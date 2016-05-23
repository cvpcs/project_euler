#include <stdio.h>
#include <utils.h>

#define MAX 2000000

int main(int argc, char* argv[]) {
	__int8* prime_list = create_prime_list(MAX);

	unsigned long long sum = 0;
	for (int i = 0; i < MAX; i++) {
		if (is_prime(prime_list, i)) {
			sum += i;
		}
	}

	printf("%llu\n", sum);

	destroy_prime_list(prime_list);

	return 0;
}
