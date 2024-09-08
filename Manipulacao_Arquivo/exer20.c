#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    void pares(){
        int i=0,j=0;
        int num_temp[5], num[5];
        FILE *arq, *arq_temp;
        if((arq = fopen("numeros.bin", "rb"))== NULL){
            printf("ERRO ao abirir numeros.bin\n");
            exit(1);
        }
        if((arq_temp = fopen("numeros_temp.bin", "wb"))== NULL){
            printf("ERRO ao abirir numeros_temp.bin\n");
            exit(1);
        }

        while(fread(&num, sizeof(int), 5, arq)==5){
        j=0;
            for(i=0; i<5; i++){
                if(num[i] % 2 == 0 ){
                    num_temp[j] = num[i];
                    j++;
                }
            }
            fwrite(num_temp, sizeof(int), j, arq_temp);
        }

        fclose(arq);
        fclose(arq_temp);
        remove("numeros.bin");
        rename("numeros_temp.bin", "numeros.bin");
        printf("Arquivo copiado com sucesso\n");
    }

int main(){
    int num[5], i;
    char repet = 's';
    FILE *arq;

        if((arq = fopen("numeros.bin", "wb"))== NULL){
            printf("ERRO\n");
            exit(1);
        }
        do{
            for(i=0; i<5; i++)
                scanf("%d", &num[i]);
            fwrite(num, sizeof(int), 5, arq);
            printf("Deseja outro? (s/n)");
            scanf(" %c", &repet);
        }while(repet == 's');
            fclose(arq);

    pares();
}