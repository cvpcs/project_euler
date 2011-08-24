#include <stdio.h>

int get_tri(int n) {
	int i;
	int r;

	r = 0;
	for(i = 1; i <=n; i++) {
		r += i;
	}

	return r;
}

int get_num_div(int n) {
	int i;
	int r;

	r = 0;
	for(i = 1; i <= n; i++) {
		if (n % i == 0) {
			r++;
		}
	}

	return r;
}

int main(int argc, char* argv[]) {
	int i;
	int j;

	i = 1;
	while(1) {
		j = get_tri(i);
		printf("Triangle number: %d\n", j);
		j = get_num_div(j);
		printf("Num divisors: %d\n", j);
		if (j > 500) {
			break;
		}
		i++;
	}

	printf("%d\n", i);

	return 0;
}
