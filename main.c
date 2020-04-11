#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<time.h>
#include<windows.h>
#include <locale.h>

#define TAM_L 6
#define TAM_C 6

void regrasDoJogo()
{
    printf("************************REGRAS*********************************************\n");
    printf(" O tabuleiro deve conter a quantidade MÍNIMA de 3 linhas e 3 colunas         \n");
    printf(" O tabuleiro deve conter a quantidade MÁXIMA de 6 linhas e 6 colunas         \n");
    printf(" Ao escolher o segundo item, ele deve ter uma posição diferente do primeiro  \n");
    printf(" Não digite letras durante o jogo                                            \n");
    printf("\n\n                       BOM JOGO");
    Sleep(4000);
    system("cls");
}
void solicitarDimensoesTabuleiro(int *pQtdL, int *pQtdC)
{
    printf("\nDigite a quantidade de linhas do seu tabuleiro: ");
    scanf("%i", pQtdL);
    fflush(stdin);
    while (*pQtdL<3||*pQtdL>6)
    {
        printf("Valor não coicide com as regras, digite novamente  ");
        scanf("%i", pQtdL);
        fflush(stdin);
    }
    printf("\nDigite a quantidade de colunas do seu tabuleiro: ");
    scanf("%i", pQtdC);
    fflush(stdin);
    while (*pQtdC<3||*pQtdC>6)
    {
        printf("Valor não coicide com as regras, digite novamente   ");
        scanf("%i", pQtdC);
        fflush(stdin);
    }
}
void preencherTabuleiro(char tab[TAM_L][TAM_C], int *pQtdL, int *pQtdC, char letrasArray[19])
{
    srand(time(NULL));
    int contador=0;
    int qtdLetras= (*pQtdC**pQtdL)/2, indice=0; //qtsLetras e a quantidade de letras que serao necessarias no tabuleiro
    char letras [qtdLetras+1]; //preenchendo somente com as letras necessarias
    for(int i=0; i< qtdLetras; i++)
    {
        letras[i]=letrasArray[i];
    }
    letras[qtdLetras]='\0'; //deixando o ultimo espaço null para nao influenciar o tabuleiro
    qtdLetras--; //o vetor letras tem a mesma quantidade de letras, -1 pois começa a contas no 0
    for(int l=0; l<*pQtdL; l++) //limpar o vetor principal
    {
        for (int c=0; c<*pQtdC; c++)
        {
            tab[l][c]='\0';
        }
    }
    for (int i = 0; i < qtdLetras; i++) //misturar as letras do vetor Letras, para ter uma aleatoridade
    {
        int r = rand() % qtdLetras;

        int temp = letras[i];
        letras[i] = letras[r];
        letras[r] = temp;
    }
    for(int l=0; l<*pQtdL; l++) //adicionar os valor do vetor letras no vetor principal
    {
        for (int c=0; c<*pQtdC; c++)
        {
            if ((*pQtdL**pQtdC)%2==1)
            {
                if(contador==0)
                {
                    int w,q;
                    w=rand()%*pQtdL;
                    q=rand()%*pQtdC;
                    tab[w][q]='?';
                    contador++;
                }
            }
            if (indice>qtdLetras)
            {
                for (int i = 0; i < qtdLetras; i++) //mistura novamente para nao ficar nas mesmas posicoes
                {
                    int r = rand() % qtdLetras;

                    int temp = letras[i];
                    letras[i] = letras[r];
                    letras[r] = temp;
                }
                indice=0;
            }
            if (tab[l][c]=='\0')
            {
                tab[l][c]=letras[indice];
                indice++;
            }
        }
    }
}
void construirTabuleiro(char tab[TAM_L][TAM_C], int *pQtdL, int *pQtdC, char letrasArray[19])
{
    // Pedir para o usuário as dimensões de linha e de coluna
    solicitarDimensoesTabuleiro(pQtdL, pQtdC);

    // Preencher o tabuleiro
    preencherTabuleiro(tab, pQtdL, pQtdC,letrasArray);

}
void visualizarTabuleiro(char tab[TAM_L][TAM_C], int *pQtdL, int *pQtdC)
{
    for(int l=0; l<*pQtdL; l++)
    {
        for (int c=0; c<*pQtdC; c++)
            printf("| %c |", tab[l][c]);
        printf("\n");
    }
    Sleep(3000);
    system("cls");

}
void visualizarTabuleiroJogo(char tabVISIVEL[TAM_L][TAM_C], int *pQtdL, int *pQtdC)
{
    for(int l=0; l<*pQtdL; l++)
    {
        for (int c=0; c<*pQtdC; c++)
        {
            printf(" %c ", tabVISIVEL[l][c]);
        }
        printf("\n");
    }
}
void pedirPosicoes (char tab[TAM_L][TAM_C], int *pQtdL, int *pQtdC,int *escolhaL, int *escolhaC, int *escolhaL2, int *escolhaC2)
{
    printf("\nDigite a linha do primeiro item  ");
    scanf("%i", escolhaL);
    fflush(stdin);
    while(*escolhaL>*pQtdL||*escolhaL==0)
    {
        printf("\nValor invalido, digite novamente ");
        scanf("%i", escolhaL);
        fflush(stdin);
    }
    *escolhaL=*escolhaL-1;//para usar a posicao dos vetores
    printf("\nDigite a coluna do primeiro item  ");
    scanf("%i", escolhaC);
    fflush(stdin);
    while(*escolhaC>*pQtdC||*escolhaC==0)
    {
        printf("\nValor invalido, digite novamente ");
        scanf("%i", escolhaC);
        fflush(stdin);
    }
    *escolhaC= *escolhaC-1;//para usar a posicao dos vetores
    do
    {
        printf("\nDigite a linha do segundo item  ");
        scanf("%i", escolhaL2);
        fflush(stdin);
        while(*escolhaL2>*pQtdL||*escolhaL2==0)
        {
            printf("\nValor invalido, digite novamente ");
            scanf("%i", escolhaL2);
            fflush(stdin);
        }
        *escolhaL2=*escolhaL2-1;//para usar a posicao dos vetores
        printf("\nDigite a coluna do segundo item  ");
        scanf("%i", escolhaC2);
        fflush(stdin);
        while(*escolhaC2>*pQtdC||*escolhaC2==0)
        {
            printf("\nValor invalido, digite novamente ");
            scanf("%i", escolhaC2);
            fflush(stdin);
        }
        *escolhaC2= *escolhaC2-1;//para usar a posicao dos vetores
    }
    while(*escolhaL==*escolhaL2 && *escolhaC==*escolhaC2);
}
void contadorJogo(char tab[TAM_L][TAM_C], int *escolhaL, int *escolhaC, int *escolhaL2, int *escolhaC2, int *pontos, int *jogadas, int *posicoesOcultas,  int *pQtdL, int *pQtdC, char tabVISIVEL[TAM_L][TAM_C])
{
    if (tab[*escolhaL][*escolhaC]=='?'||tab[*escolhaL2][*escolhaC2]=='?')
    {
        int contador=0;
        system("cls");
        printf("\n Voce caiu na armadilha!");
        for(int l=0; l<*pQtdL; l++)
        {
            if (contador>0)
            {
                break;
            }
            for (int c=0; c<*pQtdC; c++)
            {
                if (contador>0)
                {
                    break;
                }
                if (tabVISIVEL[l][c]!='-')
                {
                    for(int a=0; a<*pQtdL; a++)
                    {
                        if (contador>0)
                        {
                            break;
                        }
                        for (int b=0; b<*pQtdC; b++)
                        {
                            if (contador>0)
                            {
                                break;
                            }
                            if (tabVISIVEL[l][c]==tabVISIVEL[a][b] && l!=a && c!=b)
                            {
                                tabVISIVEL[l][c]='-';
                                tabVISIVEL[a][b]='-';
                                contador++;
                            }
                        }
                    }
                }
            }
        }
        printf("\n");
        visualizarTabuleiroJogo(tabVISIVEL, pQtdL, pQtdC);

        ++*posicoesOcultas;
        ++*posicoesOcultas;
    }
    else if (tabVISIVEL[*escolhaL][*escolhaC]=='-' && tabVISIVEL[*escolhaL2][*escolhaC2]=='-')
    {
        if(tab[*escolhaL][*escolhaC]==tab[*escolhaL2][*escolhaC2])
        {
            --*posicoesOcultas;
            --*posicoesOcultas;
            system("cls");
            printf("\nVoce acertou!\n");
            tabVISIVEL[*escolhaL][*escolhaC]=tab[*escolhaL][*escolhaC];
            tabVISIVEL[*escolhaL2][*escolhaC2]=tab[*escolhaL2][*escolhaC2];
            visualizarTabuleiroJogo(tabVISIVEL, pQtdL, pQtdC);
        }
        else
        {
            system("cls");
            printf("\nVoce errou!\n");
            visualizarTabuleiro(tab, pQtdL, pQtdC);
            visualizarTabuleiroJogo(tabVISIVEL, pQtdL, pQtdC);
        }
    }

    else if (tabVISIVEL[*escolhaL][*escolhaC]!='-'||tabVISIVEL[*escolhaL2][*escolhaC2]!='-')
    {
        if (tabVISIVEL[*escolhaL][*escolhaC]!='-')
        {
            printf("\nA posição linha: %i coluna: %i  já foi revelada", *escolhaL+1, *escolhaC+1);
        }
        if (tabVISIVEL[*escolhaL2][*escolhaC2]!='-')
        {
            printf("\nA posição linha: %i coluna: %i  já foi revelada", *escolhaL2+1, *escolhaC2+1);
        }
    }


//toda rodada irá aparecer
    ++*jogadas;
    printf("\nSuas tentativas: %i\n", *jogadas);
    //printf("posições ocultas: %i\n", *posicoesOcultas);

//final do jogo
    if (*posicoesOcultas<=0)
    {
        if (*jogadas<=(*pontos*1.3))
        {
            printf("Parabéns! Você tem boa memória.");
        }
        if (*jogadas>(*pontos*1.3))
        {
            printf("Você precisa treinar mais sua memória");
        }
    }
}
int main()
{
    char tabuleiro[TAM_L][TAM_C];
    char letrasArray[19]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R'};
    int qtdL, qtdC, escolhaL=0, escolhaC=0, escolhaL2='\0', escolhaC2='\0', pontos, jogadas=0, posicoesOcultas;
    setlocale(LC_ALL, "Portuguese");

    regrasDoJogo();

    construirTabuleiro(tabuleiro, &qtdL, &qtdC, letrasArray);

    visualizarTabuleiro(tabuleiro, &qtdL, &qtdC);
    char tabVISIVEL[TAM_L][TAM_C];
    for(int l=0; l<qtdL; l++)
    {
        for (int c=0; c<qtdC; c++)
            tabVISIVEL[l][c]='-';
    }
    posicoesOcultas=pontos=qtdL*qtdC;

    while(posicoesOcultas>0)
    {
        pedirPosicoes(tabuleiro, &qtdL, &qtdC, &escolhaL, &escolhaC, &escolhaL2, &escolhaC2);

        contadorJogo(tabuleiro, &escolhaL, &escolhaC, &escolhaL2, &escolhaC2, &pontos, &jogadas, &posicoesOcultas, &qtdL, &qtdC, tabVISIVEL);

        if (posicoesOcultas==1)
        {
            posicoesOcultas=0;
        }

    }
    return 0;
}
