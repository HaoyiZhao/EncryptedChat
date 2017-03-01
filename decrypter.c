#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// method takes as input a character c and an int key and returns the deciphered character value
char decipher(char c, int key){
	if(c == '\0'){
	return c;
	}
	
	return ((c - key)) % 256; 
}

// method reverses a string by swapping indexes from front of array to back of array
void reverse(char *str){
	if(*str){
		char temp;
		int length = strlen(str);
		int i;
		int j = length - 1;
		for(i=0; i<length/2; i++){
			temp = str[i];
			str[i] = str[j];
			str[j] = temp;
			j--;
		}
	}
}

// method takes as input a character pointer(string) and an int key and decrypts the character using the key
char* decrypt(char *str, int key){
	if(*str){
		char* decrypted = (char*) malloc(1001);
		char c;
		reverse(str);
		int i;
		for(i=0; i<strlen(str); i++){
			c = decipher(str[i], key);
			printf("%c", c);
			decrypted[i] = c;
		}
		printf("\n");
		return decrypted;
	}
}

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("ERROR, invalid number of arguments");
		return 1;
	}
	// convert key argument to integer
	int key = atoi(argv[1]);
	char *filename = argv[2];
	char *s = (char*) malloc(1001);
	FILE  *file;
	file = fopen(filename, "r");
	int c;
	char convertCh[2];
	convertCh[1] = '\0';
	while((c = fgetc(file)) != EOF){
		convertCh[0] = (char) c;
		strncat(s,convertCh,1);
	}
	fclose(file);
	decrypt(s, key);
	return 0;
}



