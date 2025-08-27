#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head=NULL;

struct Node* insert_beg(struct Node* head,int data){
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=NULL;

    if (head==NULL){
        return new_node;
    }

    new_node->next=head;
    head=new_node;
    return head;
}

struct Node* insert_end(struct Node* head,int data){
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=NULL;

    if (head==NULL){
        return new_node;
    }

    struct Node* temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    return head;
}

struct Node* delete_beg(struct Node* head){

    if (head==NULL){
        printf("List is empty\n");
        return NULL;
    }

    if(head->next==NULL){
        printf("Deleted element is %d\n",head->data);
        free(head);
        return NULL;
    }

    struct Node* temp=head;
    head=head->next;
    printf("Deleted element is %d\n",temp->data);
    free(temp);
    return head;
    
}

struct Node* delete_end(struct Node* head){
    if (head==NULL){
        printf("List is empty\n");
        return NULL;
    }
    if(head->next==NULL){
        printf("Deleted element is %d\n",head->data);
        free(head);
        return NULL;
    }

    struct Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    printf("Deleted element is %d\n",temp->next->data);
    free(temp->next);
    temp->next=NULL;
    return head;
}

void display(struct Node* head){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp=head;
    while (temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    head=insert_beg(head,10);
    head=insert_beg(head,20);
    head=insert_end(head,30);
    head=insert_end(head,40);
    display(head);
    head=delete_beg(head);
    display(head);
    head=delete_end(head);
    display(head);
    return 0;
}