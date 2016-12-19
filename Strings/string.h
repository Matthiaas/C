#pragma once
#include <stdio.h>
#include <stdlib.h>

char* readLine() {

	int len = 2;
	char *ret = (char*)malloc(len * sizeof(char));
	int pos = 0;

	char c;
	while ((c = fgetc(stdin)) != 10) {

		if (pos >= len) {
			len *= 2;
			ret = (char*) realloc(ret, len);
		}
		*(ret + pos) = c;


		pos++;
	}
	if (pos >= len) {
		len *= 2;
		ret = (char*) realloc(ret, len);
	}
	ret[pos] = '\0';


	return ret;
}

char* reverseString(char *string) {
	int len = 0;
	while (*(string++)) { len++; }
	char* ret =(char*) malloc(len);
	string--;
	int pos = 0;
	while (len--) {
		*(ret+ pos)= *(--string);
		pos++;
	}
	*(ret + pos) = '\0';
	return ret;
}

char getCharAt(char *string , int pos) {
	if (*string == 0) return 0;
	while (*(++string) & --pos) {}
	return string[0];
}

void stringCopy(char *dest, char *from) {

	while (*(dest++) = *(from++)) {}
}

int length_of_string(char *string) {
	int pos = 0;
	while (*(string++)) {
		pos++;
	}
	return pos;
}

char* stringConcat(char *front, char *end) {
	int pos = 0; 
	int len = 2;
	char *ret = (char*)malloc(len);
	char c;
	while ( c = *(front++)) {
		if (pos >= len) {
			len *= 2;
			ret = (char*)realloc(ret, len);
		}
		ret[pos] = c;
		pos++;
	}

	while (c = *(end++)) {
		if (pos >= len) {
			len *= 2;
			ret = (char*)realloc(ret, len);
		}
		ret[pos] = c;
		pos++;
	}
	if (pos >= len) {
		len += 1;
		ret = (char*)realloc(ret, len);
	}
	ret[pos] = '\0';

	return ret;

}