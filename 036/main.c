#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int is_dual_palendrome(int n) {
	mpz_t m;	
	char* s;

	unsigned int i;
	size_t j;
	int r;

	mpz_init(m);
	mpz_set_ui(m, n);

	s = mpz_get_str(NULL, 10, m);
	i = 0;
	j = strlen(s) - 1;
	r = 1;
	while(i <= j && r) {
		if (s[i++] != s[j--]) {
			r = 0;
		}
	}
	free(s);

	s = mpz_get_str(NULL, 2, m);
	i = 0;
	j = strlen(s) - 1;
	while(i <= j && r) {
		if (s[i++] != s[j--]) {
			r = 0;
		}
	}
	free(s);

	mpz_clear(m);

	return r;
}

int main(int argc, char* argv[]) {
	int i;
	int j;

	j = 0;
	for (i = 1; i < 1000000; ++i) {
		if (is_dual_palendrome(i)) {
			j += i;
		}
	}

	printf("%d\n", j);

	return 0;
}
