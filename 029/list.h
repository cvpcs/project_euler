#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>
#include <gmp.h>

typedef struct node * node_t;
struct node {
	mpz_t val;
	node_t prev;
	node_t next;
};

typedef struct list * list_t;
struct list {
	node_t first;
	node_t last;
};

node_t create_node(mpz_t);
void destroy_node(node_t);

list_t create_list();
void destroy_list(list_t);

void insert_node(list_t, node_t);

#endif//__LIST_H__
