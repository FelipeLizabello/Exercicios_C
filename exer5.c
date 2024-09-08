#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char nome[99];
    int idade;
    float altura;
}PESSOA;

int main()
{
    char resp;
    PESSOA pessoa;
    FILE *arq;
    
    if((arq=fopen("pessoas.bin", "wb"))==NULL){
        printf("Erro\n");
        exit(1);
    }
do{ 
    fflush(stdin);
    printf("Nome: ");
    gets(pessoa.nome);
    
    printf("Idade: ");
    scanf("%d", &pessoa.idade);
    
    printf("Altura: ");
    scanf("%f", &pessoa.altura);    

    fwrite(&pessoa, sizeof(pessoa), 1, arq);
    printf("Adicionar mais pessoas? (s/n): ");  
    do{
        scanf(" %c", &resp);
    }while(resp != 's' && resp != 'n');
}while (resp == 's');

fclose(arq);
 
}