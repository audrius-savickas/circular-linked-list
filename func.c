#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void createList (struct Node** head, int value) {
    *head = (struct Node*) malloc(sizeof(struct Node));
    (*head)->data = value;
    (*head)->next = *head;

    return; 
}
void addToBeginning (struct Node** head, int value) {
    struct Node* x = *head;
    struct Node* y = (struct Node*)malloc (sizeof(struct Node));
    y->data = value;

    while (x->next != *head) {
        x = x->next;
    }
    x->next = y;
    y->next = *head;
    *head = y;

    return;
}
void printList (struct Node* head) {
    struct Node* current;
    current = head;
    while (current->next != head) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d ", current->data);
    printf("\n");

    return;
}

void deleteList (struct Node **head) {
    struct Node* current = *head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
        if (current->next == *head) {
            free(current);
            current = NULL;
        }
    }
    *head = NULL;
    return;
}
