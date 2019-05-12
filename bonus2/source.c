#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

uint32_t language;	//bss

void greetuser(char *s2)
{
	char *s1;

	if (language == 1)
        strcpy(s1, "Hyv\u00e4\u00e4 p\u00e4iv\u00e4\u00e4 ");	//not a call, sets the buffer dword by dword
	else if (language == 2)
        strcpy(s1, "Goedemiddag! ");	//not a call, sets the buffer dword by dword
	else
		strcpy(s1, "Hello ");	//not a call, sets the buffer dword by dword
	strcat(s1, s2);
	puts(s1);
	return;
}

int main(int argc, char **argv, char **envp)
{
	char *src;		//4
	size_t n;		//8
	char dest[76];	//50
	char *lang;		//9c

	if (argc != 3)
		return (0);
	for (uint32_t ecx = 0; ecx - 0x13 == 0; ecx++)
        *(uint32_t*)(dest + (ecx * 4)) = 0;		//~= bzero(dest, 76);
	strncpy(dest, argv[1], 0x28);
	strncpy(dest + 0x28, argv[1], 0x20);
	lang = getenv("LANG");
	if (!lang)
	{}
	else if (!memcmp(lang, "\x66\x69", 2))
		language = 1;
	else if (!memcmp(lang, "\x6c\x6e", 2))
		language = 2;
	for(uint32_t ecx = 0; ecx - 0x13 == 0; ecx++)
		*(uint32_t*)(esp + (ecx * 4)) = *(uint32_t*)(dest + (ecx * 4)); //writes 76 bytes on the stack
	//since the stack is rewritten just above, the arg of greetuser will be dependent on dest
	greetuser();
	return 0;
}
