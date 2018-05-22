#include<stdio.h>
#include<cstring>
#include<iostream>
#include <climits>
#include <stdlib.h> 
using namespace std;
 
// Tree Node structure
struct node1
{
    int data;
    struct node1 *left, *right;
};
// Doubly Linked List Node Structure
struct node2{
     
    int data,level;
    struct node2 *nxt;
    struct node2 *prev;
};
 
typedef struct node1 tnode;
typedef struct node2 lnode;
  
 
// New Tree Node 
tnode* newTNode( int data)
{
    tnode* temp = (tnode *) malloc( sizeof(tnode) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
  
// New Linked List Node
lnode*  newLNode( int data , int level )
{
    lnode* temp = (lnode *) malloc( sizeof(lnode) );
    temp->data = data;
    temp->level=level;
    temp->nxt = temp->prev = NULL;
    return temp;
}
 
// Vertical sum routine 
void top_view(tnode * root , lnode* llnode , int level){
    if(!root)
    return ;
    // Add root's data to current linked list node
    if(level < llnode->level){
    llnode->data = root->data;
    llnode->level = level;
    }
     
    //If tree has left child 
    if(root->left){
        //If some node at this horizontal 
        //distance already occured , Simply pass 
        //Already created node
        if(llnode->prev){
            top_view(root->left, llnode->prev , level+1);
        }
        else{
        // Create new node before current node
        lnode* ltmp = newLNode(INT_MAX ,INT_MAX );
        ltmp->nxt = llnode;
        llnode->prev = ltmp;
        top_view(root->left,ltmp , level+1);
        }
    }
    // Do similar as above 
     if(root->right){
        if(llnode->nxt){
            top_view(root->right, llnode->nxt , level+1);
        }
        else{
        lnode* ltmp = newLNode(INT_MAX, INT_MAX);
        ltmp->prev = llnode;
        llnode->nxt = ltmp;
        top_view(root->right,ltmp , level+1);
        }
    }
}
 
  
int main(){
 
    tnode *root = newTNode(20);
    root->left = newTNode(8);
    root->left->left  = newTNode(4);
    root->left->right = newTNode(12);
    root->left->right->left  = newTNode(10);
    root->left->right->right = newTNode(14);
    root->right = newTNode(22);
    root->right->right = newTNode(25);
     
    lnode * llnode = newLNode(0 , 0);
    top_view(root, llnode , 0);
 
    lnode *head = llnode;
    // Find the head of the linked list 
    while(head->prev!=NULL)
        head= head->prev;
    // Print linked list 
    while(head){
        cout<<head->data<<"   ";
        head = head->nxt;
       }
return 0;
}
