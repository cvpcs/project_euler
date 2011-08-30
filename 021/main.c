#include <stdio.h>
#include <stdlib.h>

int d(int n) {
	int i;
	int m;

	m = 0;
	for (i = 1; i < n; i++) {
		if (n % i == 0) {
			m += i;
		}
	}

	return m;
}

int main(int argc, char* argv[]) {
	int i;
	int j;
	int k;

	k = 0;

	for (i = 0; i < 10000; i++) {
		j = d(i);

		if (j != i && d(j) == i) {
			k += i;
		}
	}

	printf("%d\n", k);

	return 0;
}
