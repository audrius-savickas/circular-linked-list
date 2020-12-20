#ifndef __FUNC_H_
#define __FUNC_H_

struct Node {
    int data;
    struct Node* next;
};
void createList (struct Node** head, int value);
void printList (struct Node* head);
void addToBeginning (struct Node** head, int value);
void deleteList (struct Node **head);

#endif
