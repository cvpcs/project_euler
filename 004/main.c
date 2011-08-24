#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palendrome(int n) {
	char* str;
	int i;
	int j;
	int r;

	str = (char*)malloc(256 * sizeof(char));
	sprintf(str, "%d", n);

	i = 0;
	j = strlen(str) - 1;

	r = 1;

	while(i <= j) {
		if (str[i++] != str[j--]) {
			r = 0;
			break;
		}
	}

	free(str);

	return r;
}

int main(int argc, char* argv[]) {
	int i;
	int j;
	int n;
	int m = 0;

	for (i = 100; i < 1000; ++i) {
		for (j = 100; j < 1000; ++j) {
			n = i * j;

			if (is_palendrome(n) && n > m) {
				m = n;
			}
		}
	}

	printf("Largest palendrome: %d\n", m);
}
