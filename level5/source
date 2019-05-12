#include <stdio.h>
#include <stdlib.h>

void o()
{
	system("/bin/sh");
	exit(1);
}

void n()
{
	char format[0x200];

	fgets(format, 0x200, stdin);
	printf(format);
	exit(1);
}

int main(int argc, char **argv, char **envp)
{
	n();
	return 0;
}
