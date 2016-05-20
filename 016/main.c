#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char* argv[]) {
	mpz_t n;
	mpz_t m;
	char* str;
	char* buf;

	mpz_init(n);
	mpz_init(m);
	mpz_ui_pow_ui(n, 2, 1000);

	str = mpz_get_str(NULL, 10, n);

	printf("Number we are adding the digits of: %s\n", str);

	mpz_set_ui(n, 0);

	buf = (char*)malloc(2 * sizeof(char));

	for(unsigned int i = 0; i < strlen(str); ++i) {
		buf[0] = str[i];
		buf[1] = '\0';
		mpz_set_str(m, buf, 10);
		mpz_add(n, n, m);
	}

	free(buf);
	free(str);

	str = mpz_get_str(NULL, 10, n);	

	printf("Sum of digits: %s\n", str);

	free(str);

	mpz_clear(n);
	mpz_clear(m);

	return 0;
}
