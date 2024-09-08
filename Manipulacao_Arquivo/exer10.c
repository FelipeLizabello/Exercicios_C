#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    int idade;
    float nota;
}ALUNO;

void ler(ALUNO *aluno){
    fflush(stdin);
    printf("Nome\n");
    fgets((*aluno).nome, 20, stdin);
    
    printf("Idade\n");
    scanf("%d", &(*aluno).idade);

    printf("Nota\n");
    scanf("%f", &(*aluno).nota);

}
int main(){
    ALUNO aluno;
    FILE *arq;
    char repet = 's';

    if((arq = fopen("alunos.bin", "wb")) == NULL){
        printf("Erro\n");
        exit(1);
    }
do{    
    ler(&aluno);
    fwrite(&aluno, sizeof(aluno), 1, arq);
    printf("Adicionar outro aluno? (s/n)");
    scanf(" %c", &repet);

}while(repet =='s');
    fclose(arq);
}