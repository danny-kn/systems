/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
   TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
   THIS ASSIGNMENT.
*/
#include <stdio.h>				/* this tells the preprocessor to copy IO library prototypes
						   and other information from the file /usr/include/stdio.h	*/
#include "local_file.h"				/* this is an include file located in the current directory	*/
void print_chars(unsigned int maxEntries){
int getchar_return_value;

	printf("enter the %u characters: ", maxEntries);

	for(int i = 0; i < maxEntries; i++){
		getchar_return_value = getchar();
		if(i==0) printf("The keyboard values are: \n");
		if (getchar_return_value != EOF){				/* we got a valid value			*/
			putchar(getchar_return_value);				/* print it back out			*/
			putchar('\n');
	
		}
		else{
			printf("fewer than %u characters entered, number of characters set to %d\n", maxEntries, i);
			maxEntries = i;
			break;
		}

	}
	return;
}
