#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char* argv[]) {
	mpz_t n;
	char* s;
	unsigned long int i;

	mpz_init(n);

	i = 0;

	while(1) {
		mpz_fib_ui(n, ++i);
		s = mpz_get_str(NULL, 10, n);
		if (strlen(s) >= 1000) {
			break;
		}
		free(s);
	}

	mpz_clear(n);

	printf("%lu\n", i);

	return 0;
}
