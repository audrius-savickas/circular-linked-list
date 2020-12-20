#ifndef __FUNC_H_
#define __FUNC_H_

struct Node {
    int data;
    struct Node* next;
};
void printList(struct Node* n);
void push(struct Node** head_ref, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void append(struct Node** head_ref, int new_data);

#endif
