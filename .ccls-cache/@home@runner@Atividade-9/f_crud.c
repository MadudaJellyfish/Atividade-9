#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "crud.h"

void lista_utens(Utens *vetUtensils) {
  int tamVet = sizeof((*vetUtensils))/sizeof(Utens);

  for(int i =0; i < tamVet;i++){
    printf("%d,%s,%f,%s\n", vetUtensils[i].id, vetUtensils[i].nome,
     vetUtensils[i].preco, vetUtensils[i].descr);

  }
}
