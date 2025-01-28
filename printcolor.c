#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main (int ac , char **av)
{
	int len = strlen(av[1]);

	int cmp = strncmp (av[1] + (len - 4) , ".ber", 5);
	if (cmp == 0)
		printf("\033[32mcorrect the file end with .ber\n\033[0m");
	else
		printf("\033[31m no this does not end with .ber\n\033[0m");
}