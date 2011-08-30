#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

#include "list.h"

int main(int argc, char* argv[]) {
	list_t l;
	node_t n;
	mpz_t m;
	int a;
	int b;
	int i;

	l = create_list();

	for (a = 2; a <= 100; a++) {
		for (b = 2; b <= 100; b++) {
			i++;
			mpz_init(m);
			mpz_set_ui(m, a);
			mpz_pow_ui(m, m, b);
			insert_node(l, create_node(m));
			mpz_clear(m);
		}
	}

	i = 0;
	n = l->first;
	while(n != NULL) {
		n = n->next;
		i++;
	}

	printf("%d\n", i);

	destroy_list(l);

	return 0;
}
