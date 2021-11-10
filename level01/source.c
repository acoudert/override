#include <strings.h>
#include <string.h>
#include <stdio.h>

char	a_user_name[256];

int		verify_user_name() {
	//puts("verifying username....\n");
	return strncmp(a_user_name, "dat_wil", 7); // repz cmps
}

int	verify_user_pass(char *buf) {
	return strncmp(buf, "admin", 5); // repz cmps
}

int main() {
	char	buf[16];
	int		n;

	bzero(buf, 16); // rep stos
	n = 0;
	//puts("********* ADMIN LOGIN PROMPT *********");
	//printf("Enter Username: ");
	fgets(a_user_name, 256, stdin);
	n = verify_user_name();
	if (n != 0) {
		//puts("nope, incorrect username...\n");
		return 1;
	} else {
		//puts("Enter Password: ");
		fgets(buf, 100, stdin);
		n = verify_user_pass(buf);
		if (n == 0) {
			if (n == 0) {
				return 0;
			}
		}
		//puts("nope, incorrect password...\n");
		return 1;
	}
}
