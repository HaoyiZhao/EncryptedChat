#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* readIntoString(char *filename){
	FILE *file;
	file = fopen(filename, "r");
	if(file){
		char *s = (char*) malloc(1000);
		memset(s, 0, 1000);
		char convertCh[2];
		convertCh[1] = '\0';
		int c;
		while((c = fgetc(file)) != EOF){
			convertCh[0] = (char) c;
			strncat(s, convertCh, 1);
		}
		fclose(file);
		return s;
	}
	else{
		return "nofile";
	}
}

void sendMessage(char *filename, char *message){
	FILE *file;
	file = fopen(filename, "w");
	fprintf(file, "%s", message);
	fclose(file);
}











	



