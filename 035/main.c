#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

void rotate_str(char* s) {
	char c = s[0];
	size_t l = strlen(s);

	for (unsigned int i = 1; i < l; i++) {
		s[i - 1] = s[i];
	}

	s[l - 1] = c;
}

int is_circular(mpz_t n) {
	char* s = mpz_get_str(NULL, 10, n);
	size_t l = strlen(s);
	mpz_t m;

	mpz_init(m);
	int r = 1;

	for (unsigned int i = 0; i < l; i++) {
		mpz_set_str(m, s, 10);
		if (mpz_probab_prime_p(m, 10) == 0) {
			r = 0;
			break;
		}
		rotate_str(s);
	}

	mpz_clear(m);
	free(s);

	return r;
}

int main(int argc, char* argv[]) {
	mpz_t n;
	int i;

	mpz_init(n);
	mpz_set_ui(n, 1);
	mpz_nextprime(n, n);

	i = 0;

	while(mpz_get_ui(n) < 1000000) {
		if (is_circular(n)) {
			i++;
		}
		mpz_nextprime(n, n);
	}

	printf("%d\n", i);

	mpz_clear(n);

	return 0;
}
