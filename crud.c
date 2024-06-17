#define _CRT_SECURE_NO_WARNINGS
#include "crud.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

//quick sort para ordenaçao

void lista_utens(FILE *fBin) {

  Utens utens;

  while (fread(&utens, sizeof(Utens), 1, fBin) == 1) {
    if(utens.active==1)
      printf("%d,%s,%.2f,%s\n", utens.id, utens.nome, utens.preco, utens.descr);
  }

  return;
}

void le_utens(char *nome) {
  FILE *fBin;
  int achou = 0;

  if (!(fBin = fopen("utensils.bin", "rb"))) {
    printf("nao foi possivel abrir o arquivo");
    exit(1);
  }

  Utens utens;

  while (fread(&utens, sizeof(Utens), 1, fBin) == 1) {

    if (strcmp(nome, utens.nome) == 0 && utens.active == 1) {
      printf("%d, %s ,%.2f ,%s\n", utens.id, utens.nome, utens.preco, utens.descr);
      achou = 1;
      break;
    }
  }

  if(achou == 0)
    printf("Utensilio %s nao econtrado\n", nome);
 

  fclose(fBin);
  
  return;
}

void adiciona_utens(Utens novo, int ids_existentes[]) {
  FILE *fBin;

  clock_t start, end, diff;
  start = clock();

  if (!(fBin = fopen("utensils.bin", "ab"))) {
    printf("nao foi possivel abrir o arquivo");
    exit(1);
  }

  novo.id = rand() % 100;
  novo.active = 1;

  int aux = 0;
  do{
    for (int i = 0; i < TAM; i++){
      if (novo.id == ids_existentes[i]){
        novo.id = rand() % 100;
        aux = i;
      }
    }
  } while (novo.id == ids_existentes[aux]);
  
  fwrite(&novo, sizeof(novo), 1, fBin);

  fclose(fBin);

  end = clock();
  diff = end - start;
  printf("Tempo gasto: %f\n", (double)diff / CLOCKS_PER_SEC);
  
  return;
}

void atualiza_utens(int id, char* novo_nome, char* nova_descr, Utens lista_utens[]) {
  FILE* fBin;
  int achou = 0;

  clock_t start, end, diff;
  start = clock();

  for (int i = 0; i < TAM; i++){
    if (lista_utens[i].id == id) {
      strcpy(lista_utens[i].nome, novo_nome);
      strcpy(lista_utens[i].descr, nova_descr);
      achou = 1;
      break;
  }
}

  if(achou == 0)
  {
    printf("Utensilio  de id %d nao encontrado\n", id);
    end = clock();
    diff = end - start;
    printf("Tempo gasto: %f\n", (double)diff / CLOCKS_PER_SEC);
    return;
  }

  if (!(fBin = fopen("utensils.bin", "wb"))) {
    printf("nao foi possivel abrir o arquivo");
    exit(1);
  }

  int i = 0;
  while(lista_utens[i].id)
  {
    fwrite(&lista_utens[i], sizeof(Utens), 1, fBin);
    i++;
  }

  fclose(fBin);
  
  end = clock();
  diff = end - start;
  printf("Tempo gasto: %f\n", (double)diff / CLOCKS_PER_SEC);
  
}

void remove_utens(int id, Utens lista_utens[]){
  FILE *fBin;
  int del_pos;
  int achou = 0;

  clock_t start, end, diff;
  start = clock();

  for (int i = 0; i < TAM; i++){
    if (id == lista_utens[i].id) {
      del_pos = i;
      achou = 1;
      break;
    }
  }

  if(achou == 0)
  {
    printf("Utensilio de id %d nao encontrado\n", id);
    end = clock();
    diff = end - start;
    printf("Tempo gasto: %f\n", (double)diff / CLOCKS_PER_SEC);
    return;
  }

  lista_utens[del_pos].active = 0;
  

  if (!(fBin = fopen("utensils.bin", "wb"))) {
    printf("nao foi possivel abrir o arquivo");
    exit(1);
  }

  int i = 0;
  while(lista_utens[i].id)
  {
    fwrite(&lista_utens[i],sizeof(Utens),1,fBin);
    i++;
  }
  
  fclose(fBin);

  end = clock();
  diff = end - start;
  printf("Tempo gasto: %f\n", (double)diff / CLOCKS_PER_SEC);
}


//****************************************************
//arquivo texto
//****************************************************

void lista_utens_text() {

  Utens utens;
  FILE* fArq;
  
  if(!(fArq=fopen("utensils.txt", "r")))
    exit(1);

  while (!(feof(fArq))) {
    fscanf(fArq, "%d,%[^,],%f,%[^,],%d\n", &utens.id, utens.nome, &utens.preco, utens.descr, &utens.active);
    
    if(utens.active==1)
      printf("%d, %s ,%.2f ,%s\n", utens.id, utens.nome, utens.preco, utens.descr);
    
  }

  return;
}

void le_utens_txt(char *nome) {
  FILE *fArq;
  int achou = 0;

  if (!(fArq = fopen("utensils.txt", "r"))) {
    printf("nao foi possivel abrir o arquivo");
    exit(1);
  }

  Utens utens;

  while (!(feof(fArq))) {
    fscanf(fArq, "%d,%[^,],%f,%[^\n]\n", &utens.id, utens.nome, &utens.preco, utens.descr);

    if (strcmp(nome, utens.nome) == 0 && utens.active ==1) {
      printf("%d,%s,%.2f,%s\n", utens.id, utens.nome, utens.preco, utens.descr);
      achou = 1;
      break;
    }
  }

  if(achou == 0)
    printf("Utensilio %s nao encontrado!\n", nome);

  fclose(fArq);

  return;
}

void adiciona_utens_txt(Utens novo, int ids_existentes[]) {
  FILE *fArq;
  int aux = 0;

  clock_t start, end, diff;
  start = clock();
  
  if (!(fArq = fopen("utensils.txt", "a"))) {
    printf("nao foi possivel abrir o arquivo");
    exit(1);
  }

  novo.id = rand() %100;
  novo.active = 1;
  
  do{
    for (int i = 0; i < TAM; i++){
      if (novo.id == ids_existentes[i]){
        novo.id = rand() % 100;
        aux = i;
      }
    }
  } while (novo.id == ids_existentes[aux]);
  
  fprintf(fArq, "\n%d,%s,%f,%s", novo.id, novo.nome, novo.preco, novo.descr);

  fclose(fArq);

  end = clock();
  diff = end - start;
  printf("Tempo gasto: %f\n", (double)diff / CLOCKS_PER_SEC);

  return;
}

void atualiza_utens_txt(int id, char* novo_nome, char* nova_descr, Utens lista_utens[])
{
  FILE* fArq;
  int achou = 0;

  clock_t start, end, diff;
  start = clock();

  for (int i = 0; i < TAM; i++){
    if (lista_utens[i].id == id) {
      strcpy(lista_utens[i].nome, novo_nome);
      strcpy(lista_utens[i].descr, nova_descr);
      achou = 1;
      break;
  }
}
  if (achou == 0)
  {
    printf("Utensilio de id %d nao encontrado\n", id);
    end = clock();
    diff = end - start;
    printf("Tempo gasto: %f\n", (double)diff / CLOCKS_PER_SEC);
    return;
  }

  if (!(fArq = fopen("utensils.txt", "w"))) {
    printf("nao foi possivel abrir o arquivo");
    exit(1);
  }
  
  int i = 0;
  while(lista_utens[i].id)
  {
    fprintf(fArq, "%d,%s,%f,%s,%d\n", lista_utens[i].id, lista_utens[i].nome, lista_utens[i].preco, lista_utens[i].descr, lista_utens[i].active);
    i++;
  }

  fclose(fArq);

  end = clock();
  diff = end - start;
  printf("Tempo gasto: %f\n", (double)diff / CLOCKS_PER_SEC);
}

void remove_utens_txt(int id, Utens lista_utens[]){
  FILE *fArq;
  int del_pos;
  int achou = 0;

  clock_t start, end, diff;
  start = clock();

  for (int i = 0; i < TAM; i++){
    if (id == lista_utens[i].id) {
      del_pos = i;
      achou = 1;
      break;
    }
  }

  if(achou == 0)
  {
    printf("Utensilio de id %d nao encontrado\n", id);
    end = clock();
    diff = end - start;
    printf("Tempo gasto: %f\n", (double)diff / CLOCKS_PER_SEC);
    return;
  }
 
  lista_utens[del_pos].active = 0;

  if (!(fArq = fopen("utensils.txt", "w"))) {
    printf("nao foi possivel abrir o arquivo");
    exit(1);
  }

  int i = 0;
  while(lista_utens[i].id)
  {
    fprintf(fArq, "%d,%s,%f,%s,%d\n", lista_utens[i].id, lista_utens[i].nome, lista_utens[i].preco, lista_utens[i].descr, lista_utens[i].active);
    i++;
  }
    
  fclose(fArq);

  end = clock();
  diff = end - start;
  printf("Tempo gasto: %f\n", (double)diff / CLOCKS_PER_SEC);
}