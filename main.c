#include <stdio.h>
#include <stdlib.h>
#include "./includes/tree.h"

int
main()
{
    struct tree *tree = create_tree();  
    insert(tree, 444);
    insert(tree, 666);
    insert(tree, 100);
    insert(tree, 200);
    insert(tree, 5);
    insert(tree, 20); 
    pre_order(tree);
    printf("\n");
    pos_order(tree);
    printf("\n");
    in_order(tree); 
    printf("\n");
    printf("Tree Depth: %d\n", depth(tree));
    remove_leaf(tree, 5); 
    pre_order(tree);
    printf("\n");
    pos_order(tree);
    printf("\n");
    in_order(tree);
    printf("\n");
    printf("Tree Depth: %d\n", depth(tree));
}
