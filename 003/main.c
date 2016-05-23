#include <stdlib.h>
#include <stdio.h>
#include <utils.h>

int main(int argc, char* argv[]) {
	uint64_t input = 600851475143;
	uint64_t* f = factors(input);

	printf("Prime factors of %llu:\n", input);

	for (int i = 0; f[i]; i++) {
		printf("  %llu\n", f[i]);
	}

	free(f);
}
