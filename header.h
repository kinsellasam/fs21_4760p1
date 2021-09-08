#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#ifndef HEADER_H
#define HEADER_H

typedef struct data_struct{
  time_t time; //time
  char type; //message type (I/W/E/F)
  char *string; //message string
} data_t;

int addmsg (const char type, const char *msg);
void clearlog();
char *getlog();
int savelog(char *filename);

#endif
