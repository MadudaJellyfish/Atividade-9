#include <stdio.h>
#include "crud.h"

int main(void) {

  FILE *pArq;
  FILE *pBin;
  Utens vetUtensils[100];
  int ids[100];

  if(!(pArq = fopen("utensils.txt", "r")))
  {
    printf("erro ao abrir o arquivo\n");
    exit(1);
  }

  int i = 0;
  while(!feof(pArq))
  {
    fscanf(pArq, "%d,%[^,],%f,%[^,],%d", &vetUtensils[i].id, vetUtensils[i].nome, &vetUtensils[i].preco, vetUtensils[i].descr, &vetUtensils[i].active);

    
    ids[i] = vetUtensils[i].id;

    i++;
  }

  fclose(pArq);

  if(!(pBin= fopen("utensils.bin", "rb")))
    {
      printf("erro ao abrir o arquivo\n");
      exit(1);
    }
  
  //lista_utens_text(); //listar utensílios arquivo texto
  //putchar('\n');
  //putchar('\n');
  //lista_utens(pBin); //listar utensílios arquivo texto
  //le_utens_txt("Batedor"); //ler um utensilio que existe
  //le_utens_txt("Fue"); //ler um utensilio que nao existe

  //le_utens("Mixer");
  //le_utens("Laranja");

  //Utens novo_utens = {1,"Cortador", 10.99, "Cortador de pizza", 0};
  //adiciona_utens_txt(novo_utens, ids); //adicionar um novo elemento no arquivo texto

  //adiciona_utens(novo_utens, ids); //adicionar um novo elemento no arquivo binario

  //atualiza_utens_txt(29,"Concha", "Servir caldos", vetUtensils); //atualizar utensilio que existe
  //atualiza_utens_txt(15, "Laranja", "Fruta", vetUtensils); //atualizar utensilio que nao existe

  //atualiza_utens(29,"Concha", "Servir caldos", vetUtensils);
  //atualiza_utens(15, "Laranja", "Fruta", vetUtensils);

  //remove_utens_txt(29, vetUtensils); //remover utensilio existente
  //remove_utens_txt(15, vetUtensils); //remover utensilio inexistente

  //remove_utens(29, vetUtensils); 
  //remove_utens(15, vetUtensils); 
  
  
  fclose(pBin);
  
  return 0;
}