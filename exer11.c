#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[20];
    int idade;
    float nota;
}ALUNO;

int main(){
    ALUNO aluno;
    FILE *arquivo;

    if((arquivo = fopen("alunos.bin", "rb")) == NULL){
        printf("Erro\n");
        exit(1);
    }

    while(fread(&aluno, sizeof(aluno), 1, arquivo)){
        printf("%s", aluno.nome);
        printf("%d\n", aluno.idade);
        printf("%.2f\n", aluno.nota);
    }
    fclose(arquivo);
}