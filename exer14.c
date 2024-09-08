#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    long int num_tele;
    char cidade[30];
    int tempo;
}TELE;

void ler(TELE *telefone){
    printf("Cidade\n");
    fflush(stdin);
    fgets((*telefone).cidade, 30, stdin);
    (*telefone).cidade[strcspn((*telefone).cidade, "\n")] = '\0';
    
    printf("Telefone\n");
    scanf("%ld", &(*telefone).num_tele);

    printf("Tempo\n");
    scanf("%d", &(*telefone).tempo);
}

void arquivo(char *nome_arq, TELE *telefone){
    char repet = 's';
    FILE *arq;
        if((arq = fopen(nome_arq, "wb")) == NULL){
            printf("Erro\n");
            exit(1);
        }
    do{
       ler(telefone);
       fwrite(telefone, sizeof(TELE), 1, arq);
       printf("De novo? (s/n)\n");
       scanf(" %c", &repet); 
    }while(repet == 's');
fclose(arq);
}

void compara(){
    FILE *arq1, *arq2;
    TELE tel1, tel2;
    int flag = 0;
    if((arq1=fopen("listaA.bin", "rb")) == NULL){
        printf("Erro 1\n");
        exit(1);
    }
    if((arq2=fopen("listaB.bin", "rb")) == NULL){
        printf("Erro 1\n");
        exit(1);
    }

    while (fread(&tel1, sizeof(TELE), 1, arq1)){
        rewind(arq2);
            while(fread(&tel2, sizeof(TELE), 1, arq2)){
                if(strcmp(tel1.cidade, tel2.cidade) == 0){
                    printf("Cidade:%s\n Telefones:\n%ld\n%ld", tel1.cidade, tel1.num_tele, tel2.num_tele);
                    flag = 1;
                } 
            }
    }
    if(!flag)
        printf("Nenhuma cidade encontrada\n");

fclose(arq1);
fclose(arq2);

}
int main(){
    TELE telefone;
    arquivo("listaA.bin", &telefone);
    arquivo("listaB.bin", &telefone);
    compara();
}