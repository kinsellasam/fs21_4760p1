#include "header.h"

typedef struct list_struct{
  data_t item;
  struct list_struct *next;
} log_t;

static log_t *headptr = NULL;
static log_t *tailptr = NULL;

int addmsg(data_t data){
  return 0;
}

void clearlog(void){
  fclose(fopen("log.h", ))
  return 0;
}

void *getlog(void){
  return 0;
}

int savelog(char *filename){
  return 0;
}
