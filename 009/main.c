#include <stdio.h>

int main(int argc, char* argv[]) {
	int a;
	int b;
	int c;
	int r = 0;

	for (a = 0; a < 998; a++) {
		for (b = a + 1; b < 998; b++) {
			for (c = b + 1; c < 998; c++) {
				if ((a * a) + (b * b) == (c * c) &&
						a + b + c == 1000) {
					r = a * b * c;
				}
			}
		}
	}

	printf("%d\n", r);

	return 0;
}
