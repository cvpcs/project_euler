#include <primes.h>

#include <stdlib.h>
#include <math.h>

__int8* create_prime_list(unsigned long long upper_bound) {
	__int8* prime_list = (__int8*)calloc((size_t)(upper_bound / 8 + 1), sizeof(__int8));

	// 0 and 1 are not prime
	prime_list[0] |= (__int8)3;

	long double limit = sqrtl((long double)upper_bound);
	for (unsigned long long i = 2; i <= limit + 1; i++) {
		if (!is_prime(prime_list, i))
			continue;

		for (int j = 2; i * j <= upper_bound; j++) {
			unsigned long long n = i * j;
			prime_list[n / 8] |= (__int8)(1 << (n % 8));
		}
	}

	return prime_list;
}

void destroy_prime_list(__int8* prime_list) {
	free(prime_list);
}

int is_prime(__int8* prime_list, unsigned long long n) {
	return ((1 << n % 8) & prime_list[n / 8]) == 0;
}
