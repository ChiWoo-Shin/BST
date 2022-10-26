#ifndef _BST_H_
#define _BST_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef int key_t;

typedef struct Node_t // Node structure 만들기
{
    key_t key; // 값    
    struct Node_t *left,*right; // 주소가 연결될 곳
}Node_t;

typedef struct Node_list
{
    Node_t *root;
    Node_t *nil;
}Node_list;

Node_list *New_First_Node(void);
Node_t *BST_insert(Node_list* , const key_t);
Node_t *BST_delete(Node_list*, const key_t);
Node_t* BST_search(Node_list*, const key_t);
void print_BST(Node_list*);

// Node_t* BST_find(Node_list* node_l, int val);
// void appendNode(Node_list* node_l, int value);
// void print_list(Node_list* node_l);
// int pop(Node_list* node_l);
// void find_node(Node_list* node_l, int value);
// void delete_node(Node_list* node_l, int value);
// Node_t* appendNode(Node_list* node_l, int value);
// Node_t* deleteNode_First(Node_list* node_l);
// Node_t* delete_data(Node_list* node_l, int value);

#endif
