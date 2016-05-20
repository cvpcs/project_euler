#include "list.h"

node_t create_node(mpz_t v) {
	node_t n = (node_t)malloc(sizeof(struct node));
	n->prev = NULL;
	n->next = NULL;
	mpz_init(n->val);
	mpz_set(n->val, v);
	return n;
}

void destroy_node(node_t n) {
	mpz_clear(n->val);
	n->prev = NULL;
	n->next = NULL;
	free(n);
}

list_t create_list() {
	list_t l = (list_t)malloc(sizeof(struct list));
	l->first = NULL;
	l->last = NULL;
	return l;
}

void destroy_list(list_t l) {
	node_t n = l->first;
	node_t m;

	while(n != NULL) {
		m = n->next;
		destroy_node(n);
		n = m;
	}

	free(l);
}

void insert_node(list_t l, node_t n) {
	node_t m;

	if (l->first == NULL) {
		l->first = n;
		l->last = n;
	} else {
		if (mpz_cmp(n->val, l->first->val) < 0) {
			n->next = l->first;
			l->first->prev = n;
			l->first = n;
		} else {
			m = l->first;

			while(m != NULL && mpz_cmp(m->val, n->val) < 0) {
				m = m->next;
			}

			if (m == NULL) {
				l->last->next = n;
				n->prev = l->last;
				l->last = n;
			} else {
				if (mpz_cmp(m->val, n->val) != 0) {
					n->next = m;
					n->prev = m->prev;
					m->prev->next = n;
					m->prev = n;
				}
			}
		}
	}
}
