#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	log_wrapper(FILE *a, char *b, char *c) {
	// Stack corruption will be checked
	FILE *e = a; // [rbp-0x118]
	char *str = b; // [rbp-0x120]
	char *_av1 = c; // [rbp-0x128]
	char h[256]; // [rbp-0x110]

	strcpy(h, str);
	snprintf(h + strlen(h), 254 - strlen(h), str); // repnz scas
	h[strcspn(h, "\n")] = 0;
	fprintf(e, "LOG: %s\n", h);
}

int	main(int ac, char **av) {
	// Stack corruption will be checked
	int _ac = ac; // [rbp-0x94]
	char **_av = av; // [rbp-0xa0]
	char c = 255; // [rbp-0x71]
	int d = 4294967295; // [rbp-0x78]
	FILE	*e; // [rbp-0x88]
	FILE	*f; // [rbp-0x80]
	char	g[99]; // [rbp-0x70]

	//if (_ac != 2) {
	//	printf("Usage: %s filename\n", *_av);
	//}
	e = fopen("./backups/.log", "w");
	if (e == 0) {
		//printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	log_wrapper(e, "Starting back up: ", _av[1]);
	f = fopen(_av[1], "r");
	if (f == 0) {
		//printf("ERROR: Failed to open %s\n", _av[1]);
		exit(1);
	}
	strncpy(g, "./backups/", 11); // main+281 -> main+308
	strncat(g, _av[1], 99 - strlen(g)); // repnz scas
	d = open(g, 193, 432);
	if (d < 0) {
		//printf("ERROR: Failed to open %s%s\n", "./backups/", _av[1]);
		exit(1)
	}
	do {
		c = fgetc(f);
		write(d, &c, 1);
	} while (c != EOF);
	log_wrapper(e, "Finished back up ", _av[1]);
	fclose(f);
	close(d);
	return 0;
}
