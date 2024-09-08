#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[5];
    int i;
    printf("Digite 5 numeros inteiros\n");

        for(i=0; i<5; i++){
            scanf("%d", &vetor[i]);
        }
    
    FILE *arq;
        if((arq = fopen("dados.bin", "wb")) == NULL){
            printf("Erro ao abrir arquivo\n");
            exit(1);
        }
    
    fwrite(&vetor, sizeof(vetor), 1, arq);
    fclose(arq);
}