#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char lixo;
int check, lido; // variaveis para checar se o que é digitato é valido ou não e le-lo

int main(){
    int t = 1,x,n; // variavel tentativa atual n e variavel numero que tem que acertar x e numero de tentativas t
    srand(time(NULL)); // gera uma seed para o randomizador com base no tempo
    x = rand() % 101; // randomiza e seleciona o resto da divisão por 101, variando de 0 a 100
    printf("BEM VINDO A CACA AO TESOURO!\n\nRegras:\nSo vale numeros de 0 a 100\nVoce deve acertar o numero sorteado\nBoa sorte!\n\n");
    do{
        printf("Digite um numero: ");
        do{
            lido = scanf("%d%c", &n, &lixo); // lê o número E o char seguinte
            check = (lido == 2 && lixo == '\n' && n>= 0 && n <= 100) ? 1 : 0; // caso seja um numero valido retorna 1, caso contrario, 0
            if (!check){
                printf("Valor invalido, Digite outro: ");
                char c;
                if (lido != 2 || lixo != '\n'){
                    do{
                        c = getchar();
                    } while(c != '\n'); // limpador de buffer
                }}
        }while (!check); // fazer enquanto não está checado

        if (n > x){
            printf("VOCE ERROU!!!\n%d é maior que o numero sorteado\n",n);
            t++;
        } else if( n < x){
            printf("VOCE ERROU!!!\n%d é menor que o numero sorteado\n",n);
            t++;
        }
    } while (n != x);
    printf("PARABENS!!! O NUMERO SORTEADO ERA %d\nVoce acertou com %d tentativas",x,t);
    return 0;
}
