#include<stdlib.h>
#include<stdio.h>

typedef struct node_s{
    int data;
    struct node_s *next;
    struct node_s *arbit;
} Node_s;

void free_list(Node_s * head){
    if(!head) return;
    Node_s * temp = head;
    Node_s * next = head;
    while(temp){
        next = temp->next;
        free(temp);
        temp = next;
    }
}
void push_1(Node_s **head, int value){
    if(*head == NULL){
        (*head) = (Node_s *)malloc(sizeof(Node_s));
        (*head)->data = value;
        (*head)->next = NULL;
    }
    else{
        Node_s * temp = (Node_s *)malloc(sizeof(Node_s));
        if(temp){
            temp->data = value;
            temp->next = (*head);
            *head = temp;
        }
    }
}
void add_arbit(Node_s *L1, int a, int b){

    Node_s * first = L1;
    Node_s * second = L1;

    while(first){
        if(first->data == a)
            break;
        first = first->next;
    }
    while(second){
        if(second->data == b)
            break;
        second = second->next;
    }
    if(first)
        first->arbit = second;
}

Node_s * create_node(int val){

    Node_s * temp =  (Node_s *)malloc(sizeof(Node_s));
    if(temp){
        temp->data = val;
        temp->next = NULL;
    }
    return temp;
}

Node_s * clone(Node_s * node){

    if(!node) return NULL;
    Node_s * current = node;

    //First insert clone nodes in original linked list.     
    while(current){
        Node_s * current_next = current->next;
        current->next  =  create_node(current->data);
        current->next->next = current_next;
        current = current_next;
    }
    current = node;
    
    //Now copy arbit pointer of each node to cloned list
    Node_s * clone_head  = current->next;
    while(current){
        Node_s * clone = current->next;
        if(current->arbit){
            clone->arbit    = current->arbit->next;
        }
        current = clone->next;
    }

    current = node;
    
    //Segregate two linked list
    while(current){
        Node_s * clone  = current->next;
        current->next = clone->next;
        if(clone->next){
            clone->next = clone->next->next;
        }
        current = current->next;
    }
    //return head pointer to the calling function
    return clone_head;
}
int main(){
    Node_s * L1 = NULL;
    push_1(&L1,1);
    push_1(&L1,2);
    push_1(&L1,3);
    push_1(&L1,4);
    push_1(&L1,5);
    push_1(&L1,6);

    add_arbit(L1,1,6);
    add_arbit(L1,2,5);
    add_arbit(L1,3,1);
    add_arbit(L1,4,2);
    add_arbit(L1,5,4);
    add_arbit(L1,6,3);

    print_list_1(L1);
    
    Node_s *clone_head  = clone(L1);
    free_list(L1);
    print_list_1(clone_head);

    return 0;     
}
