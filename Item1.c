#include <stdio.h>
#include <math.h>

int t = 5; // variavel de tamanho da matriz t 
char lixo;
int check, lido; // variaveis para checar se o que é digitato é valido ou não e le-lo


float media(int num, float x[num]){
    float m = 0; // m ser� a m�dia
    for(int i=0; i<num; i++){
    // soma todos os valores na matriz em m
        m += (float)x[i];
    }
    m /= num; // divide a soma feita pelo numero de elementos para se ter a m�dia
    return m;
}


float mediaPonderada(int num, float x[num]){
    float m = 0,s = 0; // M ser� a m�dia e S ser� a soma dos pesos
    float p[num]; // matriz para armazenar os pesos
    for (int i = 0; i < num; i++){
        printf("Qual peso tera o %d valor? ",i+1);  // pe�ar� os pesos ao usuraio
        do{
            lido = scanf("%f%c", &p[i], &lixo); // lê o número E o char seguinte
            check = (lido == 2 && lixo == '\n' && p[i] >= 0) ? 1 : 0; // caso seja um numero valido retorna 1, caso contrario, 0
            if (!check){
                printf("Valor invalido, Digite outro: ");
                char c;
                if (lido != 2 || lixo != '\n'){
                    do{
                        c = getchar();
                    } while(c != '\n'); // limpador de buffer
                }}
        }while (!check); // fazer enquanto não está checado
        m += (float)p[i]*x[i]; // soma do produto do peso ao seu valor pr�-inserido
        s += (float)p[i]; // soma dos pesos
    }
    s = s == 0? 1: s;
    return m / s; // j� que esse � o ultimo passo n�o � preciso calcular antes de retornar
}


float desvioPadrao(int n, float y[n]){
    float m,dp = 0; // dp ser� o desvio padr�o e m ser� a variavel da m�dia
    m = media(n,y);
    for (int i = 0; i < n; i++){
        dp += (float) powf((y[i]-m),2); // pow � da potencia que est� na biblioteca math
    }
    dp /= n;
    return sqrtf(dp); // j� ir� retornar o desvio pronto
}


float menorValor(int n, float x[n]){
    float min = x[0]; /* variavel min ser� o menor numero da sequencia
    c/ valor inicial sendo o primeiro numero que o usuario digitou */
    for (int i = 1; i < n; i++){
        min = (min < x[i])? min : x[i];
    }
    return min;
}


float maiorValor(int n, float x[n]){
    float max = x[0]; /* variavel max ser� o menor numero da sequencia
    c/ valor inicial sendo o primeiro numero que o usuario digitou */
    for (int i = 1; i < n; i++){
        max = (max > x[i])? max : x[i];
    }
    return (float)max;
}



int main(){
    int e = 0;      // variavel de tamanho da matriz t & variavel escolha e
    float r = 0,m[t],pv = 1; // Variavel resultado r & Matriz M para salvar os valores & Variavel primeira vez para checar se é a primeira vez que o comando está rodando
    for(int i = 0; i < t; i++){ // for para n�o gerar futuros bugs
        m[i] = 0;
    }
    do { // loop de repeti��o para as opera��es
        printf("Qual modo voce deseja usar?\n" // Menu
               "(1) Selecao dos numeros\n"
               "(2) Maior valor\n"
               "(3) Menor valor\n"
               "(4) Media\n"
               "(5) Media ponterada\n"
               "(6) Desvio padao\n"
               "(0) Encerrar sistema\n"
        );
        if (pv){
            printf("\n# Primeira inicialização do sistema! Opções possiveis (1) e (0) #\n\n");
        }
        printf("Escolha: ");
        do{
            lido = scanf("%d%c", &e, &lixo); // lê o número E o char seguinte
            if (pv){
                check = (lido == 2 && lixo == '\n' && e >= 0 && e <= 1) ? 1 : 0;
            } else check = (lido == 2 && lixo == '\n' && e >= 0 && e <= 6) ? 1 : 0; // caso seja um numero valido retorna 1, caso contrario, 0
            if (!check){
                printf("Valor invalido, Digite outro: ");
                char c;
                if (lido != 2 || lixo != '\n'){
                    do{
                        c = getchar();
                    } while(c != '\n'); // limpador de buffer
                }}
        }while (!check); // fazer enquanto não está checado
        printf("\n");
        
        switch(e){ // case baseado na escolha

        case 1:
            for(int i = 0; i < t; i++){
                printf("Digite um valor para o espaco [%d]: ",i);
                do{
                    lido = scanf("%f%c", &m[i], &lixo); // lê o número E o char seguinte
                    check = (lido == 2 && lixo == '\n' && m[i] >= 0) ? 1 : 0; // caso seja um numero valido retorna 1, caso contrario, 0
                    if (!check){
                        printf("Valor invalido, Digite outro: ");
                        char c;
                        if (lido != 2 || lixo != '\n'){
                            do{
                                c = getchar();
                            } while(c != '\n'); // limpador de buffer
                        }}
                }while (!check); // fazer enquanto não está checado
            }
            printf("\n");
            pv = 0;
            break;
        case 2:
            r = maiorValor(t,m);
            printf("O maior valor de M: %.3f\n\n",r);
            break;
        case 3:
            r = menorValor(t,m);
            printf("O menor valor de M: %.3f\n\n",r);
            break;
        case 4:
            r = media(t,m);
            printf("Media de M: %.3f\n\n",r);
            break;
        case 5:
            r = mediaPonderada(t,m);
            printf("\nMedia ponderade de M: %.3f\n\n",r);
            break;
        case 6:
            r = desvioPadrao(t,m);
            printf("Desvio padrao em M: %.3f\n\n",r);
            break;
        };
    } while(e); // N�o � necessario reqra l�gica pois o 0 J� � O VALOR DE FALSE
    return 0;
}