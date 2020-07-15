#ifndef ERRORS_H
#define ERRORS_H

#define OK 0
#define ERR_READ -1
#define ERR_INPUT -2
#define ERR_RANGE -3
#define ERR_ALLOC -4
#define NO_DOTS -5

void error_message(int err);

#endif
