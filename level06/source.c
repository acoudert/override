#include <stdio.h>
#include <string.h>
#include <sys/ptrace.h>
#include <limits.h>

int		auth(char *buf, unsigned int d) {
	unsigned int e; // [ebp-0xc]
	int f; // [ebp-0x10]
	int g; // [ebp-0x14]

	buf[strcspn(buf, "\n")] = 0;
	e = strnlen(buf, 32);
	if (e > 5) {
		if (ptrace(PTRACE_TRACEME, 0, 1, 0) != -1) {
			f = (buf[3] ^ 4919) + 6221293;
			g = 0;
			while (g < e) {
				if (buf[g] <= 31) {
					return 1;
				}
				f += (buf[g] ^ f) - (((((buf[g] ^ f) - ((buf[g] ^ f) * 2284010283 / UINT_MAX)) / 2 + ((buf[g] ^ f) * 2284010283 / UINT_MAX)) >> 10) * 1337);
				g += 1;
			}
			printf("%u\n", f);
			if (f == d) {
				return 0;
			}
		}
		//puts("\033[32m.---------------------------.");
		//puts("\033[31m| !! TAMPERING DETECTED !!  |");
		//puts("\033[32m'---------------------------'");
	}
	return 1;
}

int	main(int ac, char **av) {
	int a; // [esp+0x1c]
	int b; // [esp+0x4c]
	char	buf[32]; // [esp+0x2c]
	unsigned int d; // [esp+0x28]

	//puts("***********************************");
	//puts("*\t\tlevel06\t\t  *");
	//puts("***********************************");
	//printf("-> Enter Login: ");
	fgets(buf, 32, stdin);
	//puts("***********************************");
	//puts("***** NEW ACCOUNT DETECTED ********");
	//puts("***********************************");
	//printf("-> Enter Serial: ");
	scanf("%u", &d);
	if (auth(buf, d) == 0) {
		//puts("Authenticated!");
		system("/bin/sh");
		return 0;
	}
	return 1;
}
