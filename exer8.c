#include <stdio.h>
#include<stdlib.h>
typedef struct{
    char nome[99];
    int idade;
    float altura;
}PESSOA;

int main(){
    int indice = 1;
    PESSOA pessoa;
    FILE *arq, *arq_novo;

    if((arq = fopen("pessoas.bin", "rb")) == NULL){
        printf("Erro alunos.bin\n");
        exit(1);
    }
    if ((arq_novo = fopen("arquivo_novo.bin", "wb")) == NULL) {
        printf("Erro ao criar arquivo novo.\n");
        exit(1);
    }
    
    while(fread(&pessoa, sizeof(pessoa), 1, arq)==1){
        if(indice != 2){
            fwrite(&pessoa, sizeof(pessoa), 1, arq_novo);
        }
    indice ++;    
    }

    fclose(arq);
    fclose(arq_novo);
    remove("pessoas.bin");
    rename("arquivo_novo.bin", "pessoas.bin");
    printf("Segunda pessoa removida\n");

    
}