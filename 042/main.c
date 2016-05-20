#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_triangle_word(char* s) {
	unsigned int i;
	int t;
	int j = 0;
	size_t l = strlen(s);

	for (i = 0; i < l; i++) {
		j += s[i] - 64;
	}

	t = 0;
	for (i = 1; t < j; i++) {
		t = (i * (i + 1)) / 2;

		if (t == j) {
			return 1;
		}
	}

	return 0;
}

int main(int argc, char* argv[]) {
	char s[512];
	int i;
	int j;
	char c;

	i = 0;
	j = 0;
	c = getchar();
	while(c != EOF) {
		if (c == ',') {
			s[i] = '\0';
			if (is_triangle_word(s)) {
				j++;
			}
			i = 0;
		} else if (c != '"') {
			s[i++] = c;
		}
		c = getchar();
	}

	s[i] = '\0';
	if (is_triangle_word(s)) {
		j++;
	}

	printf("%d\n", j);

	return 0;
}
