#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>

#define MAX 2000000

int main(int argc, char* argv[]) {
	int i;
	mpz_t n;
	mpz_t m;
	char* str;

	mpz_init(n);
	mpz_init(m);
	mpz_set_ui(n, 0);
	mpz_set_ui(m, 0);

	while(1) {
		mpz_nextprime(n, n);
		if (mpz_get_ui(n) > MAX) {
			break;
		} else {
			mpz_add(m, n, m);
		}
	}

	str = mpz_get_str(NULL, 10, m);

	printf("%s\n", str);

	free(str);

	mpz_clear(n);
	mpz_clear(m);

	return 0;
}
