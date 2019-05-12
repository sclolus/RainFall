#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void run(void)
{
	size_t	size;
	size_t	nitems;
	FILE	*stream;

	stream = stdout;
	nitems = 0x13;
	size = 1;
	fwrite("Good... Wait what?", size, nitems, stream);
	system("/bin/sh");
	return;
}

int main (int argc, char **argv)
{
	char s[0x40];

	gets(s);
	return 0;
}
