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

//A linked list node
struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* n) {
    while (n != 0) {
        printf("%d ", n->data);
        n = n->next;
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL; 

    head = (struct Node*)malloc(sizeof(struct Node));   
    second = (struct Node*)malloc(sizeof(struct Node));   
    third = (struct Node*)malloc(sizeof(struct Node)); 

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL; 

    printList(head);
}
