#include <stdio.h>
#include<stdlib.h>
typedef struct{
    char nome[99];
    int idade;
    float altura;
}PESSOA;
int main(){
PESSOA pessoa;
FILE *arq;

     if((arq=fopen("pessoas.bin", "rb"))==NULL){
        printf("Erro\n");
        exit(1);
    }
    while (fread(&pessoa, sizeof(pessoa), 1, arq)){
        printf("\n%s\n", pessoa.nome);
        printf("%d\n", pessoa.idade);
        printf("%.2f\n", pessoa.altura);
    }
    fclose(arq);
}