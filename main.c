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

int main() {
    struct Node* head = NULL;
    int choice = 0;
    int value;
    int bool_created = 0;
    
    while (choice != 3) {
        printf("Enter 1 if you want to create a circular singly linked list.\n");
        printf("Enter 2 if you want to insert a node at the start of the list.\n");
        printf("Enter 3 if you want to remove a value from the list.\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Which value would you like to be the first element of the list?\n");
            scanf("%d", &value);
            createList(&head, value);
        }
        if (choice == 2) {
            printf("Which value would you like to add at the start of the list?\n");
            scanf("%d", &value);
            addToBeginning(&head, value);
        }
        else if (choice == 3) {
            printf("Which value would you like to remove?\n");
            scanf("%d", &value);
            printf("Current list: ");
            printList(head);
            deleteNodeFromList(&head, value);
        }
        printf("----------------------------------------------------------\n");
    }
    printf("List after deletion:\n");
    printList(head);

    return 0;
}
