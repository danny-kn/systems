#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LN 80
#define MAX_HIST 10

char hist[MAX_HIST][MAX_LN];
int cmd_count = 0;
char hist_fname[] = "mysh.history";

void disp_msg(void);
void save_hist(int, char *);
void disp_hist(int);
int search_cmd(char, char *);
void no_hist(char *);
void save_hist_to_fname(void);
void load_hist_from_fname(FILE *);

void disp_msg(void) {
    printf("no command found in history\n");
}

void save_hist(int idx, char *cmd) {
    int j = 0;
    while (j < MAX_LN - 1 && cmd[j] != '\0') {
        hist[idx][j] = cmd[j];
        j++;
    }
    hist[idx][j] = '\0';
    cmd_count++;
}

void disp_hist(int sig) {
    printf("\n");
    if (cmd_count == 0) {
        return;
    }
    int j = (cmd_count >= MAX_HIST) ? cmd_count - MAX_HIST : 0;
    while (j < cmd_count) {
        printf("%d %s\n", j + 1, hist[j % MAX_HIST]);
        j++;
    }
}

int search_cmd(char ch, char *cmd) {
    int i = cmd_count - 1;
    int flag = 0;
    while (i >= 0 && i >= cmd_count - MAX_HIST) {
        if (hist[i % MAX_HIST][0] == ch) {
            int j = 0;
            while (j < MAX_LN - 1 && hist[i % MAX_HIST][j] != '\0') {
                cmd[j] = hist[i % MAX_HIST][j];
                j++;
            }
            cmd[j] = '\0';
            flag = 1;
        }
        i--;
    }
    return flag;
}

void no_hist(char *cmd) {
    disp_msg();
    free(cmd);
}

void save_hist_to_fname(void) {
    FILE *hist_fname = fopen("mysh.history", "w");
    if (hist_fname == NULL) {
        return;
    }
    int j = (cmd_count >= MAX_HIST) ? cmd_count - MAX_HIST : 0;
    if (cmd_count > 0) {
        fprintf(hist_fname, "%d\n", j + 1);
    }
    while (j < cmd_count) {
        fprintf(hist_fname, "%s\n", hist[j % MAX_HIST]);
        j++;
    }
    if (cmd_count == 0) {
        fprintf(hist_fname, "\n");
    }
    fclose(hist_fname);
}

void load_hist_from_fname(FILE *ptr) {
    char line[MAX_LN];
    int hist_num = 0;
    if (fgets(line, MAX_LN, ptr) != NULL) {
        hist_num = atoi(line);
    }
    cmd_count = hist_num;
    while (fgets(line, MAX_LN, ptr) != NULL) {
        int len = 0;
        while (line[len] != '\n' && line[len] != '\0') {
            len++;
        }
        if (line[len] == '\n') {
            line[len] = '\0';
        }
        save_hist(cmd_count % MAX_HIST, line);
    }
}
int main(int argc, char *argv[]) {
    char *cmd;
    size_t restrict_size = 0;
    size_t line_size;
    int system_ret;
    int i;
    
    FILE *hist_fname = fopen("mysh.history", "r");
    if (hist_fname == NULL) {
        hist_fname = fopen("mysh.history", "a+");
        if (hist_fname == NULL) {
            exit(-1);
        }
        fclose(hist_fname);
    }
    
    hist_fname = fopen("mysh.history", "r");
    if (hist_fname != NULL) {
        load_hist_from_fname(hist_fname);
        fclose(hist_fname);
    }
    
    struct sigaction handler;
    handler.sa_handler = disp_hist;
    handler.sa_flags = SA_RESTART;
    sigaction(SIGINT, &handler, NULL);
    
    while (1) {
        printf("COMMAND->");
        fflush(0);
        cmd = NULL;
        line_size = getline(&cmd, &restrict_size, stdin);
        
        if (line_size == -1) {
            if (errno != ENOMEM) {
                free(cmd);
            }
            if (errno) {
                save_hist_to_fname();
                return -1;
            }
            save_hist_to_fname();
            return 0;
        }
        
        if (cmd[strlen(cmd) - 1] == '\n') {
            cmd[strlen(cmd) - 1] = '\0';
        }
        
        if (!strcmp("exit", cmd)) {
            save_hist(cmd_count % MAX_HIST, cmd);
            save_hist_to_fname();
            free(cmd);
            return 0;
        }
        
        if (cmd[0] == 'r' && cmd[1] == '\0') {
            if (cmd_count == 0) {
                no_hist(cmd);
                continue;
            }
            char *recent_cmd = hist[(cmd_count - 1) % MAX_HIST];
            int j = 0;
            while (j < MAX_LN - 1 && recent_cmd[j] != '\0') {
                cmd[j] = recent_cmd[j];
                j++;
            }
            cmd[j] = '\0';
        }
        
        if (cmd[0] == 'r' && cmd[1] == ' ' && strlen(cmd) == 3) {
            if (cmd_count == 0) {
                no_hist(cmd);
                continue;
            }
            if (!search_cmd(cmd[2], cmd)) {
                no_hist(cmd);
                continue;
            }
        }
        
        save_hist(cmd_count % MAX_HIST, cmd);
        system_ret = system(cmd);
        if (system_ret) {
            printf("error: failed to do system\n");
        }
        free(cmd);
    }
    return 0;
}

