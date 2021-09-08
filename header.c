#include "header.h"

typedef struct list_struct{
  data_t item;
  struct list_struct *next;
} log_t;

//static log_t *headptr = NULL;
//static log_t *tailptr = NULL;

int addmsg(const char type, const char *msg){
  return 0;
}

void clearlog(void){
  fclose(fopen("log.h", "a+"));
}

char *getlog(void){
  return NULL;
}

int savelog(char *filename){
  return 0;
}
