#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "cmd.h"


#define BUFFER 128
#define MAX_ARGS 10


Command *addCmd(char *input){
	

	int count;
	char *ptr;
	Command *cmd = (Command*) malloc(sizeof(Command));
	cmd->argA = (char**) malloc(sizeof(char*) * MAX_ARGS);
	for(count = 0, ptr = strtok(ptr, " "); ptr!= NULL; count++, ptr = strtok(NULL, " ")){
		printf("ptr value: %s",ptr);
		cmd->argA[count] = (char*) malloc(strlen(ptr) + 1);
		strcpy(cmd->argA[count], ptr);
		
	}
	cmd->argL = count;
	cmd->name = cmd->argA[0];
	//printf("name: %s",cmd->argA[0]);
	
	
	
}


void main() {
	Command *cmd;
	//while(1){
		printf("~$ ");
		char *input;
		input = (char*) malloc(sizeof(char)*BUFFER);
		fgets(input,99, stdin);
		
		cmd = addCmd(input);
	
	//}
}
		
		
		
