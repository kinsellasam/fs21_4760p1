#include "header.h"
#include <iostream>

//this is how I will make an array of arguments from the comand line.
int makeargv(const char *s, const char *delimiters, char ***argvp);

int main(int argc, char *argv[]){
  clearlog(); //start by clearing the log file

  char delim[] = "\t"; //array delimiter
  char **myargv; //this is going to be an array of our arguments
  int numtokens; //keep track of the number of number of tokens

  //this first statement will return the usage if there are not enough arguments
  if(arcg != 2){
    fprintf(stderr, "Usage: %s string\n", argv[0]);
    return 1;
  }

  //this statement will give an error if an array cannot be made
  if((numtokens = makeargv(argv[1], delim, &myargv)) == -1){
    fprintf(stderr, "Failed to construct an argument array for %s\n", argv[1]);
  }

  printf("The argument array contains:\n");
  for(int i = 0; i < numtokens; i++){
    printf("%d:%s\n", i, myargv[i]);
  }
  return 0;
}
