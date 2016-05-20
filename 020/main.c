#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char* argv[]) {
	mpz_t n;
	unsigned int i;
	int m;
	char* s;
	char b[2];

	mpz_init(n);
	mpz_set_ui(n, 1);

	for(i = 100; i > 0; i--) {
		mpz_mul_ui(n, n, i);
	}

	s = mpz_get_str(NULL, 10, n);
	mpz_clear(n);

	m = 0;
	b[1] = '\0';
	for(i = 0; i < strlen(s); i++) {
		b[0] = s[i];
		m += atoi(b);
	}

	free(s);

	printf("%d\n", m);

	return 0;
}
