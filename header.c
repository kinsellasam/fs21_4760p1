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

  //open and print to log.h and close
  FILE *logptr;
  logptr = fopen("log.h", "a+");
  fprintf(logptr, "%.2d:%.2d:%.2d\t%c\t%s\n", tptr->tm_hour, tptr->tm_min, tptr->tm_sec, type, msg);
  fclose(logptr);

  //print F to terminal
  if(type == 'F'){
    printf("%.2d:%.2d:%.2d\t%c\t%s\n", tptr->tm_hour, tptr->tm_min, tptr->tm_sec, type, msg);
  }
  return 0;
}

void clearlog(void){
  fclose(fopen("log.h", "w"));
}

char *getlog(void){
  return NULL;
}

int savelog(char *filename){
  return 0;
}
