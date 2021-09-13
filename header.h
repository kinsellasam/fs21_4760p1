#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>
//#include <vector>

//constan declarations
extern const char TYPE_ARRAY[4];
extern const int LOW_TIME;
extern const int HIGH_TIME;

#ifndef HEADER_H
#define HEADER_H

typedef struct data_struct{
  time_t time; //time
  char type; //message type (I/W/E/F)
  char *string; //message string
} data_t;

int addmsg (const char type, const char *msg);
void clearlog(void);
char *getlog(void);
int savelog(char *filename);

#endif
