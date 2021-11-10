#include <stdio.h>
#include <stdlib.h>

int		main() {
	int		n;

	//puts("***********************************");
	//puts("* \t     -Level00 -\t\t  *");
	//puts("***********************************");
	//printf("Password:");
	scanf("%d", &n);
	if (n == 5276) {
		//printf("\nAuthenticated!");
		system("/bin/sh");
		return 0;
	}
	//puts("\nInvalid Password!");
	return 1;
}
