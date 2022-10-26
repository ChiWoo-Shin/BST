#include "BST_h.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Node_list* node_l=New_First_Node();
    BST_insert(node_l,30);
    BST_insert(node_l,40);
    BST_insert(node_l,20);
    BST_insert(node_l,60);
    BST_insert(node_l,10);
    BST_insert(node_l,70);
    BST_insert(node_l,50);
    BST_insert(node_l,90);
    print_BST(node_l);
    BST_search(node_l,20);
    BST_search(node_l,30);
    BST_search(node_l,110);
    BST_search(node_l,120);
    print_BST(node_l);
    node_l=BST_delete(node_l, 30);
    print_BST(node_l);
    node_l=BST_delete(node_l, 50);
    print_BST(node_l);
    node_l=BST_delete(node_l,100);
    node_l=BST_delete(node_l,110);
    print_BST(node_l);
}
