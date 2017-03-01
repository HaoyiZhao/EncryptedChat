#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// read file contents and store into a string, return string if file exists and valid message is inside, otherwise return nomessage
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
		if(s[0] == '['){
			return s;
		}
		else{
			return "nomessage";
		}
	}
	else{
		return "nomessage";
	}
}

// write message to file, taking input username message and filename
void sendMessage(char *filename, char *message, char *username){
	FILE *file;
	file = fopen(filename, "w");
	fprintf(file, "[%s] %s", username, message);
	fclose(file);
}
	
int main(int argc, char *argv[]){
	if(argc != 4){
		printf("ERROR, Invalid number of arguments\n");
		return 1;
	}
	// create variables for current and previous input
	char *previousIn = (char*) malloc(1000);
	char *currentIn = (char*) malloc(1000);
	// read file input into currentIn
	currentIn = readIntoString(argv[1]);
	// create output message
	char *output = (char*) malloc(1000);
	// check if file had valid message/exists, print Nothing received yet if not and print message if exists
	if((strcmp(currentIn, "nomessage")) == 0){
		printf("Nothing received yet.\n");
	}
	else{
		printf("Received:%s", currentIn);
	}
	// set previous input to current input
	previousIn = currentIn;
	
	while(1){
		// prompt for message, take input from stdin and store into output, then write to file
		printf("Send: ");
		fgets(output, 1000, stdin);
		sendMessage(argv[2], output, argv[3]);
		while(1){
			sleep(1);
			currentIn = readIntoString(argv[1]);
			// check to see if a new valid message has been entered, break loop and print if so.
			if((strcmp(currentIn, "nomessage") != 0) && (strcmp(currentIn, previousIn) != 0)){
				break;
			}
		}
		printf("Received:%s", currentIn);
		previousIn = currentIn;
	}
}










	



