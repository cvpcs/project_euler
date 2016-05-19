#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int score(char* s) {
	int i;
	int n;

	n = 0;
	for (i = 0; i < strlen(s); i++) {
		n += (s[i] - 64);
	}

	return n;
}

int main(int argc, char* argv[]) {
	int n;
	int i;
	int r;
	char s[512];

	n = 0;
	i = 1;
	r = 1;
	r = scanf_s("%s", s, 512);
	while (r != EOF) {
		n += score(s) * i++;
		r = scanf_s("%s", s, 512);
	}

	printf("%d\n", n);

	return 0;
}
