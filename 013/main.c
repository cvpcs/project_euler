#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char* argv[]) {
	mpz_t n;
	mpz_t m;
	char* str;

	mpz_init(n);
	mpz_init(m);
	mpz_set_ui(n, 0);

	while(1) {
		str = (char*)malloc(256 * sizeof(char));
		gets_s(str, 255);
		printf("Found number: \"%s\"\n", str);

		if(strlen(str) == 0) {
			break;
		} else {
			mpz_set_str(m, str, 10);
			mpz_add(n, n, m);
		}

		free(str);
	}

	str = mpz_get_str(NULL, 10, n);

	printf("Sum of digits: %s\n", str);

	free(str);

	mpz_clear(n);
	mpz_clear(m);

	return 0;
}
