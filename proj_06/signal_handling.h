#ifndef SIGNAL_HANDLING_H
#define SIGNAL_HANDLING_H

#include <signal.h>

extern volatile sig_atomic_t sigint_flag;
extern volatile sig_atomic_t sigquit_flag;
extern volatile sig_atomic_t ct;

void setup_signal_handlers(void);

#endif
