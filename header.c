#include "header.h"

typedef struct list_struct{
  data_t item;
  struct list_struct *next;
} log_t;

//static log_t *headptr = NULL;
//static log_t *tailptr = NULL;

int addmsg(const char type, const char *msg){
  //createing the basic time struct
  time_t tm;
  time(&tm);
  struct tm *tptr = localtime(&tm);
  printf("%.2d:%.2d:%.2d\n", tptr->tm_hour, tptr->tm_min, tptr->tm_sec);

  


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
