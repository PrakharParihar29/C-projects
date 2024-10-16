#include<stdio.h>
#include<stdlib.h>
  
struct node{
    int data;
    struct node *next; 
};
// for print the link list
void LinkedListTraversal(struct node *ptr){
    printf("Elements of linked list\n");
    while (ptr != 0){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
    
}
// Delete node at start
struct node* DeleteAtStart(struct node*  head){
    struct node* ptr = head;
    head = head->next;
    free(ptr);
    printf("\nFirst element deleted!\n");

    return head;
}
// Delete node at given index
struct node* DeleteAtindex(struct node* head, int index){
    struct node* p = head;
    struct node* q = head->next;
    
    for(int i=0; i< index-1; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    printf("\nelement at given index deleted!\n");
    return head;
}
// Delete end node
struct node* DeleteAtEnd(struct node* head){
    struct node* p = head;
    struct node* q = p->next;
    
    while( q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next  = NULL;
    free(q);

    printf("\nelement at end deleted!\n");
    return head;
}
// Delete node with given value
struct node* DeleteAtValue(struct node* head, int value) {
    struct node* p = head;
    struct node* q = head->next;

    if (head->data == value) {
        head = head->next;
        free(p);
        printf("\nElement with value %d deleted!\n", value);
        return head;
    }

    while (q != NULL) {
        if (q->data == value) {
            p->next = q->next;
            free(q);
            printf("\nElement with value %d deleted!\n", value);
            return head;
        }
        p = p->next;
        q = q->next;
    }

    printf("\nElement with value %d not found!\n", value);
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
    fourth->next = NULL;
    
    LinkedListTraversal(head);

    // head = DeleteAtStart(head);
    // LinkedListTraversal(head);

    // head = DeleteAtindex(head,1);
    // LinkedListTraversal(head);

    // head = DeleteAtEnd(head);
    // LinkedListTraversal(head);

    head = DeleteAtValue(head,11);
    LinkedListTraversal(head);

return 0;
}