#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[5];
    int i;

    FILE *arq;

    if((arq=fopen("dados.bin","rb")) == NULL){
        printf("Erro\n");
        exit(1);
    }
    while (fread(&vetor,sizeof(vetor), 1, arq))
    {
        for (i = 0; i <5; i++)
        {
            printf("%d ", vetor[i]);
        }
        
    }
    
}