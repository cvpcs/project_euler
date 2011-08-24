#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
	int n;
	int m;
	int i;

	n = 0;
	m = 0;
	for (i = 1; i < 101; ++i) {
		m += i;
		n += i * i;
	}

	printf("Diff: %d\n", abs(n - (m * m)));

	return 0;
}
