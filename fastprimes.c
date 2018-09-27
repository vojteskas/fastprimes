#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "linkedlist.c"
					
#define END 500								//Az do jakeho cisla ma zjistovat
											//zda se jedna o prvocislo
void primes(int input, node_t * head);
void countAllPrimes(node_t * head);

int main(){
	node_t * head = newnode(2);				//Vytvori zacatek listu pro
											//ukladani prvocisel
	
	countAllPrimes(head);					//Najde vsechny prvocisla az
											//do velikosti END
	
	printlist(head);						//Vypisi prvocisla
	freelist(head);							//Uvolni pamet l. listu
	
	return 0;
}

void primes(int input, node_t * head){		//Zjistim zda se jedna o prvocislo nebo ne
	for(node_t * current = head; current->value < input; current = current->next){
		if((input % current->value) == 0){
			printf("Cislo %d neni prvocislo\n", input);
			return;
		}
		if(current->next == NULL){
			break;
		}
	}
	printf("Cislo %d je prvocislo!!\n", input);
	append(head, input);					//Nove zjistene prvocislo pridam do linked listu
	return;
}

void countAllPrimes(node_t * head){			//Zjistuji pro vsechna cisla az do END
	for(int i = 3; i < END; i++){
		primes(i, head);
	}
	return;
}
