#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>

int main(int argc, char* argv[]) {
	int i;
	mpz_t n;
	char* str;

	mpz_init(n);
	mpz_set_ui(n, 0);
	
	for(i = 0; i < 10001; i++) {
		mpz_nextprime(n, n);
	}

	str = mpz_get_str(NULL, 10, n);

	printf("%s\n", str);

	free(str);

	mpz_clear(n);

	return 0;
}
