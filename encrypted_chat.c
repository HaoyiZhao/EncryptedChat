#include "encrypt.h"
#include "q2_text_chat.h"
#include "decrypt.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>



int main(int argc, char *argv[]){
	if(argc != 5){
		printf("ERROR, invalid number of input arguments\n");
		return 1;
	}
	// convert argument to integer key
	int key = atoi(argv[4]);
	char username[100];
	// initialize username variable: username surrounded by square brackets
	username[0] = '[';
	strncat(username, argv[3], strlen(argv[3]));
	strncat(username, "] ", 2);
	// create and allocate memory for previous input, current input, output, temporary output, and decrypted message
	char *previousIn = (char*) malloc(1000);
	// read file and store string into currentIn
	char *currentIn = readIntoString(argv[1]);
	char *output = (char*) malloc(1000);
	char *tempOutput = (char*) malloc(1000);
	// decrypt file contents using key and store into decryptedM
	char *decryptedM = decrypt(currentIn, key);
	// if file is empty or an invalid message is in the file, print nothing received yet
	if((strcmp(currentIn, "nofile") == 0) || (decryptedM[0] != '[')){
		printf("Nothing received yet.\n");
	}
	// otherwise print decrypted message and replace previousIn with the decrypted message
	else{
		printf("Received:%s", decryptedM);
		previousIn = decryptedM;
		// clear currentIn
		memset(currentIn, 0, 1000);
	}
	
	while(1){
		// clear output 
		memset(output, 0, 1000);
		printf("Send: ");
		// append message to username using strncpy and strncat after taking output from stdin through the use of variable tempOutput
		strncpy(output, username, strlen(username));
		fgets(tempOutput, 1000, stdin);
		strncat(output, tempOutput, strlen(tempOutput));
		output = encrypt(output, key);
		// write message to file
		sendMessage(argv[2], output);
		while(1){
			// keep checking input file until valid new message exists, then print and replace previousIn with decryptedMessage
			sleep(1);
			currentIn = readIntoString(argv[1]);
			decryptedM = decrypt(currentIn, key);
			int a = strcmp(decryptedM, previousIn);
			if((strcmp(currentIn, "nofile") != 0) && (decryptedM[0] == '[')){
				if (a != 0 ){
					break;
				}
			}
		}
		printf("Received:%s", decryptedM);
		previousIn = decryptedM;
		//clear output
		memset(output, 0, 1000);
	}
}
