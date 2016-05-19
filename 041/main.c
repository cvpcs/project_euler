#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 987654321

int is_pandigital(unsigned long long n) {
	char digits[11];
	digits[0] = 1;
	int digitsUsed = 0;

	for (unsigned long long m = MAX, i = 9; m > n; m /= 10, i--) {
		digits[i + 1] = 1;
		digitsUsed++;
	}

	for (unsigned long long m = n; m > 0; m /= 10) {
		int d = m % 10;
		if (digits[d] == 1) {
			digitsUsed = -1;
			break;
		}

		digits[d] = 1;
		digitsUsed++;
	}

	return digitsUsed == 10;
}

__int8* get_prime_list(unsigned long long upper_bound) {
	__int8* prime_list = (__int8*)calloc((upper_bound / 8 + 1), sizeof(__int8));
	
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

int is_prime(__int8* prime_list, unsigned long long n) {
	return ((1 << n % 8) & prime_list[n / 8]) == 0;
}

int main(int argc, char* argv) {
	__int8* prime_list = get_prime_list(MAX);

	for (unsigned long long i = MAX; i >= 0; i--) {
		if (is_prime(prime_list, i) && is_pandigital(i)) {
			printf("Pandigital + Prime: %llu\n", i);
			break;
		}
	}

	free(prime_list);

	return 0;
}
