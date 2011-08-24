#include <stdio.h>
#include <stdlib.h>

#define SIZE 1001
#define LOC(x, y) ((y * SIZE) + x)

int* gen_spiral() {
	int* spiral = (int*)malloc(SIZE * SIZE * sizeof(int));
	int x, y;
	int i, j, k;
	int d;

	// clear out the spiral
	for (i = 0; i < SIZE * SIZE; i++) {
		spiral[i] = 0;
	}

	x = ((SIZE / 2) + (SIZE % 2)) - 1;
	y = ((SIZE / 2) + (SIZE % 2)) - 1;

	// d:
	// 0 = right
	// 1 = down
	// 2 = left
	// 3 = up
	d = 0;

	j = 1;
	i = j;
	k = 1;
	while(x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
		spiral[LOC(x, y)] = k++;

		if (i-- == 0) {
			d = (d + 1) % 4;
			if (d % 2 == 0) {
				j++;
			}
			i = j - 1;
		}

		switch(d) {
			case 0:
				x++;
				break;
			case 1:
				y++;
				break;
			case 2:
				x--;
				break;
			case 3:
				y--;
				break;
		}
	}

	return spiral;
}

void print_spiral(int* spiral) {
	int x, y;

	for(y = 0; y < SIZE; y++) {
		for(x = 0; x < SIZE; x++) {
			printf("%d\t", spiral[LOC(x, y)]);
		}
		printf("\n");
	}
}

int sum_spiral_diags(int* spiral) {
	int i;
	int c = 0;
	for(i = 0; i < SIZE; i++) {
		c += spiral[LOC(i, i)];
		if (i != (SIZE - 1 - i)) {
			c += spiral[LOC((SIZE - 1 - i), i)];
		}
	}
	return c;
}

int main(int argc, char* argv[]) {
	int* spiral = gen_spiral();
//	print_spiral(spiral);
	printf("Diag sum: %d\n", sum_spiral_diags(spiral));
	free(spiral);
	return 0;
}
