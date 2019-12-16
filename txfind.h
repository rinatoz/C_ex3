#include <stdio.h>
#ifndef _TXFIND_H_
#define _TXFIND_H_
#define LINE 256
#define WORD 30

char substr(const char *src, int m, int n);
int Getline(char s[]);
int Length(char ch[]);
int getword(char w[]);
int substring(char* str1, char* str2);
int similar(char* s, char* t, int n);
void print_lines(char* str);
void print_similar_words(char* str);

#endif 