#include <strings.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main() {
	int		a; // [rbp-0x114]
	int		b; // [rbp-0x120]
	char	buf1[100]; // [rbp-0x70]
	char	buf2[41]; // [rbp-0xa0]
	char	buf3[100]; // [rbp-0x110]
	FILE	*file; // [rbp-0x8]
	long	c; // [rbp-0xc]

	bzero(buf1, 100); // rep stos
	bzero(buf2, 41); // rep stos
	bzero(buf3, 100); // rep stos
	file = fopen("/home/users/level03/.pass", "r");
	if (file == 0) {
		//fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
		exit(1);
	}
	c = fread(buf2, 1, 41, file);
	buf2[strcspn(buf2, "\n")] = 0;
	if (c != 41) {
		//fwrite("ERROR: failed to read password file\n", 1, 41, stderr);
		//fwrite("ERROR: failed to read password file\n", 1, 41, stderr);
		exit(1);
	}
	fclose(file);
	//puts("===== [ Secure Access System v1.0 ] =====");
	//puts("/***************************************\\");
	//puts("| You must login to access this system. |");
	//puts("\\***************************************/");
	//printf("--[ Username: ");
	fgets(buf1, 100, stdin);
	buf1[strcspn(buf1, "\n")] = 0;
	//printf("--[ Password: ");
	fgets(buf3, 100, stdin);
	buf3[strcspn(buf3, "\n")] = 0;
	//puts("*****************************************");
	if (strncmp(buf2, buf3, 41) == 0) {
		//printf("Greetings, %s!\n", buf1);
		system("/bin/sh");
		return 0;
	}
	printf(buf1);
	//puts(" does not have access!");
	exit(1);
}
