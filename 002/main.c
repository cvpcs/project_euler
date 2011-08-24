#include <stdio.h>
#include <stdlib.h>

int fib_sum(int max) {
	int a = 1;
	int b = 2;
	int t;
	int s = 2;

	while(b < max) {
		t = b;
		b = b + a;
		a = t;

		if(b % 2 == 0) {
			s += b;
		}
	}

	return s;
}

int main(int argc, char* argv[]) {
	printf("%d\n", fib_sum(4000000));
}
