/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 23:07:35 by aalves            #+#    #+#             */
/*   Updated: 2019/05/10 23:07:35 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
