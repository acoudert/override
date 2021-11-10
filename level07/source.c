#include <string.h>
#include <stdio.h>

void	clear_stdin() {
	int		f = 0; // [ebp-0x9]

	while (f != EOF && f != '\n') {
		f = getchar();
	}
}

unsigned int get_unum() {
	unsigned int	e;

	fflush(stdout);
	scanf("%u", &e);
	clear_stdin();
	return e;
}

int	read_number(char *buf) {
	int	d = 0; // [ebp-0xc]

	//printf(" Index: ");
	d = get_unum();
	printf(" Number at data[%u] is %u\n", d, buf[d << 2]);
	return 0;
}

int	store_number(char *buf) {
	int	b = 0; // [ebp-0x10]
	unsigned int	c = 0; // [ebp-0xc]
	
	//printf(" Number: ");
	b = get_unum();
	//printf(" Index: ");
	c = get_unum();
	if (c - ((unsigned int)(c * 2863311531 / UINT_MAX) / 2) * 3 != 0) {
		if (b >> 24 != 183) {
			buf[c << 2] = b;
			return 0;
		}
	}
	//puts(" *** ERROR! ***");
	//puts("   This index is reserved for wil!");
	//puts(" *** ERROR! ***");
	return 1;
}

int	main(int ac, char **av, char **env) {
	char	**avs; // [esp+0x1c]
	char	**envs; // [esp+0x18]
	int		a; // [esp+0x1cc]
	int		begin_arr = 0; // [esp+0x1b4]
	char	arr[20] = {0}; // [esp+0x1b8] -> [esp+0x1c8]+4
	char	buf[100] = {0}; // [esp+0x24]

	avs = av;
	envs = env;
	while (avs) {
		memset(*avs, 0, strlen(*avs)); // repnz scas
		avs += 1;
	}
	while (envs) {
		memset(*envs, 0, strlen(*envs)); // repnz scas
		envs += 1;
	}
	//puts([store, read, quit]);
	while (1) {
		//printf("Input command: ");
		begin_arr = 1;
		fgets(arr, 20, stdin);
		arr[strlen(arr) - 1] = 0; // repnz scas
		if (strncmp(arr, "store", 5) == 0) { // repz cmps
			begin_arr = store_number(buf);
		}
		if (strncmp(arr, "read", 4) == 0) { // repx cmps
			begin_arr = read_number(buf);
		}
		if (strncmp(arr, "quit", 4) == 0) { // repx cmps
			return 0;
		}
		//if (begin_arr != 0) {
		//	printf(" Failed to do %s command\n");
		//} else {
		//	printf(" Completed %s command successfully\n");
		//}
		bzero(arr, 20); // main+645 -> main+672
	}
}
