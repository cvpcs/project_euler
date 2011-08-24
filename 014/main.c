#include <stdio.h>

int calc_chain_length(int n) {
	int i = 1;

	while(1) {
		if (n == 1) {
			break;
		}

		if (n % 2 == 0) {
			n /= 2;
		} else {
			n = 3 * n + 1;
		}

		i++;
	}

	return i;
}

int main(int argc, char* argv[]) {
	int i, j;
	int r = 0;

	for(i = 1; i < 1000000; i++) {
		j = calc_chain_length(j);
		if (r < j) {
			r = j;
		}
	}

	printf("%d\n", r);
	return 0;
}
