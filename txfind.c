#include <stdio.h>
#include <stdlib.h>
#include "txfind.h"

int Getline(char s[])
{
	int c, i;
	for (i = 0; i < LINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	 s[i] = '\0';
	return i;
}

int Length(char ch[])
{
	int length = 0;

	while (ch[length]||ch[length]=='\n'||ch[length]=='\t'||ch[length]==' ')
	{
		length++;
	}
	return length;
}

int getword(char w[])
{
	int c, i;
	for (i = 0; i < WORD - 1 && (c = getchar()) != EOF && c != '\n'&&c!= ' '&&c!= '\t'; ++i)
		w[i] = c;
	if (c == '\n'||c==' '||c=='\t')
	{
		w[i] = c;
		++i;
	}
	w[i] = '\0';
    
	return i;
}

int substring(char* str1, char* str2)
{
	int len = Length(str1);
	int len1 = Length(str2);
	int i = 0;
	int j = 0;
	int counter = 0;

	while (i < len)
	{
		while (str1[i] == str2[j]&&j<len1)
		{
			counter++;

			j++;
			i++;
	    }
		if (counter > 0)
		{
			if (counter == len1)
			{
				return 1;
			}
		}
		j = 0;
		i++;
		counter = 0;
	}

	return 0;

}

int similar(char* s, char* t, int n)
{
	int lenS = Length(s);
	int lenT = Length(t);
	int n1 = 0;;
	int counter = 0;
	int i = 0, j = 0;
	while ( j < lenS)
	{
		if (i < lenT)
		{
			if (t[i] == s[j])
			{
				counter++;
				i++;
			}
			else
			{
				n1 = n1 + 1;
			}
		}
		else
		{
			n1 = n1 + 1;
		}

		j++;
	}

	if (counter == lenT&&n1==n)
	{
		return 1;
	}

		return 0;

}

void print_lines(char* str)
{
	char text[LINE];

	while (fgets(text,LINE, stdin))
	{
		int print = substring(text, str);
		if (print == 1)
		{
			printf("%s", text);
		}
	}

}

void print_similar_words(char* str)
{
	char text[WORD];

	while (fscanf(stdin," %s", text)==1)
	{
		int print = similar(text, str, 1);
		if (print == 1)
		{
			printf("%s\n", text);
		}
	}
}

