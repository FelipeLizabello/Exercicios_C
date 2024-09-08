#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct{
    char nome[MAX], rua[MAX], cidade[MAX], estado[MAX];
    long int telefone;
    int num;
}DADOS;

void ler(DADOS *dados){
    printf("Cidade\n");
    fflush(stdin);
    fgets((*dados).cidade, MAX, stdin);
    (*dados).cidade[strcspn((*dados).cidade, "\n")] = '\0';
    
    printf("Nome\n");
    fflush(stdin);
    fgets((*dados).nome, MAX, stdin);
    (*dados).nome[strcspn((*dados).nome, "\n")] = '\0';
    
    printf("Estado\n");
    fflush(stdin);
    fgets((*dados).estado, MAX, stdin);
    (*dados).estado[strcspn((*dados).estado, "\n")] = '\0';
    
    printf("Telefone\n");
    scanf("%ld", &(*dados).telefone);

    printf("Tempo\n");
    scanf("%d", &(*dados).num);
}

void remover(DADOS *dados){
    FILE *arq, *arq_temp;
    if((arq=fopen("dados16.bin", "rb")) == NULL){
        printf("ERRO\n");
        exit(1);
    }
    if((arq_temp=fopen("dados16_temp.bin", "wb")) == NULL){
        printf("ERRO\n");
        exit(1);
    }
    while(fread(&dados, sizeof(*dados), 1, arq)){
        fwrite(&dados, sizeof(*dados), 1, arq_temp);
    }
    fclose(arq);
    fclose(arq_temp);
    remove("dados16.bin");
    rename("dados16_temp.bin", "dados16.bin");
    printf("REmovido\n");  
}
int main(){
    DADOS dados;
    FILE *arq;
    char repet = 's', repet2 = 's';
    if((arq=fopen("dados16.bin", "wb")) == NULL){
        printf("ERRO\n");
        exit(1);
    } 
    do{
    ler(&dados);
    fwrite(&dados, sizeof(DADOS), 1, arq);
    printf("De novo? (s/n)\n");
    scanf(" %c", &repet); 
    }while(repet=='s');
    fclose(arq);
    
    do{
    printf("Deseja remover algum arquivo? (s/n)\n");
    scanf(" %c", &repet2);
    remover(&dados);
    }while (repet2 =='s');    
}