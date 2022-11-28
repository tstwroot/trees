#include "../includes/tree.h"
#include <alloca.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct leaf
{
    int value;
    struct leaf *left, *right;
};

struct tree
{
    int depth;
    struct leaf *root;
};

struct tree*
create_tree()
{
    struct tree *tree = (struct tree*)calloc(1, sizeof(struct tree));
    tree->depth = 0;
    tree->root = NULL;
    return tree;
}

struct leaf*
create_leaf(int value)
{
    struct leaf *new_leaf = (struct leaf*)calloc(1, sizeof(struct leaf));
    new_leaf->value = value;
    new_leaf->left = NULL;
    new_leaf->right = NULL;
    return new_leaf;
}

/*
  *  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
  *  PRE-ORDER
  *  (1) - EXECUTE THE ALGORITHM
  *  (2) - CHECK IF EXIST NODE ON THE LEFT
  *  (3) - CHECK IF EXIST NODE ON THE RIGHT
  *  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  *  POS-ORDER
  *  (1) - CHECK IF EXIST NODE ON THE LEFT
  *  (2) - CHECK IF EXIST NODE ON THE RIGHT
  *  (3) - EXECUTE THE ALGORITHM
  *  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  *  IN-ORDER
  *  (1) - CHECK IF EXIST NODE ON THE LEFT
  *  (2) - EXECUTE THE ALGORITHM
  *  (3) - CHECK IF EXIST NODE ON THE RIGHT
  *  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/

void aux_pre(struct leaf *leaf)
{
    if(leaf != NULL)
    {
        printf("%d ", leaf->value);
        aux_pre(leaf->left);
        aux_pre(leaf->right);
    }
    return;
}

void
pre_order(struct tree *tree)
{
    if(is_empty(tree))
    {
        return;
    }
    aux_pre(tree->root);
}

void aux_pos(struct leaf *leaf)
{
  if(leaf != NULL)
  {
    aux_pos(leaf->left);
    aux_pos(leaf->right);
    printf("%d ", leaf->value);
  }
  return;
}

void pos_order(struct tree *tree)
{
  if(is_empty(tree))  
  {
    return;
  }
  aux_pos(tree->root);
}

void aux_in(struct leaf *leaf)
{
  if(leaf != NULL)
  {
    aux_in(leaf->left);
    printf("%d ", leaf->value);
    aux_in(leaf->right);
  }
  return;
}

void in_order(struct tree *tree)
{
  if(is_empty(tree))
  {
    return;
  }
  aux_in(tree->root);
}

// Check if the tree is empty.
bool
is_empty(struct tree *_tree)
{
    return _tree->root == NULL;
}

int getDepth(struct leaf *leaf)
{
  if(leaf == NULL)
  {
    return -1;
  }
  else
  {
    int l = getDepth(leaf->left);
    int r = getDepth(leaf->right);
    if(l > r)
    {
      return l + 1;
    }
    else
    {
      return r + 1;
    }
  }
}

void
add(struct leaf *leaf, int value)
{
    struct leaf* new_leaf = create_leaf(value);

    if(leaf->value > value)
    {
        if(leaf->left == NULL)
        {
            leaf->left = new_leaf;
            return;
        }
        else
        {
            add(leaf->left, value);
        }
    }
    else
    {
        if(leaf->right == NULL)
        {
            leaf->right = new_leaf;
            return;
        }
        else
        {
            add(leaf->right, value);
        }
    }
    return;
}

void
insert(struct tree *tree, int value)
{
    if(is_empty(tree))
    {
        tree->root = create_leaf(value);
        return;
    }
    add(tree->root, value);
    tree->depth = getDepth(tree->root);
}

struct leaf *remove_aux(struct leaf *leaf, int value)
{
  if(leaf != NULL)
  {
    if(leaf->value == value) 
    {
      if(leaf->left == NULL && leaf->right == NULL) 
      {
        free(leaf);
        leaf = NULL;
      }
      else
      {
        if(leaf->left != NULL && leaf->right != NULL)
        {
          int r = rand() % 2;
          if(r == 1)
          {
            struct leaf *aux = leaf->left;
            while(aux->right != NULL)
            {
              aux = aux->right;
            }
            leaf->value = aux->value;
            aux->value = value;
            leaf->left = remove_aux(leaf->left, value);
            return leaf;
          }
          else
          {
            struct leaf *aux = leaf->right;
            while(aux->left != NULL)
            {
              aux = aux->left;
            }
            leaf->value = aux->value;
            aux->value = value;
            leaf->right = remove_aux(leaf->right, value);
            return leaf;
          }
         
        }
        else
        {
          struct leaf *aux;
          if(leaf->left != NULL)
          {
            aux = leaf->left;
          }
          else
          {
            aux = leaf->right;
          }
          free(leaf);
          return aux;
        }
      }
    }
    else
    {
      if(leaf->value > value)
      {
        leaf->left = remove_aux(leaf->left, value);
      }
      else
      {
        leaf->right = remove_aux(leaf->right, value);
      }
      return leaf;
    }
  }
  return (struct leaf*)NULL;
}

void remove_leaf(struct tree *tree, int value)
{
  if(is_empty(tree))
  {
    return;
  }
  remove_aux(tree->root, value);
  tree->depth = getDepth(tree->root);
}

int depth(struct tree *tree)
{
  return tree->depth;
}
