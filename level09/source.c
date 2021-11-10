#include <stdio.h>
#include <strings.h>

struct s {
	char	str[140];
	char	buf[40];
	int		b;
};

void	secret_backdoor() {
	char	f[128];

	fgets(f, 128, stdin);
	system(f);
}

void	set_msg(struct s *a) {
	struct s *d = a; // [rbp-0x408]
	char e[1024] = {0}; // [rbp-0x400]

	//puts(">: Msg @Unix-Dude");
	//printf(">>: ");
	fgets(e, 1024, stdin);
	strncpy(*d, e, d->b); // *d = d->str
}

void	set_username(struct s *a) {
	struct s *b = a; // [rbp-0x98]
	char buf[128] = {0}; // [rbp-0x90]
	int	c; // [rbp-0x4]

	//puts(">: Enter your username");
	//printf(">>: ");
	fgets(buf, 128, stdin);
	c = 0;
	while (buf[c]) {
		b->buf[c] = buf[c];
		c += 1;
		if (c > 40) {
			break;
		}
	}
	//printf(">: Welcome, %s", b->buf);
}

void	handle_msg() {
	struct s	a; // [rbp-0xc0]
	// a.buf // [rbp-0xc0+0x8c]
	// a.b // [rbp-0xc]

	bzero(a.buf, 40); // a.str initialisation
	a.b = 140;
	set_username(&a);
	set_msg(&a);
	//puts(">: Msg sent!");
}

int		main() {
	//puts("Welcome ...");
	handle_msg();
	return 0;
}
