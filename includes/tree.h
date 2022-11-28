#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

struct tree;
struct leaf;

struct tree *create_tree();
struct leaf *create_leaf(int);
void destroy(struct tree *);
bool is_empty(struct tree *);
void insert(struct tree *, int);
void pre_order(struct tree *);
void in_order(struct tree *);
void pos_order(struct tree *);

#endif
