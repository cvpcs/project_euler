#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[]) {
	uint64_t d = 600851475143;
	uint64_t i;

	printf("Divisors of 600851475143:\n");

	while(d > 1) {
		for(i = 2; i < 600851475143; i++) {
			if(d % i == (uint64_t)0) {
				printf("%d\n", i);
				d = d / i;
				break;
			}
		}
	}
}
