#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int		main(int ac, char **av) {
	char	c;

	for (unsigned int i; i < 100; i++) {
		unsigned int a = ((unsigned int)(i * 2863311531 / UINT_MAX) / 2) * 3;
		if (i - a == 0) {
			printf("%u: Forbidden index\n", i);
		}
	}

}
