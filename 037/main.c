#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int is_tr_l(mpz_t n) {
	char* s;
	mpz_t m;
	int r;

	if (mpz_probab_prime_p(n, 10) == 0) {
		return 0;
	}

	s = mpz_get_str(NULL, 10, n);

	if (strlen(s) == 1) {
		r = 1;
	} else {
		mpz_init(m);
		mpz_set_str(m, s+1, 10);
		r = is_tr_l(m);
		mpz_clear(m);
	}

	free(s);

	return r;
}

int is_tr_r(mpz_t n) {
	char* s;
	mpz_t m;
	int r;

	if (mpz_probab_prime_p(n, 10) == 0) {
		return 0;
	}

	s = mpz_get_str(NULL, 10, n);

	if (strlen(s) == 1) {
		r = 1;
	} else {
		mpz_init(m);
		s[strlen(s) - 1] = '\0';
		mpz_set_str(m, s, 10);
		r = is_tr_r(m);
		mpz_clear(m);
	}

	free(s);

	return r;
}

int main(int argc, char* argv[]) {
	mpz_t n, m;
	char* s;

	mpz_init(n);
	mpz_init(m);
	mpz_set_ui(n, 7);
	mpz_set_ui(m, 0);
	mpz_nextprime(n, n);

	int i = 0;

	while(i < 11) {
		if (is_tr_l(n) && is_tr_r(n)) {
			i++;
			mpz_add(m, n, m);
		}

		mpz_nextprime(n, n);
	}

	s = mpz_get_str(NULL, 10, m);
	printf("%s\n", s);
	free(s);

	mpz_clear(n);
	mpz_clear(m);

	return 0;
}
