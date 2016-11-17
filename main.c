#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER 128
#define MAX_ARGS 32



void main() {
  
  int status;
 
  while(1){
    printf("~$ ");
    char input[100];
    fgets(input, 99, stdin);
    char *p = strtok(input,"\n ");
    char argInput[10][100];
    int i = 0;

    /*

      char *input;
      char **cmd_argv;
      int cmd_argc;

      size_t buffer = BUFFER;
      cmd_argv = (char **) malloc(sizeof(char *) * MAX_ARGS);

      // save input into "input"

      int count;
      char *ptr;
      for (count = 0, ptr = strtok(input, " "); ptr != NULL; c++, p = strtok(NULL, " ")) {
          cmd_argv[count] = (char *) malloc(strlen(ptr) + 1);
	  strcpy(cmd_argv[count], ptr);
      }
      cmd_argc = count;

      // Other code...

      if (cmd_argv) {
          for (int i = 0; i < cmd_argc; i++) {
	      free(cmd_argv[i])
          }
          free(cmd_argv)
      }
    */
    
    while(p != NULL){
      printf("Input: %s\n",p);
     
      input[i++] = p;

      p = strtok(NULL, " ");
    }
	printf("arg0: %s\n",argInput[0]);
 
    if(strcmp(argInput[0],"cd") == 0){
      int ret = chdir(strtok(NULL, "\n "));
	if(ret != 0){
	  perror("Error:");
	}
      }
    else if(strcmp(argInput[0],"quit") == 0){
      break;
    }
    else if(strcmp(argInput[0],"path") == 0) {
      char *mnt = strtok(NULL, "\n ");
      if(argInput[1] == NULL) {
	printf("Print path names\n");
      }
      else if(strcmp(argInput[1],"+") == 0){
	printf("add path\n");
      }
      else if(strcmp(argInput[1],"-") == 0){
	printf("remove path\n");
      }
      else{
	printf("failure");
      }
    }
            
	
    
    
  }
    
}
