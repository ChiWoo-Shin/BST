#include "BST_h.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Node_list* New_First_Node(void){
    Node_list* startNode=malloc(sizeof(Node_list));
    startNode->root=NULL;
    startNode->nil=NULL;
    return startNode;
}
// 노드 삽입
Node_t *BST_insert(Node_list* node_l, const key_t key){
    Node_t* Node_info=node_l;
    Node_t* New_Node=malloc(sizeof(Node_t));
    Node_t* parent=NULL;
    New_Node->key=key;
    New_Node->left=New_Node->right=NULL;
    if (node_l->root==NULL){
        node_l->root=key;
        Node_info=New_Node;
        return Node_info;
    }
    else{
        while(Node_info!=NULL){
            parent=Node_info;
            if(Node_info->key==key){
                printf("%d 는 이미 있습니다.\n",key);
                return Node_info;
            }
            else if(Node_info->key<key){
                Node_info=Node_info->right;
            }
            else{
                Node_info=Node_info->left;
            }
        }
    }
    if(parent!=NULL){
        if(parent->key < New_Node->key){
            parent->right=New_Node;
        }
        else
            parent->left=New_Node;
    }
    return Node_info;
}
// 노드 찾기
Node_t* BST_search(Node_list* node_l, const key_t find_key){
    Node_t *p=node_l;
    while(p!=NULL){
        if(p->key==find_key){
            printf("\n%d 는 있습니다.\n",find_key);
            return p;
        }
        else if(p->key<find_key){
            p=p->right;
        }
        else{
            p=p->left;
        }
    }
    printf("\n찾는 key가 없습니다\n");
    return p;
}
//노드 프린트
void print_BST(Node_list* node_l){
    Node_t* print_node=node_l;
    if (print_node){
        print_BST(print_node->left);
        printf("%d ",print_node->key);
        print_BST(print_node->right);
    }
}

//노드 삭제

Node_t *BST_delete(Node_list* node_l, const key_t key){
    Node_t* Node_info=node_l;
    Node_t* parent=NULL;
    Node_t* child=NULL; // 삭제할 노드가 차수가 1인 것을 선언
    Node_t* parent_2=NULL; // 삭제할 노드가 차수가 2인 것의 부모를 선언
    Node_t* child_2=NULL; // 삭제할 노드가 차수가 2인 것을 선언

    while((Node_info!=NULL)&& (Node_info->key!=key)){ // 해당 노드가 있는지 있다면 어디있는지 먼저 탐색 ㄱㄱ
        parent=Node_info;        
        if(Node_info->key<key){
            Node_info=Node_info->right;
        }
        else{
            Node_info=Node_info->left;
        }
    }
    
    if (Node_info==NULL){ // 위 과정을 거치고 나왔는데 Null이면 없다는 얘기
        printf("\n삭제할 key가 존재하지 않습니다.\n");
        return node_l;
    }

    // 차수가 0인 Node == child가 없다
    if (Node_info->right==NULL && Node_info->left==NULL){
        if(parent==NULL){
            Node_info=NULL;
            printf("\n root : %d 가 삭제되었습니다.\n",key);
            }
        else{
            if(parent->left==Node_info){
                parent->left=NULL;
                printf("\n 0차수 : %d가 삭제되었습니다. \n",key);
                }
            else{
                parent->right=NULL;
                printf("\n 0차수 : %d가 삭제되었습니다. \n",key);
                }
        }
    }

    // 차수가 1인 Node == child 가 1인 Node
    else if (Node_info->right==NULL || Node_info->left==NULL){
        if (Node_info->left !=NULL) // Node가 왼쪽 자식만 갖고 있으면
            child=(Node_info->left); // child는 왼쪽자식
        else
            child=(Node_info->right);

        if (parent==NULL){
            Node_info=child;
            printf(" \n1차수 : %d가 삭제되었습니다. \n",key);
            }
        else{
            if (parent->right !=NULL){
                parent->right=child;
                printf(" \n1차수 : %d가 삭제되었습니다. \n",key);
                }
            else{
                parent->left=child;
                printf(" \n1차수 : %d가 삭제되었습니다. \n",key);
                }
        }
    }

    // 차수가 2인 Node
    else{
        parent_2=Node_info; // Node_info의 정보를 부모에 너놓고
        child_2=Node_info->left; // 왼쪽 child를 child_2에 넣고 시작 (왼쪽 tree의 최대값을 찾는다)
        while(child_2->right!=NULL){ // 오른쪽이 NULL이 아니면
            parent_2=child_2; // 현재 child정보를 parent에 넣고
            child_2=child_2->right; // child를 한칸 더 진행
        }
        Node_info->key=child_2->key; // child 가 갖고 있는 키 값을 지우려는 Node에 있는 키에 복사해줌
        // 끝에 도달하면 부모와 자식간의 link를 끊어야함 -- 그 부분을 NULL로 만들어줘야함
        // 그 작업을 하는 부분 -- 이 작업은 오른쪽 끝에 도달했다는 확신을 갖고 진행
        if (parent_2->left=child_2){ // 오른쪽 끝에 도달했을때
            parent_2->left=child_2->left; // child의 왼쪽 자식 값을 부모에게 이어줌(오른쪽 자식은 연결이 끊길거니깐)
            printf(" \n2차수 : %d가 삭제되었습니다. \n",key);
            }
        else{
            parent_2->right=child_2->right; // 그게 아니라면 자신의 오른쪽 자식을 줌
            printf(" \n2차수 : %d가 삭제되었습니다. \n",key);
            }
        
        Node_info=child_2;
    }
    free(Node_info); // 마지막 child를 비움
    return node_l; // 수정된 node_l을 리턴함
}

