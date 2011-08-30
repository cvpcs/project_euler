#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char* argv[]) {
	mpz_t n;
	mpz_t m;
	int i;
	char* s;

	mpz_init(n);
	mpz_init(m);

	mpz_set_ui(m, 0);

	for (i = 1; i < 1001; i++) {
		mpz_set_ui(n, i);
		mpz_pow_ui(n, n, i);
		mpz_add(m, m, n);
	}

	mpz_clear(n);

	s = mpz_get_str(NULL, 10, m);

	mpz_clear(m);

	printf("%s\n", s + strlen(s) - 10);

	free(s);

	return 0;
}
