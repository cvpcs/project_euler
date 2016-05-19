#include "tree.h"

node_t* create_node(unsigned long num) {
	node_t* n = (node_t*)malloc(sizeof(node_t));
	n->num = num;
	n->seq = 0;
	n->next = NULL;
	return n;
}

void destroy_node(node_t* n) {
	free(n);
}

tree_t* create_tree(unsigned long size) {
	tree_t* t;
	node_t* n;
	node_t** l;
	unsigned long i;
	unsigned long j;
	unsigned long k;

	t = (tree_t*)malloc(sizeof(tree_t));
	t->num_nodes = size;
	t->num_extra = 0;
	t->extra = (node_t**)malloc(sizeof(node_t*));
	t->nodes = (node_t**)malloc(sizeof(node_t*) * size);

	for (i = 0; i < size; i++) {
		t->nodes[i] = create_node(i);
	}

	for (i = 1; i < size; i++) {
		n = t->nodes[i];

		j = i;

		while (j != 1 && n->next == NULL) {
			j = (j % 2 == 0 ? j / 2 : 3 * j + 1);

			if (j < size) {
				n->next = t->nodes[j];
			} else {
				l = (node_t**)malloc(sizeof(node_t*) * (t->num_extra + 1));
				for (k = 0; k < t->num_extra; k++) {
					l[k] = t->extra[k];
				}
				l[k] = create_node(j);
				free(t->extra);
				t->extra = l;
				l = NULL;
				
				n->next = t->extra[k];
			
			}

			n = n->next;
		}
	}

	return t;
}

void destroy_tree(tree_t* t) {
	unsigned long i;

	for (i = 0; i < t->num_nodes; i++) {
		destroy_node(t->nodes[i]);
	}

	if (t->num_extra > 0) {
		for (i = 0; i < t->num_extra; i++) {
			destroy_node(t->extra[i]);
		}
		free(t->extra);
	}

	free(t->nodes);
	free(t);
}

unsigned long get_seq_len(node_t* n) {
	node_t* m;
	unsigned long i;

	if (n->seq > 0) {
		return n->seq;
	}

	m = n;
	i = 0;
	while (m) {
		if (m->seq > 0) {
			i += m->seq;
			break;
		} else {
			m = m->next;
			i++;
		}
	}
	n->seq = i;

	return i;
}
