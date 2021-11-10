#include <stdio.h>
#include <unistd.h>

int	main() {
	char	buf[100]; // [esp+0x28]
	int		a; // [esp+0x8c]

	fgets(buf, 100, stdin);
	a = 0;
	while (a < strlen(buf)) {
		if (buf[a] > 64 && buf[a] <= 90) {
			buf[a] = buf[a] ^ 32;
		}
		a += 1;
	}
	printf(buf);
	exit(0);
}
