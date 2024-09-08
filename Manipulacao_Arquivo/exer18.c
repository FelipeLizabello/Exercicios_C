#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 35
typedef struct{
    char estd_civil[MAX];
    int num_dependentes;
    long int valor_patrimonio; 
}DADOS;
void ordena(DADOS *dados, int n){
    DADOS temp;
    int i, j;
        for(i=0; i<n-1; i++){
            for(j=0; j<n-1-i; j++){
                if(dados[j].num_dependentes > dados[j+1].num_dependentes){
                    temp = dados[j];
                    dados[j] = dados[j+1];
                    dados[j+1] = temp;
                }
            }
        }
}
void ler(DADOS *dados, int n){
int i;

    for(i=0; i<n; i++){
        printf("Estado civil\n");
        fflush(stdin);
        fgets(dados[i].estd_civil, MAX, stdin);
        dados[i].estd_civil[strcspn(dados[i].estd_civil, "\n")] = '\0';
    
        printf("Patrimonio\n");
        scanf("%ld", &dados[i].valor_patrimonio);

        printf("Numero de dependentes\n");
        scanf("%d", &dados[i].num_dependentes);
    }
}
void printa(){
    DADOS dados;
    FILE *arq;
    if((arq=fopen("dados_pacientes.bin", "rb")) == NULL){
            printf("ERRO\n");
            exit(1);
        }
    
    while (fread(&dados, sizeof(DADOS), 1, arq))
    {
        printf("\n%s\n", dados.estd_civil);
        printf("%d\n", dados.num_dependentes);
        printf("%ld\n", dados.valor_patrimonio);
    }
    fclose(arq);
    

}
int main(){
    int n =3;
    DADOS dados[3];
    FILE *arq;

    ler(dados, n);
    ordena(dados, n);
        if((arq=fopen("dados_pacientes.bin", "wb")) == NULL){
            printf("ERRO\n");
            exit(1);
        } 
        
        fwrite(dados, sizeof(DADOS), n, arq);
        printf("Arquivos salvos\n");
        fclose(arq);
    
    printf("Arquivos oredenaddos\n");
    printa();

}