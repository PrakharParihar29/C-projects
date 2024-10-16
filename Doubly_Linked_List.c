#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};


void Traversal(struct node* head){
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr = head;

    while(ptr != NULL){
        printf("Element is: %d\n",ptr->data);
        ptr = ptr->next;
    }
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

    head->prev = NULL;
    head->data = 7;
    head->next = second;

    second->prev = head;
    second->data = 11;
    second->next = third;

    third->prev = second;
    third->data = 66;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 74;
    fourth->next = NULL;
    
    Traversal(head);

    return 0;
}