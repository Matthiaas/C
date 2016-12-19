#pragma once
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	char* cString;
	int lenght;
} string;


string* String(char* s) {
	string* ret =(string*) malloc(sizeof(string));
	
	char* sc = s;
	int len = 1;
	while (*(sc++)) {
		len++;
	}
	ret->lenght = len-1;
	ret->cString = (char*) malloc(len);
	sc = ret->cString;
	while (*(s)) {
		*sc = *s;
		sc++;
		s++;
	}
	*sc = 0;
	return ret;

}

string* stringConcat(string* s1, string* s2) {
	string* ret = (string*)malloc(sizeof(string));
	ret->lenght = s1->lenght + s2->lenght;
	ret->cString = (char*)malloc(s1->lenght + s2->lenght +1);
	memcpy(ret->cString, s1->cString, s1->lenght);
	memcpy(ret->cString + s1->lenght , s2->cString, s2->lenght);
	*(ret->cString + ret->lenght) = 0;
	return ret;
}

char getCharAt(string* s, int i) {
	if (i < 0 || i >= s->lenght) return 0;
	return *(s->cString + i);
}

string* reverseString(string* s) {
	string* ret = (string*)malloc(sizeof(string));
	ret->lenght = s->lenght;
	ret->cString = (char*)malloc(s->lenght + 1);

	char* result = ret->cString;
	int len = s->lenght;
	while (len--)
	{
		*result = *(s->cString + len);

		result++;
	}

	return ret;
}

string* copyString(string* s) {
	string* ret = (string*)malloc(sizeof(string));
	ret->lenght = s->lenght ;
	ret->cString = (char*)malloc(s->lenght  + 1);
	memcpy(ret->cString, s->cString, s->lenght+1);
}




