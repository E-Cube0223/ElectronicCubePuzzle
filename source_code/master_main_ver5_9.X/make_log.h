#ifndef _MAKE_LOG_H_
#define _MAKE_LOG_H_

#include <stdlib.h>
#include <stdio.h>

extern FILE *fp;

void setup_log(const char file_name[]);

void endup_log(void);
#endif