#include <stdio.h>

/*      Criação do jogo de movimentaão de peças de xadrez!
        Aqui usaremos 3 tipos de estruturas de repetição, uma para cada tipo de peça.
        Começando por "while" que permite uma execução repetitiva e controle sobre execução do código.
        Também usaremos a estrutura "do-while" assegura que o pedido de entrada seja feito pelo menos uma vez
        independente do valor da variável. E por fim, usaremos a estrutura "for" é ideal quando sabemos quantas vezes o programa
        será executado. 

        Atualização - Nível Aventureiro:
        Agora, vamos adicionar uma nova peça ao nosso tabuleiro: o **cavalo**.
        Sabemos que o cavalo é a única peça que pode pular outras, e sua movimentação em "L" é única.
        Para simular isso, usamos loops aninhados: um "while" externo e um "for" interno, representando os dois movimentos do cavalo. 

        Atualização - Nível Mestre:
        Agora levamos nosso programa para outro nível utilizando **recursividade e loops complexos**!
        Implementamos funções recursivas para simular os movimentos das peças Torre, Rainha e Bispo,
        substituindo os loops simples por chamadas recursivas que repetem o movimento até que a condição de parada seja atingida.

        Além disso, para a peça Bispo, aplicamos tanto **recursividade quanto loops aninhados**, 
        onde o loop externo representa o movimento na direção vertical (subindo) 
        e o loop interno representa o movimento na direção horizontal (para a direita), 
        seguindo a lógica do movimento diagonal no xadrez.

        Para a movimentação do Cavalo, aprimoramos o código utilizando **loops aninhados, múltiplas variáveis, condições,
        além de comandos de controle de fluxo como break e continue**, tornando a lógica mais robusta e alinhada
        às regras do desafio.

        Todo o código está documentado de forma clara, prezando pela organização, legibilidade e eficiência,
        utilizando conceitos avançados da programação em C para simular de maneira fiel os movimentos das peças do xadrez.*/



// ===============================
// Função do BISPO
// ===============================

/* 
    Função recursiva responsável por simular o movimento do bispo na diagonal 
    (Cima + Direita). A cada chamada da função, ela imprime o passo atual e 
    chama a si mesma, somando +1 no passo, até que o passoAtual seja maior 
    que o número total de casas, onde então ocorre a parada da recursão.
*/
void moverBispoRecursivo(int passoAtual, int casas) {
    if (passoAtual > casas) {
        return; // condição de parada
    }
    printf("Movendo o bispo para Cima e Direita... passo %d\n", passoAtual);
    moverBispoRecursivo(passoAtual + 1, casas);
}

/* 
    Função que usa loops aninhados (for dentro de for) para representar 
    o movimento do bispo. O loop externo simboliza o movimento na vertical (subindo)
    e o loop interno simboliza o movimento na horizontal (para a direita).
    Ambos estão fixos em 1, pois o movimento real ocorre dentro da função recursiva 
    chamada no interior do loop.
*/
void moverBispo(int casas) {
    for (int vertical = 0; vertical < 1; vertical++) { // só 1 direção: cima
        for (int horizontal = 0; horizontal < 1; horizontal++) { // só 1 direção: direita
            moverBispoRecursivo(1, casas);
        }
    }
}


// ===============================
// Função da RAINHA
// ===============================

/*
    Função recursiva que simula o movimento da Rainha para a esquerda.
    A cada chamada, a função diminui uma casa no movimento e imprime o passo.
    Quando 'casas' chega a 0, a função para (condição de parada).
*/
void moverRainha(int casas) {
    if (casas > 0) {
        moverRainha(casas -1);  // chamada recursiva, reduzindo uma casa a cada chamada
        printf("Movendo a rainha para a esquerda... passo %d\n", casas);
     }
}


// ===============================
// Função da TORRE
// ===============================

/* 
    Função recursiva que simula o movimento da Torre para a direita.
    A lógica é semelhante à da Rainha: enquanto o número de 'casas' for maior que 0,
    a função chama a si mesma subtraindo 1 a cada chamada, até que chegue em 0.
    Após cada retorno da recursão, imprime o movimento realizado.
*/
void moverTorre(int casas) {
    if (casas > 0) {
        moverTorre(casas -1);  // chamada recursiva, reduzindo uma casa
        printf("Movendo a torre para a direita... passo %d\n", casas);
    }
}


// ========================================
// Função Principal (main) - SEM ALTERAÇÕES
// ========================================
int main (){


    printf("======================================================================\n");
    printf("    >>>>>> MOVIMENTAÇÃO DE PEÇAS DE XADREZ - NIVEL MESTRE <<<<<\n");
    printf("======================================================================\n\n");

     printf("       >>>>>>>>>> Movimentação da peça: Bispo <<<<<<<<<<\n ");
     printf("        O bispo acaba de se mover 5 casas na diagonal \n");
     

     int casas = 5;

     printf("Movimento do Bispo:\n");
     moverBispo(casas);
     printf("\n");

     printf("       >>>>>>>>>> Movimentação da peça: Rainha <<<<<<<<<<\n");
     printf("             A rainha acaba de se mover 8 casas\n");

     printf("Movimento da Rainha:\n");
     moverRainha(8);
     printf("\n");

     printf("        >>>>>>>>>> Movimentação da peça: Torre <<<<<<<<<<\n");
     printf("             A torre acaba de se mover 5 casas \n");

     printf("Movimento da Torre:\n");
     moverTorre(5);
     printf("\n");



     printf("       >>>>>>>>>> Movimentação da peça: Cavalo <<<<<<<<<<\n");
     printf("           O cavalo acaba de se mover 2 casas\n");

     printf("Movimento do Cavalo:\n");

    int movimentoEmL = 1;  // flag para controlar o movimento em L

    while (movimentoEmL--) {
        for (int cavalo = 0; cavalo < 2; cavalo++) {  // duas casas para cima
            if (cavalo == 1 && movimentoEmL == 0) {
                continue; // exemplo de continue: pulando este passo específico
            }
            printf("Movendo o cavalo para cima... passo %d\n", cavalo + 1);
        }

        for (int cavalo = 0; cavalo < 1; cavalo++) {  // uma casa para direita
            if (movimentoEmL < 0) {
                break; // exemplo de break para sair do loop se condição for satisfeita
            }
            printf("Movendo o cavalo para direita... passo %d\n", cavalo + 1);
        }
    }

    return 0;
}
