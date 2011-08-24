#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define LEN 4

int calc_down(int x, int y, int grid[]) {
	int i;
	int j;
	int r;

	r = 1;
	for(i = 0; i < LEN; i++) {
		j = ((y + i) * SIZE) + x;

		if (j < 0 || j >= SIZE * SIZE) {
			return 0;
		}

		r *= grid[((y + i) * SIZE) + x];
	}

	return r;
}

int calc_right(int x, int y, int grid[]) {
	int i;
	int r;
	int j;

	r = 1;
	for(i = 0; i < LEN; i++) {
		j = (y * SIZE) + x + i;

		if (j < 0 || j >= SIZE * SIZE) {
			return 0;
		}

		r *= grid[(y * SIZE) + x + i];
	}

	return r;
}

int calc_rdiag(int x, int y, int grid[]) {
	int i;
	int r;
	int j;

	r = 1;
	for(i = 0; i < LEN; i++) {
		j = ((y + i) * SIZE) + x + i;

		if (j < 0 || j >= SIZE * SIZE) {
			return 0;
		}

		r *= grid[((y + i) * SIZE) + x + i];
	}

	return r;
}

int calc_ldiag(int x, int y, int grid[]) {
	int i;
	int r;
	int j;

	r = 1;
	for(i = 0; i < LEN; i++) {
		j = ((y + i) * SIZE) + x - i;

		if (j < 0 || j >= SIZE * SIZE) {
			return 0;
		}

		r *= grid[((y + i) * SIZE) + x - i];
	}

	return r;
}

int main(int argc, char* argv[]) {
	int grid[SIZE * SIZE];
	int i, j, r, s;

	for(i = 0; i < SIZE; i++) {
		for(j = 0; j < SIZE; j++) {
			scanf("%d", &grid[(j * SIZE) + i]);
		}
	}

	for(i = 0; i < SIZE; i++) {
		for(j = 0; j < SIZE; j++) {
			printf("%d ", grid[(j * SIZE) + i]);
		}
		printf("\n");
	}

	r = 0;

	for(i = 0; i < SIZE; i++) {
		for(j = 0; j < SIZE; j++) {
			s = calc_down(i, j, grid);
			if (r < s) { r = s; }
			s = calc_right(i, j, grid);
			if (r < s) { r = s; }
			s = calc_rdiag(i, j, grid);
			if (r < s) { r = s; }
			s = calc_ldiag(i, j, grid);
			if (r < s) { r = s; }
		}
	}

	printf("%d\n", r);

	return 0;
}
