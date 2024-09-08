#include <stdio.h>
#include <stdlib.h>

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

void arquivo(char *nome_arquivo, ALUNO *aluno){
    char repet = 's';
    FILE *arq;   
    
    if((arq = fopen(nome_arquivo, "wb"))== NULL){
        printf("Erro");
        exit(1);
    }
do{
    ler(aluno);
    fwrite(&aluno, sizeof(aluno), 1, arq);
    printf("De novo? (s/n)\n");
    scanf(" %c", &repet);
}while(repet == 's');
fclose(arq);
}

void turma_comp(ALUNO *aluno){
    FILE *arqA, *arqB, *arqC;

    if((arqA = fopen("turmaA.bin", "rb"))== NULL){
        printf("Erro");
        exit(1);
    }
    if((arqB = fopen("turmaB.bin", "rb"))== NULL){
        printf("Erro");
        exit(1);
    }

    if((arqC = fopen("turba_completa.bin", "wb"))== NULL){
        printf("Erro");
        exit(1);
    }
    
    while(fread(&aluno, sizeof(aluno), 1, arqA)){
        fwrite(&aluno, sizeof(aluno), 1, arqC); 
    }
    while(fread(&aluno, sizeof(aluno), 1, arqB)){
        fwrite(&aluno, sizeof(aluno), 1, arqC); 
    }
    fclose(arqA);
    fclose(arqB);
    fclose(arqC);
    
    printf("Os arquivos foram combinados em turma_completa.bin com sucesso!!(eu acho)\n");
}

int main(){
    ALUNO aluno;
    arquivo("turmaA.bin", &aluno);
    arquivo("turmaB.bin", &aluno);
    turma_comp(&aluno);
}