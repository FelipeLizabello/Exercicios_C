#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[5]= {0};

    FILE *arquivo;
    if((arquivo = fopen("dados.bin", "rb")) == NULL){
        printf("Erro\n");
        exit(1);
    }
    fread(&vetor, sizeof(vetor), 1, arquivo);
    fclose(arquivo);

    if((arquivo = fopen("dados.bin", "wb")) == NULL){
        printf("Erro\n");
        exit(1);
    }
    printf("Reescreva a posicao 3: ");
    scanf("%d", &vetor[2]);
    
    fwrite(&vetor, sizeof(vetor), 1, arquivo);
    fclose(arquivo);
}