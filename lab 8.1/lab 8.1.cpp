#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#define	MAXLENGTH 300
//программа для удаления лишних пробелов

int main()
{
	char *str = (char*)malloc(sizeof(char) * MAXLENGTH);
	if (str != NULL) {
		puts("enter string:");
		fgets(str, MAXLENGTH, stdin);
		fputs(str, stdout);
		/*int a = strlen(str);
		printf_s("%d\n", a);*/
		if (space(str))
			fputs(str, stdout);
		/*int b = strlen(str);
		printf_s("%d\n", b);*/
	} else {
		puts("memory allocation error");
	}
	free(str);
	return 0;
}
