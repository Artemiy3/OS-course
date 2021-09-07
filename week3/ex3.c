#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;

void print_list(Node *head){
    Node *p = head;
    while(p != NULL){
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

void insert_node(Node *head, int value_to_insert, int previous_value){
    Node *temp = head;
    while(temp->next != NULL && temp->value != previous_value){
        temp = temp->next;
    }
    Node* new_node = malloc(sizeof(struct Node));
        new_node->value = value_to_insert;
        new_node->next = temp->next;
        temp->next = new_node;
}

void delete_node(Node *head, int value){
    Node *prev = head;
    Node *next = prev->next;
    while(next != NULL && next->value != value){
        prev = next;
        next = next->next;
    }
    if(next != NULL){
        prev->next = next->next;
    }
}

int main() {
    Node *head = malloc(sizeof(struct Node));
    head->value = 1;
    head->next = NULL;
    insert_node(head, 5, 1);
    insert_node(head, 3,5);
    insert_node(head, 8, 5);
    print_list(head);
    delete_node(head, 5);
    print_list(head);
    return 0;
}
