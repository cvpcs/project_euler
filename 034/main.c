#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int find_max() {
	mpz_t n, m;
	unsigned int i, j, r;
	char* s;

	mpz_init(n);
	mpz_init(m);

	mpz_fac_ui(n, 9);
	mpz_set_ui(m, 0);
	s = mpz_get_str(NULL, 10, m);

	for (i = 0; strlen(s) >= i; i++) {
		free(s);
		mpz_mul_ui(m, n, i);
		s = mpz_get_str(NULL, 10, m);
	}

	free(s);
	mpz_clear(n);
	mpz_clear(m);

	r = 1;

	for (j = 0; j < i; j++) {
		r *= 10;
	}

	return r;
}

int is_fac_sum(mpz_t n) {
	char* s;
	char* b;
	int r;
	mpz_t l, m;

	b = (char*)malloc(sizeof(char) * 2);
	b[0] = '0';
	b[1] = '\0';
	s = mpz_get_str(NULL, 10, n);

	mpz_init(l);
	mpz_init(m);
	mpz_set_ui(m, 0);

	for (unsigned int i = 0; i < strlen(s); i++) {
		b[0] = s[i];

		mpz_fac_ui(l, atoi(b));
		mpz_add(m, l, m);
	}

	if (mpz_cmp(n, m) == 0) {
		r = 1;
	} else {
		r = 0;
	}

	mpz_clear(l);
	mpz_clear(m);

	free(b);
	free(s);

	return r;
}

int main(int argc, char* argv[]) {
	int m;
	int i;
	mpz_t n;
	mpz_t r;
	char* s;

	m = find_max();

	mpz_init(r);
	mpz_set_ui(r, 0);

	for (i = 3; i < m; i++) {
		mpz_init(n);
		mpz_set_ui(n, i);

		if (is_fac_sum(n)) {
			s = mpz_get_str(NULL, 10, n);
			printf("Fact sum: %s\n", s);
			free(s);
			mpz_add(r, n, r);
		}

		mpz_clear(n);
	}

	s = mpz_get_str(NULL, 10, r);
	printf("\nSum: %s\n", s);
	free(s);

	mpz_clear(r);

	return 0;
}
