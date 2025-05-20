#include   <stdio.h>

        /* Criação do jogo de movimentaão de peças de xadrez!
        Aqui usaremos 3 tipos de estruturas de repetição, uma para cada tipo de peça.
        Começando por "while" que permite uma execução repetitiva e controle sobre execução do código.
        Também usaremos a estrutura "do-while" assegura que o pedido de entrada seja feito pelo menos uma vez
        independente do valor da variável. E por fim, usaremos a estrutura "for" é ideal quando sabemos quantas vezes o programa
        será executado. 

        Atualização - Nível Aventureiro:
        Agora, vamos adicionar uma nova peça ao nosso tabuleiro: o **cavalo**.
        Sabemos que o cavalo é a única peça que pode pular outras, e sua movimentação em "L" é única.
        Para simular isso, usamos loops aninhados: um "while" externo e um "for" interno, representando os dois movimentos do cavalo. */


int main (){
        
    printf("======================================================================\n");
    printf("    >>>>>> MOVIMENTAÇÃO DE PEÇAS DE XADREZ - NIVEL AVENTUREIRO <<<<<\n");
    printf("======================================================================\n\n");

    printf("        >>>>>>>>>> Movimentação da peça: Torre <<<<<<<<<<\n");
    printf("             A torre acaba de se mover 5 casas \n");

    int torre = 0;  // variável da torre

    while (torre < 5)  // enquanto o movimento da torre for menor que 5, vai se repetir.
    {
        printf("Movendo a torre para a direita... passo %d\n", torre + 1);  // Imprime a direção do movimento começando pelo passo 1
        torre++; // incrementa +1 movimento
    }
    printf("\n");
    
    printf("       >>>>>>>>>> Movimentação da peça: Bispo <<<<<<<<<<\n ");
    printf("        O bispo acaba de se mover 5 casas na diagonal \n");
    int bispo = 0; // Variável da pela Bispo

    do
    {
            printf("Movendo o bispo na diagonal ↗ passo %d\n", bispo +1); // Imprime a direção do movimento // +1 para inicializar no passo 1, ficar mais legível.
        bispo++; // Incrementa +1 movimento

    } while (bispo < 5); // enquanto o movimento do bispo for menor 5, vai se repetir.
    printf("\n");

    printf("       >>>>>>>>>> Movimentação da peça: Rainha <<<<<<<<<<\n");
    printf("             A rainha acaba de se mover 8 casas\n");
    

    for (int rainha = 0; rainha < 8; rainha++) // rainha começa em 0 passos, a condição é que, enquanto o movimento for menor que 8 vai se repetir e vai incrementar +1 passo 
    {
        printf("Movendo a rainha para a esquerda... passo %d\n", rainha +1); // Imprime a direção da rainha, começando pelo passo 1
    }
    printf("\n");

    printf("       >>>>>>>>>> Movimentação da peça: Cavalo <<<<<<<<<<\n"); // Nova peça no tabuleiro
    printf("           O cavalo acaba de se mover 3 casas\n");  // Descrição do movimento da peça

    int movimentoEmL = 1; // Criei uma variável descritiva que informa o último passo da nossa peça, uma flag para controlar o movimento em 'L'

        while (movimentoEmL--)  // Aqui usei 'while' com decremento
        {
            for (int cavalo = 0; cavalo < 2; cavalo++) // O cavalo começará com 0 passos, e enquanto for menor que 2 ele vai repetir, e incrementar +1 movimento
            {
                printf("Movendo o cavalo para baixo... passo %d\n", cavalo +1);  // Imrprime a direção do cavalo, começando pelo passo 1 (fica mais legível assim)
            }
            printf("Movendo o cavalo para esquerda... passo %d\n", movimentoEmL +1); // Imprime o último movimento do cavalo, deixei começando em 1 pq é um novo movimento.
            
        }



    return 0;
}
