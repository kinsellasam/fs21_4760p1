#include "header.h"


int main(int argc, char *argv[]){
  clearlog(); //start by clearing the log file

  int timeVal = 0;
  int opts;
  int hFlag = 0;
  int tFlag = 0;

  while((opts = getopt(argc, argv, "ht:")) != -1){
    switch (opts){
      case 'h':
        fprintf(stderr, "Usage: %s [-h] [-t time] [logfile]\n", argv[0]);
        printf("-h: The help command. This will print the usage prompt.\n");
        printf("-t: This command can accept a number seconds as a following argument.\n");
        printf("\tIf another argument is not given, a default value will be used..\n");
        printf("logfile: The user can specify the logfile.\n");
        hFlag++;
        return -1;

      case 't':
        tFlag++;
        timeVal = optopt;
        break;

      case '?':
        if(optopt == 't'){
          fprintf(stderr, "Option -%c requires an argument [0-9].\n", optopt);
        }
        else if(isprint(optopt)){
          fprintf(stderr, "Unknown option '-%c'.\n", optopt);
        }
        else{
          fprintf(stderr, "Unknown option character '\\x%x'.\n", optopt);
        }
        return -1;
      default:
        abort();
    }
  }

  printf("The argument array contains:\n");
  for(int i = 1; i < argc; i++){
    printf("%d: %s\n", i, argv[i]);
  }
  return 0;
}
