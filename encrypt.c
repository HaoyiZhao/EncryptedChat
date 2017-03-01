#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char cipher(char c, int key){
	if(c == '\0'){
	return c;
	}
	return ((c + key)) % 256; 
}

void reverse(char *str){
	if(str){
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


char* encrypt(char *str, int key){
	if(*str){
		char* encrypted = (char*) malloc(1001);
		char c;
		reverse(str);
		int i;
		for(i=0; i<strlen(str); i++){
			c = cipher(str[i], key);
			encrypted[i] = c;
		}
		return encrypted;
	}
}

int main(int argc, char *argv[0]){
	char test[] = "Hello";	
	printf("%s",encrypt(test, 1));
}


