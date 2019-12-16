#include <stdio.h>
#include <stdlib.h>
#include "txfind.h"
#include <string.h>

int main()
{
	 
	 char first_line[LINE]; //to get the first line, the search querry and the function to perform
	fgets(first_line, LINE , stdin); // reads the first line
	printf("The First line is:  %s",first_line);
		int lookup_val=0; //a value that stores i from the loop
	  char word[LINE]; //contains the search word at MAX_LENGTH of 250
	  char func; //contains the operation to be performed a or b and a single character
	for(int i=0;i<LINE;i++) //somple loop
	{
		if(first_line[i]==' ') //this loop stops basically when where is a space, since space seperates the search word and the function
		{
			lookup_val=i; // storing i for later use
			i=LINE; //generic way to make the loop stop and not waste more resources
		}
	}
	strncpy(word,first_line,lookup_val); //make word string from first_line[0] to first_line[lookup_val]
	func=first_line[lookup_val+1]; // assign function for a or b
	printf("The lookup string is: %s \n",word);
	printf("The action is: %s \n",&func);
	
	
	if(func-97==0)
	{
		print_lines(word);
	}

	if(func-98==0)
	{
		print_similar_words(word);

	}
}