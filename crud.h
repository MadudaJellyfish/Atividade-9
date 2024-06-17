#define MAX 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>


struct utens {
  int id;
  char nome[MAX];
  float preco;
  char descr[MAX];
  int active;
};

typedef struct utens Utens;

void lista_utens(FILE* fBin);
void le_utens(char *nome);
void adiciona_utens(Utens utens, int ids_existentes[]);
void atualiza_utens(int id, char* novo_nome, char* nova_descr, Utens lista_utens[]);
void remove_utens(int id, Utens lista_utens[]);

void lista_utens_text();
void le_utens_txt(char *nome);
void adiciona_utens_txt(Utens utens, int ids_existentes[]);
void atualiza_utens_txt(int id, char* novo_nome, char* nova_descr, Utens lista_utens[]);
void remove_utens_txt(int id, Utens lista_utens[]);