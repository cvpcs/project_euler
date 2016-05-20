#include <stdio.h>
#include <primes.h>

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

int main(int argc, char* argv) {
	__int8* prime_list = create_prime_list(MAX);

	for (unsigned long long i = MAX; i >= 0; i--) {
		if (is_prime(prime_list, i) && is_pandigital(i)) {
			printf("Pandigital + Prime: %llu\n", i);
			break;
		}
	}

	free(destroy_prime_list);

	return 0;
}
