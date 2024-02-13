#include <stdio.h>
#include <stdlib.h>

const int initialSize = 10;

char* unlimitedInput()
{
	int size = initialSize;
	int count = 0;
	char* buffor = (char*) malloc(sizeof(char) * size);
	char mark;
	while ((mark = getc(stdin)) != '\n')
	{
		buffor[count] = mark;
		count++;
		if (count == size)
		{
			size *= 2;
			buffor = (char*) realloc(buffor, sizeof(char) * size);
		}
	}
	buffor[count] = '\0';
	return buffor;
}

int main(void)
{
	char* answer = unlimitedInput();
	printf("%s\n", answer);

	return 0;
}