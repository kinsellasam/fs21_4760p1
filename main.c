#include "header.h"

const char TYPE_ARRAY[4] = {'I','W','E','F'};
const int LOW_TIME = 0;
const int HIGH_TIME = 30;

int main(int argc, char *argv[]){
  clearlog(); //start by clearing the log file

  int timeVal = 0;
  int opts;
  int hFlag = 0;
  int tFlag = 0;

  char *filenameArr;
  FILE *fileptr;
  int fileExists = 0;
  char msgType;



  //check if any arguments are passed
  if(argc == 1){
    printf("No arguments were given. Using default variables.\n");
  }

  //getopt if there are arguments
  while((opts = getopt(argc, argv, "ht:")) != -1){
    switch (opts){
      case 'h':
        hFlag++;
        fprintf(stderr, "Usage: %s [-h] [-t time] [logfile]\n", argv[0]);
        printf("-h: The help command. This will print the usage prompt.\n");
        printf("-t: This command can accept a number seconds as a following argument.\n");
        printf("\tIf another argument is not given, a default value will be used..\n");
        printf("logfile: The user can specify the logfile.\n");
        return -1;

      case 't':
        tFlag++;
        timeVal = atoi(optarg);
        if(timeVal < 0 || timeVal > 30){
          fprintf(stderr, "Option -%c requires an argument [1-30].\n", optopt);
          return -1;
        }
        break;

      case '?':
        if(optopt == 't'){
          fprintf(stderr, "Option -%c requires an argument [1-30].\n", optopt);
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

  //checking for an argument for the file name
  if(optind < argc){
    do{
      filenameArr = argv[optind];

      printf("Attempting to open file '%s'\n", filenameArr);

      fileptr = fopen(filenameArr, "r");

      if(fileptr == NULL){
        printf("File '%s' not found. Exiting.\n", filenameArr);
        return -1;
      }
      else{
        printf("Opened file %s\n", filenameArr);
        fileExists = 1;
      }

    }while(++optind < argc);
  }
  //end of command line argument handling.

  //showing the user the passed arguments
  printf("The argument array contains:\n");
  for(int i = 1; i < argc; i++){
    printf("%d: %s\n", i, argv[i]);
  }

  //start logging messages
  //open a predetermined file if one has not been passed.
  if(fileExists == 0){
    printf("No file was passed. Opening file 'messages.txt'\n");
    fileptr = fopen("messages.txt", "r");
  }


  //setup for the actual program
  char line[1024];
  int numLines = 0;
  int randLine;

  //count the lines in the file
  while (!feof(fileptr)){
    fgets(line, 1024, fileptr);
    numLines++;
  }

  //get a random type and message
  do{
    srand(time(0));

    msgType = TYPE_ARRAY[rand() % 4];
    randLine = rand() % numLines;

    fseek(fileptr, 0, SEEK_SET);
    for(int i = 0; !feof(fileptr) && i < randLine; i++){
      fgets(line, 1024, fileptr);
    }

    addmsg(msgType, line);
    sleep(1);

  }while(msgType != 'F');

  //close file and end program
  fclose(fileptr);
  return 0;
}
