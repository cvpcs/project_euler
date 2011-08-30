#ifndef __TREE_H__
#define __TREE_H__

#include <stdlib.h>

typedef struct node node_t;
struct node {
	unsigned long num;
	unsigned long seq;
	node_t* next;
};

node_t* create_node(unsigned long num);
void destroy_node(node_t* n);

typedef struct tree tree_t;
struct tree {
	unsigned long num_nodes;
	node_t** nodes;
	unsigned long num_extra;
	node_t** extra;
};

tree_t* create_tree(unsigned long size);
void destroy_tree(tree_t* t);

unsigned long get_seq_len(node_t* n);

#endif//__TREE_H__
