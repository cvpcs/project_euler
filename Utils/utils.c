#include <utils.h>

#include <stdint.h>
#include <stdlib.h>
#include <math.h>

uint8_t* create_prime_list(uint64_t upper_bound) {
	uint8_t* prime_list = (uint8_t*)calloc((size_t)(upper_bound / 8 + 1), sizeof(uint8_t));

	// 0 and 1 are not prime
	prime_list[0] |= (uint8_t)3;

	long double limit = sqrtl((long double)upper_bound);
	for (unsigned long long i = 2; i <= limit + 1; i++) {
		if (!is_prime(prime_list, i))
			continue;

		for (int j = 2; i * j <= upper_bound; j++) {
			unsigned long long n = i * j;
			prime_list[n / 8] |= (uint8_t)(1 << (n % 8));
		}
	}

	return prime_list;
}

void destroy_prime_list(uint8_t* prime_list) {
	free(prime_list);
}

uint8_t is_prime(uint8_t* prime_list, uint64_t n) {
	return ((1 << n % 8) & prime_list[n / 8]) == 0;
}

uint64_t* factors(uint64_t n) {
	const size_t BBS = 32;
	size_t bbc = 1;

	uint64_t* factors = calloc(bbc * BBS, sizeof(uint64_t));

	uint64_t bound = (uint64_t)sqrtl((long double)n);
	uint64_t remainder = n;

	uint64_t c = 0;
	while (remainder > 1) {
		for (uint64_t i = 2; i <= bound; i++) {
			if (remainder % i == 0) {
				factors[c++] = i;

				if (c >= (bbc * BBS) - 1) {
					factors = realloc(factors, ++bbc * BBS * sizeof(uint64_t));
				}

				remainder /= i;
				break;
			}
		}
	}

	factors[c] = 0;
	return factors;
}

uint64_t* divisors(uint64_t n) {
	const size_t BBS = 32;
	size_t bbc = 1;

	uint64_t* divisors = calloc(bbc * BBS, sizeof(uint64_t));

	uint64_t c = 0;
	for (uint64_t i = 1; i <= n / 2; i++) {
		if (n % i == 0) {
			divisors[c++] = i;

			if (c >= (bbc * BBS) - 1) {
				divisors = realloc(divisors, ++bbc * BBS * sizeof(uint64_t));
			}
		}
	}

	divisors[c] = 0;
	return divisors;
}