#include "header.h"


int main(int argc, char *argv[]){
  clearlog(); //start by clearing the log file

  //this first statement will return the usage if there are not enough arguments
  if(argc <= 1){
    fprintf(stderr, "Usage: %s [-h] [-t time] [logfile]\n", argv[0]);
    return 1;
  }

  printf("The argument array contains:\n");
  for(int i = 1; i < argc; i++){
    printf("%d: %s\n", i, argv[i]);
  }
  return 0;
}
