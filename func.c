#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void createList (struct Node** head, int value) {
    *head = (struct Node*) malloc(sizeof(struct Node));
    (*head)->data = value;
    (*head)->next = *head;

    return; 
}
void deleteNodeFromList (struct Node* head, int value) {
    struct Node* current = head;
    struct Node* previous = NULL;
    int bool_not_found = 0;
    //find required node with the value
    while (current->data != value || bool_not_found) {
        if (current->next == head) {
            printf("Given node is not in the list.\n");
            bool_not_found = 1;
            return;
        }
        if (!bool_not_found) {
            previous = current;
            current = current->next;
        }
    }

    //check if found node is only node
    if (current->next == head) {
        head = NULL;
        free(current);
    }

    //if more than one node, check if found node is first node
    else if (current==head) {
        previous = head;
        while (previous->next != head) {
            previous = previous->next;
        }
        head = current->next;
        previous->next = head;
        free(current);
    }

    //check if found node is last node
    else if (current->next == head && current == head) {
        previous->next = head;
        free(current);
    }

    else {
        previous->next = current->next;
        free(current);
    }
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
