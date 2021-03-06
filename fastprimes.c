#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"

const size_t END = 500;  //Az do jakeho cisla ma zjistovat zda se jedna o prvocislo

bool is_prime(int input, node_t * head){    //Zjistim zda se jedna o prvocislo nebo ne
    for(node_t * current = head; current->value < input && current->next != NULL; current = current->next){
        if((input % current->value) == 0){
            return false;
        }
    }

    return true;
}

void find_primes(node_t * head, const size_t end){
    for(size_t i = 3; i < end; i++){
        if(is_prime(i, head)){
            if(append(head, i) == 0){
                fprintf(stderr, "Number %ld is prime\n", i);
            }
            else {
                fprintf(stderr, "Error saving prime, cannot continue!\n");
                return;
            }
        }
        else{
            fprintf(stderr, "Number %ld is not prime\n", i);
        }
    }
}

int main(){
    node_t * head = newnode(2);  //Vytvori zacatek listu pro ukladani prvocisel

    find_primes(head, END);  //Najde vsechny prvocisla az do velikosti END

    printlist(head);  //Vypisi prvocisla
    freelist(head);  //Uvolni pamet l. listu

    return 0;
}
