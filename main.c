#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "command.h"


#define BUFFER 128
#define ARGS 10
#define PATH_SIZE 30




	

Command *addCmd(char *input){
	int count;
	char *ptr;
	input[strcspn(input,"\n")] ='\0';
	Command *cmd = (Command*) malloc(sizeof(Command));
	cmd->argA = (char**) malloc(sizeof(char*) * ARGS);
	for(count = 0, ptr = strtok(input, " "); ptr!= NULL; count++, ptr = strtok(NULL, " ")){
		cmd->argA[count] = (char*) malloc(strlen(ptr) + 1);
		strcpy(cmd->argA[count], ptr);
	}
	cmd->argL = count + 1;
	cmd->name = cmd->argA[0];
}


void main() {
	Command *cmd;
	char **path = (char **) malloc(sizeof(char *) * PATH_SIZE);
	int pathL = 0;

	while(1){
		printf("~$ ");
		char *input;
		input = (char*) malloc(sizeof(char *)*BUFFER);
		fgets(input,99, stdin);
		cmd = addCmd(input);
		
		if(strcmp(cmd->name,"cd")==0){
			int ret = chdir(cmd->argA[1]);
			if(ret != 0){
				perror("ERROR:");
			}
		}
		else if(strcmp(cmd->name,"quit")==0){
			break;
		}
		else if(strcmp(cmd->name,"path")==0){
			char *check = cmd->argA[1];
			
			
			if(strcmp(cmd->argA[1],"+")==0){
				path[pathL] = (char *) malloc(sizeof(char *));
				path[pathL] = cmd->argA[2];
				printf("path: %d\n", pathL);
				printf("cmd: %s\n",cmd->argA[2]);
				printf("path: %s\n\n",path[pathL]);
				pathL++;
			}
			else if(strcmp(cmd->argA[1],"-")==0){
				printf("delete path\n");
			}
			else if(cmd->argL = 1){
				//printf("pathL: %d", pathL);
				for(int i = 0; i < pathL; i++){
					printf("paths: %s\n", path[i]);
				}
			}
			
		}	
	}	
}
