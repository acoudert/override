#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int		decrypt(int d) {
	// Check if corrupted stack
	char	*e = "Q}|u`sfg~sf{}|a3"; // [ebp-0x1d] - Refer to Ressources/hex_to_str.py
	int		g = strlen(e); // [ebp-0x2c] - repnz scas
	int		h = g; // [ebp-0x24]
	int		i = 0; // [ebp-0x28]

	while (i < h) {
		e[i] = d ^ e[i];
		i += 1;
	}
	if (strncmp(e, "Congratulations!", 17) == 0) {
		system("/bin/sh");
	} //else {
		//puts("\nInvalid Password");
	//}
	// check if corrupted stack
}

void	test(int a, int b) {
	int	c; // [ebp-0xc]

	c = b - a;
	if ((unsigned int)c <= 21)  {
		//(c << 2) + 134515184; // jump eax
		return decrypt(c);
		//...
		//return decrypt(c);
	} else {
		return decrypt(rand());
	}
}

int main() {
	int		a; // [esp+0x1c]

	srand(time(NULL));
	//puts("***********************************");
	//puts("*\t\tlevel03\t\t**");
	//puts("***********************************");
	//printf("Password:");
	scanf("%d", a);
	test(a, 322424845);
	return 0;
}
