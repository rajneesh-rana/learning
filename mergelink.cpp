#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}Node;

void printList(Node * head);

void split(Node *head, Node **front, Node **back)
{
#if 0    
  Node *fast = head->next;
  Node *slow = head;
    
  while(fast){
    fast = fast->next;
    if(fast){
      fast = fast->next;
      slow = slow->next;
    }
  }
  *front = head; 
  *back = slow->next;
  slow->next = NULL;
#else  
    Node *fast=head->next;
    Node *slow=head;
    while(fast)
    {
        fast=fast->next;
        if(fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
    }
    *front=head;
    *back=slow->next;
    slow->next=NULL;
#endif 
}

Node * merge(Node *a, Node *b){
 Node *result = NULL;
 if(a ==  NULL)
   return b;
 else if(b == NULL)
    return a;
 
 /* For the first node, we would set the result to either a or b */
  if(a->data <= b->data){
    result = a;
    /* Result's next will point to smaller one in lists 
    starting at a->next  and b */
    result->next = merge(a->next,b);
   }
   else {
    result = b;
    /*Result's next will point to smaller one in lists 
    starting at a and b->next */
    result->next = merge(a,b->next);
   }
   return result;
}

void mergeSort(Node **headRef)
{
  Node * front, *back;
  Node * head  = *headRef;
  if(head == NULL || head->next == NULL)
    return;
  printf("\n Original list:");
  printList(head);  
  split(head, &front, &back);

  printf("\n Splitted parts :\n");
  printList(front);
  printf("\n");
  printList(back);
  mergeSort(&front);
  mergeSort(&back);
  *headRef = merge(front, back);
  printf("\n After Merging:\n");
  printList(*headRef);
}

void push(Node **headRef, int data){
  Node * new_node  = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = *headRef;
  *headRef  = new_node;
}

void printList(Node * head){
  Node * current = head;
  while(current){
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL");
}
int main(void) {
    // your code goes here
  Node *head = NULL;
  Node *front, *back;
  push(&head,5);
  push(&head,8);
  push(&head,7);
  push(&head,3);
  push(&head,1);
  mergeSort(&head);
  printf("\n");
  printList(head);
  return 0;
}

