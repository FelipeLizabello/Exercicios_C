#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data{
    int dia, mes, ano;
};
typedef struct{
    long int chave;
    char informacao[30];
    struct data data;
}INFO;

void ler(INFO *info){
    printf("Chave de acesso\n");
    scanf("%ld", &(*info).chave);

    printf("Informacao\n");
    fflush(stdin);
    fgets((*info).informacao, 30, stdin);

    printf("Dia/Mes/Ano\n");
    scanf("%d %d %d", &(*info).data.dia, &(*info).data.mes, &(*info).data.ano);
}
void copia(){
    FILE *arq, *arq_temp;
    INFO info;
    if((arq=fopen("fonte.bin", "rb"))==NULL){
        printf("ERRO\n");
        exit(1);
    }
    if((arq_temp=fopen("fonte_temp.bin", "wb"))==NULL){
        printf("ERRO\n");
        exit(1);
    }
    while(fread(&info, sizeof(INFO), 1, arq)){
        fwrite(&info, sizeof(INFO), 1, arq_temp);
    }
    fclose(arq);
    fclose(arq_temp);
    
}

int main(){
    FILE *arq;
    INFO info;
    char repet = 's'; 

    if((arq=fopen("fonte.bin", "wb"))==NULL){
        printf("ERRO\n");
        exit(1);
    }
    do{
        ler(&info);
        fwrite(&info, sizeof(INFO), 1, arq);
        printf("De novo? (s/n)\n");
        scanf(" %c", &repet);
    }while (repet == 's');
        fclose(arq);
    copia();

}