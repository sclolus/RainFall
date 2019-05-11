#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t	m;

void v()
{
	char	format[0x200];
	size_t	size;		//4
	FILE	*stream_1;	//8
	FILE	*stream_2;	//c

	stream_1 = stdin;
	size = 0x200;
    fgets(format, size, stream_1);
	printf(format);
	if (m - 0x40)
		return;
	stream_2 = stdout;
	stream_1 = (FILE *)0xc;
	size = 1;
	fwrite("Wait what?!", size, (size_t)stream_1, stream_2);
	system("/bin/sh");
	return;
}

int main(int argc, char **argv, char **envp)
{
	v();
    return 0;
}
