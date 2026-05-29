#include <stdio.h>
#include <stdlib.h>

int main(){
    int x,check;
    printf("Digite um numero de 0 a 6: ");
    do{
        char lixo;
        int lido = scanf("%d%c", &x, &lixo); // lê o número E o char seguinte
        check = (lido == 2 && lixo == '\n' && x >= 0 && x <= 6) ? 1 : 0;
        printf("Valor lixo[%d] Pré validez[%d] Validez[%d]\n",lixo,lido,check);
        if (check){
            printf("\n\nO numero digitado é %d \nValor do lixo[%d] Pré-validex[%d] Validez[%d]\n",x,lixo,lido,check);
        } else {
            printf ("Valor invalido digite outro\nNumero x: (%d) Valor do Lixo: (%d) Pré-validez: (%d) Validez: (%d)\n",x,lixo,lido,check);
            char c;
            int i = 1;
            if (lido != 2 || lixo != '\n'){
            do{
                    c = getchar();
                    printf("valor do buffer %d: (%d)\n",i,c);
                    i++;
                } while(c != '\n');
            }
        }
    }while (!check);
    
    return 0;
}