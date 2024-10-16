#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};


void Traversal(struct node* head){
    struct node* ptr = head;

    do{
        printf("Elemenet is: %d\n",ptr->data);
        ptr = ptr->next;
    }
    while(ptr != head);
}

struct node* InsertAtFirst(struct node* head, int data){
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = data;

    struct node* p = head->next;
    while(p->next != head){
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;

    printf("\nInsertion at start completed!\n");
    return head;
}

struct node* DeleteAtFirst(struct node* head){
    struct node* ptr = head->next;
    struct node* p = head->next;

    while(p->next != head){
        p = p->next;
    }

    p->next = ptr;
    head = ptr;

    printf("\nDeletion at start Completed!\n");
    return head;
}

int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *) malloc(sizeof(struct node));
    second = (struct node *) malloc(sizeof(struct node));
    third = (struct node *) malloc(sizeof(struct node));
    fourth = (struct node *) malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;
    
    second->data = 11;
    second->next = third;

    third->data = 66;
    third->next = fourth;

    fourth->data = 74;
    fourth->next = head;
    
    Traversal(head);

    head = InsertAtFirst(head, 4);
    Traversal(head);

    head = DeleteAtFirst(head);
    Traversal(head);

    return 0;
}