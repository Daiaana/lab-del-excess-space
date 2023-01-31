#include <stdio.h>
#include <stdlib.h>
#define	MAXLENGTH 300


int strlen(const char* str)
{
	int size;
	for (size = 0; *(str + size); size++);
	return size;
}

char* strdls(char* dest, char* str, int number)
{
	int i = 0, size = strlen(str);
	while (i != number) {
		*(dest + i) = *(str + i);
		i++;
	}
	do {
		*(dest + i) = *(str + i + 1);
		i++;
	} while (i != size + 1);
	return dest;
}

int strchr(const char* str, const char ch)
{
	const char* ptr;
	for (ptr = str; *ptr && *ptr != ch; ptr++);
	if (*ptr)
		return 1;
	else
		return 0;
}

char* strcpy(char* dest, const char* src)
{
	for (int i = 0; *(dest + i) = *(src + i); i++);
	return dest;
}

int space(char* str)
{
	char* dest = (char*)malloc(sizeof(char) * MAXLENGTH);
	char* destX = (char*)malloc(sizeof(char) * MAXLENGTH);
	if (dest != NULL && destX != NULL) {
		strcpy(dest, str);
		int length = strlen(dest), deltaLength = 0;
		const char* signAfter = " .,!? )»";
		const char* signBefore = " «(";
		for (int i = 0; i < length; i++) {
			if (*(dest + i) == ' ') {
				if (i == 0 || i == length - 2 - deltaLength || strchr(signBefore, *(dest + i - 1)) || strchr(signAfter, *(dest + i + 1))) {
					strdls(destX, dest, i);
					strcpy(dest, destX);
					i = i - 1;
					deltaLength += 1;
				}
			}
		}
		strcpy(str, dest);
	}
	else {
		puts("memory allocation error");
		free(dest);
		free(destX);
		return 0;
	}
	free(dest);
	free(destX);
	return 1;
}