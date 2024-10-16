#include<stdio.h>
#include<stdlib.h>
  
struct node{
    int data;
    struct node *next; 
};

// for Print of linked list.
void LinkedListTraversal(struct node *ptr){
    printf("Elements of linked list are:\n");
    while (ptr != 0){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
    
}

struct node * InsertAtStart(struct node* head, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    printf("\nInsertion at the begining completed!\n");
    return ptr;
}

struct node * InsertAtIndex(struct node* head, int data, int index){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    struct node * p = head;
    int i = 0;

    while (i != (index-1)){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    printf("\nInsertion at the given index completed!\n");

    return head;
}

struct node * InsertAtEnd(struct node* head, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    struct node * p = head;

    while (p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    printf("\nInsertion at the end completed!\n");

    return head;
}

struct node* InsertAfterNode(struct node* head, struct node* prev, int data){
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prev->next;
    prev->next = ptr;
    printf("\nInsertion after node is completed!\n");
    return head;
}

int main(){
    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node *) malloc(sizeof(struct node));
    second = (struct node *) malloc(sizeof(struct node));
    third = (struct node *) malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;
    
    second->data = 11;
    second->next = third;

    third->data = 66;
    third->next = NULL;
    
    LinkedListTraversal(head);

    head = InsertAtStart(head, 56);
    LinkedListTraversal(head);

    head = InsertAtIndex(head, 65, 2);
    LinkedListTraversal(head);
    
    head = InsertAtEnd(head, 99);
    LinkedListTraversal(head);

    head = InsertAfterNode(head, second, 27);
    LinkedListTraversal(head);

    return 0;
}