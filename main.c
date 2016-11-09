#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void main() {
  
  int status;
 
  //while(1){
    printf("~$ ");
    char input[100]
    char *argInput[10]
    fgets(input, 99, stdin);
    for(int i = 0; i < 10; i++) {
      argInput[i] = strtok(input, "\n ");
      
    

    int i,pid[10];
    
    if(pid > 0) {
      //parent process
      wait(&status);
     
      
    }
    else if(pid == 0) {
      i++;
      
      
    }
    else{
      printf("Fork failure");
    }
    
    //}



}
