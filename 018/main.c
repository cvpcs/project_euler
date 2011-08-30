#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int** p;
	int i;
	int j;
	int r;
	int v;
	int s;

	p = (int**)malloc(sizeof(int*));
	i = 0;
	j = 0;
	v = 0;
	r = 1;
	while(r != EOF) {
		p = (int**)realloc(p, sizeof(int*) * (i + 1));
		p[i] = (int*)malloc(sizeof(int) * (i + 1));
		for (j = 0; j < (i + 1); j++) {
			r = scanf("%d", &v);
			p[i][j] = v;
		}
		i++;
	}
	s = i - 1;

	printf("%d rows loaded...\n", s);

	for (i = s - 2; i >= 0; i--) {
		for (j = 0; j < i + 1; j++) {
			if (p[i + 1][j] > p[i + 1][j + 1]) {
				p[i][j] += p[i + 1][j];
			} else {
				p[i][j] += p[i + 1][j + 1];
			}
		}
	}

	printf("%d\n", p[0][0]);

	for (i = 0; i < s; i++) {
		free(p[i]);
	}
	free(p);

	return 0;
}
