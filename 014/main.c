#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

int main(int argc, char* argv[]) {
	tree_t* t;
	unsigned long i;
	unsigned long j;
	unsigned long k;
	unsigned long l;

	t = create_tree(1000000);

	k = 0;
	for (i = 0; i < 1000000; i++) {
		j = get_seq_len(t->nodes[i]);

		if (j > k) {
			k = j;
			l = i;
		}
	}

	printf("%lu: %lu\n", l, k);

	destroy_tree(t);
}
