/* Audrius Savickas 4gr 1pogr 4 uzduotis 18 uzdavinys

n18.Sudaryti ciklinį vienpusį sąrašą. Parašyti procedūrą, kuri išmeta
 reikšme nurodytą elementą. Jeigu tokio elemento nėra, turi būti išvestas
 atitinkamas pranešimas.
 1. inclue *.h, o ne *.c
2. inicializacimas reiškia tiesiog NULL nustatymas, o ne pirmo nario įdėjimas
3. Jei yra dvipusis sąrašas, yra būtinos šios komandos: įdėti_į_priekį, įdėti
_į_galą, atspausdinti_iš_priekio, atspausdinti_iš_galo
4. Main'e turi būti while su duomenų įterpimu (ir paklausimu ar iš priekio ar
 iš galo dll atveju)
5. Atspausdinimas
6. Tiklsinės funkcijos paleidimas pagal užduotį
7. atspausdinimas
8. sunaikinimas
*/

#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void deleteNodeFromList (struct Node** head, int value);

int main() {
    struct Node* head = NULL;
    int choice = 0;
    int value;
    int bool_created = 0;
    
    while (choice != 2) {
        printf("Enter 1 if you want to insert a node at the start of the list.\n");
        printf("Enter 2 if you want to remove a value from the list.\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Which value would you like to add at the start of the list?\n");
            scanf("%d", &value);
            if (!bool_created) {
                bool_created = 1;
                createList(&head, value);
            }
            else addToBeginning(&head, value);
        }
        else if (choice == 2) {
            printf("Which value would you like to remove?\n");
            scanf("%d", &value);
            printf("Current list: ");
            printList(head);
            deleteNodeFromList(&head, value);
        }
        printf("----------------------------------------------------------\n");
    }
    printf("List after node deletion:\n");
    printList(head);
    deleteList(&head);
    printf("List after list deletion:\n");
    printList(head);
    return 0;
}

void deleteNodeFromList (struct Node** head, int value) {
    struct Node* current = *head;
    struct Node* previous = NULL;
    int bool_found = 1;
    //find required node with the value
    while (current->data != value) {
        if (current->next == *head) {
            printf("Given node is not in the list.\n");
            bool_found = 0;
            return;
        }
        previous = current;
        current = current->next;
    }

    //check if found node is only node
    if (current->next == *head && (*head)->next == current && bool_found) {
        printf("ONLY");
        *head = NULL;
        free(current);
    }

    //if more than one node, check if found node is first node
    else if (current==*head && bool_found) {
        previous = *head;
        while (previous->next != *head) {
            previous = previous->next;
        }
        *head = current->next;
        previous->next = *head;
        free(current);
    }

    //check if found node is last node
    else if (current->next == *head && bool_found) {
        previous->next = *head;
        free(current);
    }

    else if (bool_found) {
        previous->next = current->next;
        free(current);
    }
    return;
}
