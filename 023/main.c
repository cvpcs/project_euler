#include <stdio.h>
#include <stdlib.h>
#include <utils.h>

uint8_t is_abundant(uint32_t number) {
	uint64_t* d = divisors(number);

	uint64_t sum = 0;
	for (int i = 0; d[i]; i++) {
		sum += d[i];
	}

	free(d);

	return (number < sum) ? 1 : 0;
}

uint32_t* abundants(uint32_t min, uint32_t max) {
	const size_t BBS = 32;
	size_t bbc = 1;

	uint32_t* abundants = calloc(bbc * BBS, sizeof(uint32_t));

	uint32_t c = 0;
	for (uint32_t i = min; i <= max; i++) {
		if (is_abundant(i)) {
			abundants[c++] = i;

			if (c >= (bbc * BBS) - 1) {
				abundants = realloc(abundants, ++bbc * BBS * sizeof(uint32_t));
			}
		}
	}

	abundants[c] = 0;
	return abundants;
}

int main(int argc, char* argv[]) {
	const uint32_t min = 12;
	const uint32_t max = 28123;

	uint32_t* a = abundants(min, max);

	uint8_t* flags = (uint8_t*)calloc(max, sizeof(uint8_t));

	for (int i = 0; a[i]; i++) {
		for (int j = 0; a[j]; j++) {
			uint32_t sum = a[i] + a[j];

			if (sum <= max)
				flags[sum - 1] = 1;

			if (a[i] == a[j])
				break;
		}
	}

	uint64_t sum = 0;
	for (uint32_t i = 1; i <= max; i++) {
		if (!flags[i - 1]) {
			sum += i;
		}
	}

	printf("%llu", sum);

	return 0;
}
