#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// same method as in 1a
char decipher(char c, int key){
	if(c == '\0'){
	return c;
	}
	return ((c - key)) % 256; 
}

// same method as in 1a
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

// same method as in 1a
char* decrypt(char *str, int key){
	if(*str){
		char* decrypted = (char*) malloc(1001);
		char c;
		reverse(str);
		int i;
		for(i=0; i<strlen(str); i++){
			c = decipher(str[i], key);
			decrypted[i] = c;
		}
		return decrypted;
	}
}




int main(int argc, char *argv[]){
	if(argc != 2){
		printf("ERROR, invalid number of arguments");
		return 1;
	}
	FILE *file;
	char *filename = argv[1];
	file = fopen(filename, "r");
	char *s = (char*) malloc(1001);
	char convertCh[2];
	convertCh[1] = '\0';
	int c;
	// store file contents into string s
	while((c = fgetc(file)) != EOF){
		convertCh[0] = (char) c;
		strncat(s, convertCh, 1);
	}
	int i;
	char *decrypted = (char*) malloc(1001);
	// test every possible key to see if question conditions are met after decrypting
	for(i=0; i<256; i++){
		decrypted = decrypt(s, i);
		int j;
		// two flags for a and z
		int aFlag = 0;
		int zFlag = 0;
		for(j=0; j<strlen(decrypted); j++){
			if(decrypted[j] > 122 || (decrypted[j]< 65 && decrypted[j]!= 32 && decrypted[j] != 0) || (decrypted[j] > 90 && decrypted[j] < 97)){
				break;
			}
			else{
				if(decrypted[j] == 97 || decrypted[j] == 65){
					aFlag = 1;
				}
				if(decrypted[j] == 122 || decrypted[j] == 90){
					zFlag = 1;
				}
			}
		}
		if(aFlag == 1 && zFlag == 1){
			printf("%d\n", i);
			printf("%s\n", decrypted);
			fclose(file);
			return 0;
		}
	}
	fclose(file);
	return 0;
}
