#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char decipher(char c, int key){
	if(c == '\0'){
	return c;
	}
	
	return ((c - key)) % 256; 
}

void reverse2(char *str){
	if(*str){
		char temp;
		int length = strlen(str);
		int i;
		int j = length - 2;
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
		reverse2(decrypted);
		int i;
		for(i=0; i<strlen(decrypted)-1; i++){
			c = decipher(decrypted[i], key);
			decrypted[i] = c;
			if(c == '\0'){
				break;
			}
		}
		return decrypted;
	}
}
