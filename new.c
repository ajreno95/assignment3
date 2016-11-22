#define _GNU_SOURCE
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
	cmd->argL = count;
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
			//char *print = (char *) malloc(sizeof(char *) * BUFFER);
			//strcpy(print,cmd->name);
			//char slash[5] = '\';
			//strcpy(print,slash);

			char *test;
			asprintf(&test, "%s\%s\\", cmd->name,cmd->argA[0]);

			//print[strlen(cmd->name)] = '\';
			printf("string: %s\n", test);
			break;
		}
		else if(strcmp(cmd->name,"path")==0){
			if(cmd->argL > 1){
				char *check = cmd->argA[1];
				if(strcmp(cmd->argA[1],"+")==0){
					path[pathL] = (char *) malloc(sizeof(char *));
					path[pathL] = cmd->argA[2];
					pathL++;
				}
				else if(strcmp(cmd->argA[1],"-")==0){
					char **new = (char **) malloc(sizeof(char *) * PATH_SIZE);
					int newL = 0;
					for(int i = 0; i < pathL; i++){
						if(strcmp(cmd->argA[2],path[i])!=0){
							new[newL] = (char *) malloc(sizeof(char *));
							new[newL] = path[i];
							printf("new[%d]: %s\n",i,path[i]);
							newL++;
						}
					}
					free(path);
					path = new;
					pathL = newL;
				}
				else if(cmd->argL = 1){
					for(int i = 0; i < pathL; i++){
						printf("paths: %s\n", path[i]);
					}
				}
			}
			else{
				if(pathL > 0){
					printf("#############\tPATHS\t#############\n");
					for(int i = 0; i < pathL; i++){
						printf("%s\n",path[i]);
					}
				}
				else if(pathL == 0){
					printf("No current paths stored\n");
				}
			}
		}
		/*else{
			for(int i = 0; i < pathL; i++){
				pid = fork();
				if(pid == 0){
					char *newPath = (char *) malloc(sizeof(char*));
					strcpy(newPath,path[i]);
					newPath[strlen(path[i]) + 1] = '\';
					
					execve("			
		}	*/			
	}	
}
		
		
		
