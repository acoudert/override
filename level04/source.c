#include <sys/types.h>
#include <unistd.h>
#include <strings.h>
#include <sys/prctl.h>
#include <sys/ptrace.h>
#include <stdio.h>
#include <sys/wait.h>

int	main() {
	pid_t	pid; // [esp+0xac]
	char	buf[128]; // [esp+0x20]
	int		a; // [esp+0xa8]
	int		b; // [esp+0x1c]
	int		c; // [esp+0xa0]
	int		d; // [esp+0xa4]

	pid = fork();
	bzero(buf, 128);
	a = 0;
	b = 0;
	if (pid == 0) {
		prctl(PR_SET_PDEATHSIG, 1);
		ptrace(PTRACE_TRACEME, 0, NULL, NULL);
		//puts("Give me some shellcode, k");
		gets(buf);
	} else {
		do {
			wait(&b);
			if (b & 127 == 0 || ((b & 127) + 1) >> 1 > 0) {
				//puts("child is exiting...");
				return 0;
			}
			a = ptrace(PTRACE_PEEKUSR, pid, 44, 0);
		} while (a != 11);
		//puts("no exec() for you");
		kill(pid, 9);
	}
	return 0;
}
