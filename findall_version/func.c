#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void createList (struct Node** head) {
    *head = NULL;
    return; 
}
void addToBeginning (struct Node** head, int value) {
    if ((*head) == NULL) {
        (*head) = (struct Node*)malloc (sizeof(struct Node));
        (*head)->data = value;
        (*head)->next = *head;
        return;
    }
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

    //while next node is not head node
    while (current->next != head) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d ", current->data);
    printf("\n");

    return;
}

void deleteList (struct Node **head) {
    struct Node* current = (*head)->next; //curr node is the one after head
    struct Node* next = NULL;
    
    //while current node is not head node, free the node
    while (*head != current) {
        next = current->next;
        free(current);
        current = next;
    }
    //free head node
    free(*head);
    *head=NULL;
    return;
}

int deleteNodeFromList (struct Node** head, int value) {
    struct Node* current = *head;
    struct Node* previous = NULL;
    struct Node* next = NULL;
    int node_found = 0; //bool to check if at least one matching node was found

    //delete nodes until all found
    while (*head != NULL) {
        //find required node with the value
        while (current->data != value) {
            //if required node not found return from function
            if (current->next == *head) {
                //return 0 if not a single node was found
                if (!node_found) {
                    return 0;
                }
                //return 1 if at least one node was found
                return 1;
            }
            previous = current;
            current = current->next;
        }
        next = current->next;

        //check if found node is only node
        if (current == *head && current->next == *head) {
            *head = NULL;
            free(current);
            return 1;
        }

        //if more than one node, check if found node is first node
        else if (current == *head) {
            previous = *head;
            while (previous->next != *head) {
                previous = previous->next;
            }
            *head = current->next;
            previous->next = *head;
            free(current);
        }

        //check if found node is last node
        else if (current->next == *head) {
            previous->next = *head;
            free(current);
        }

        else {
            previous->next = current->next;
            free(current);
        }
        node_found = 1;
        current = next;
    }
    return 1;
}
