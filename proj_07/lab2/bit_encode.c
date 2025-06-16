/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE
STRICTLY ADHERED TO THE TENURES OF THE OHIO STATE
UNIVERSITY'S ACADEMIC INTEGRITY POLICY CONCERNING THIS
ASSIGNMENT.
*/

/*
Name: Danny Kan {kan.74@osu.edu}
Date of Submission: February 1, 2024
*/

#include <stdio.h>
#include <stdlib.h>

/*
Macros. ->
*/
#define MAX_LEN 200 /* The maximum character length. */
#define ONE 1
#define FOUR 4
#define EIGHT 8

/*
Global variables. ->
*/
unsigned char cleartext[MAX_LEN + 1] = {0};
unsigned char ciphertext[MAX_LEN + 1] = {0};

/*
Function prototypes. ->
*/
unsigned char create_key();
unsigned char rotate_left(unsigned char x);
unsigned char rotate_right(unsigned char x);
void print_hex_rep(unsigned char arr[]);
void get_cleartext();
void get_ciphertext(unsigned char key);

/*
The function prompts the user to enter a 4-bit key. ->
It generates an 8-bit key by duplicating the 4-bit key. ->
Example: | 1010 | -> | 1010 | 1010 |.
*/
unsigned char create_key() {
#ifdef PROMPT
    printf("enter 4-bit key: ");
#endif
    unsigned char key = 0x0; /* | 0000 | 0000 | */
    int ch = 0;
    for(int i = 0; i < FOUR; i++) {
        ch = getchar();
        key = key << ONE;
        if (ch == '1') {
            key = key | ONE;
        } // ...
    } // ...
    return (key << FOUR) | key;
}

/*
Provided an unsigned char x, the function rotates 2 bits to the left. ->
The 2 most significant bits become the 2 least significant bits.
*/
unsigned char rotate_left(unsigned char x) {
    unsigned char y = 0xc0; /* | 1100 | 0000 | */
    return((x << 2) | (x & y) >> 6);
}

/*
Provided an unsigned char x, the function rotates 2 bits to the right. ->
The 2 least significant bits become the 2 most significant bits.
*/
unsigned char rotate_right(unsigned char x) {
    unsigned char y = 0x3; /* | 0000 | 0011 | */
    return((x >> 2) | (x & y) << 6);
}

/*
The function prints the hexadecimal representation of an unsigned char array. ->
It formats it with 10 elements per row for readability.
*/
void print_hex_rep(unsigned char arr[]) {
    int i = 0;
    while(arr[i] != '\n') {
#ifdef PROMPT
        if(i % 10 == 0) {
            printf("\n");
        }
#endif
        printf("%02X ", arr[i]);
        i++;
    }
    printf("\n");
}

/*
The function obtains cleartext as input from the user and outputs it to the
console for verification.
*/
void get_cleartext() {
    /*
    According to the requirements,
    each character will be a lower-case
    alphabetic ASCII character.
    */
#ifdef PROMPT
    printf("enter cleartext: ");
#endif
    int ch, i = 0;
    do {
        ch = getchar();
        cleartext[i] = ch;
        i++;
    } while (ch != '\n');
#ifdef PROMPT
    printf("%s", cleartext);
#endif
}

/*
The function obtains ciphertext by performing the bitwise XOR operation
on each character of cleartext using the 8-bit key pattern and then
rotating 1st, 3rd, 5th, etc... characters 2 bits to the left, and 2nd, 4th, 6th,
etc... characters 2 bits to the right.
*/
void get_ciphertext(unsigned char key) {
    int j = 0;
    while(j < MAX_LEN && cleartext[j] != '\n') {
        if(j % 2 == 0) {
            ciphertext[j] = rotate_left(cleartext[j] ^ key);
        } else {
            ciphertext[j] = rotate_right(cleartext[j] ^ key);
        }
        j++;
    }
    ciphertext[j] = '\n';
}

/*
Name: Danny Kan {kan.74@osu.edu}
Date of Submission: February 1, 2024

This program implements the elementary-level bitstream cipher by
encrypting cleartext to generate ciphertext. It prompts the user to enter a
4-bit key, then duplicates it to create an 8-bit key pattern (e.g., | 1101 | to
generate | 1101 | 1101 |) by processing each input immediately and using
the bitwise OR operation in combination with bit shifting. The algorithm
then performs the bitwise XOR operation on each character of cleartext
using the 8-bit key pattern: 1st, 3rd, 5th, etc... characters are then rotated
2 bits to the left, and 2nd, 4th, 6th, etc... characters are then rotated 2
bits to the right using functions rotate_left and rotate_right.
*/
int main() {
    get_cleartext();
#ifdef PROMPT
    printf("hex encoding: ");
    print_hex_rep(cleartext);
#endif
    unsigned char user_key = create_key();
#ifdef PROMPT
    printf("hex ciphertext: ");
#endif
    get_ciphertext(user_key);
    print_hex_rep(ciphertext);
    return(EXIT_SUCCESS);
}
