#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint32_t	*new_uint(uint32_t val)
{
	uint32_t *new = malloc(sizeof(uint32_t));
	*new = val;
	return (new);
}

int32_t fcn_0804873a(int32_t *new, int32_t val)
{
	uint32_t edx;

	edx = *(new + 0x68);
    *(&val + 0x68) += edx;
	return (edx);
}

int32_t n_int(int32_t *new, int32_t val)
{
	*new = fcn_0804873a(new, val);
	*(new + 0x68) = val;
	return (val);
}

void setAnnotation_char(char *s1, char *s2)
{
	size_t	n;

	n = strlen(s2);
	memcpy(s1 + 4, s2, n);
	return;
}

int main(int argc, char **argv)
{
	void	*tmp;			//4
    int32_t *first_uint;	//1c
	int32_t *second_uint;	//18
	int32_t *first_uint_copy;//14
	int32_t *second_uint_copy;//10

	if (argc <= 1)
		exit(1);
	tmp = new_uint(0x6c);
	n_int((int32_t*)tmp, 5);
	first_uint = tmp;
	second_uint = (int32_t*)new_uint(0x6c);
	n_int(second_uint, 6);
	first_uint_copy = first_uint;
	second_uint_copy = second_uint;
	tmp = argv[1];
	setAnnotation_char((void*)first_uint_copy, argv[1]);
    tmp = first_uint_copy;
	((void (*)(int32_t *))((void*)*second_uint_copy))(second_uint_copy);
	return (0);
}
