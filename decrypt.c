#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char decipher(char c, int key){
	if(c == '\0'){
	return c;
	}
	
	return ((c - key)) % 256; 
}

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

char* decrypt(char *str, int key){
	if(*str){
		char* decrypted = (char*) malloc(1001);
		char c;
		strncpy(decrypted, str, strlen(str));
		reverse(decrypted);
		int i;
		for(i=0; i<strlen(decrypted); i++){
			c = decipher(decrypted[i], key);
			decrypted[i] = c;
		}
		return decrypted;
	}
}

int main(int argc, char *argv[]){
	char test[] = "ji^fjxpI";
	printf("%s", decrypt(test, 1));
}
