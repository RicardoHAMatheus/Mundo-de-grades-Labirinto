/* Projeto Desenvolvimento de Algoritmos - Mundo de grades: Labirinto
    Ricardo Henrique Avelar Matheus
    15.118.334-0
*/
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

void gerarLabirinto(int lab[12][12]){
    // geraração do labirinto
    int base[12][12] = {
        {1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,1,1,0,0,0,0,0,1},
        {1,0,1,0,0,0,0,1,1,1,0,0},
        {1,1,1,1,1,1,0,0,1,0,1,1},
        {0,0,0,0,0,0,1,0,0,0,1,1},
        {1,1,1,1,1,0,1,0,1,1,1,1},
        {1,0,0,0,1,0,1,0,0,0,0,1},
        {1,0,1,0,1,0,1,0,1,1,0,1},
        {1,1,1,0,0,0,1,1,0,1,0,1},
        {1,0,1,0,1,1,1,1,0,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1}
    };
    for (int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            lab[i][j] = base [i][j];
        }
    }
    return (lab);
}

void percorrerLabirinto(int lab[12][12]){
    // inicio do agente:
	int num_linha = 4;
	int num_coluna = 0;
    lab[num_linha][num_coluna] = 2;
    // direção do agente:
    // 0 = direita
    // 1 = cima
    // 2 = esquerda
    // 3 = baixo
    int dir = 0;
    
    // labirinto inicial
    printf("\n");
    for (int i = 0; i < 12; i++) {
        printf("  ");
        for (int j = 0; j < 12; j++)
            if (lab[i][j] == 1){
                printf(" %c",219);
            }
            else if (lab[i][j] == 2){
                printf(" +");
            }
            else{
                printf(" .");
            }
        printf("\n");
    }
    printf("\n");

    // loop infinito
    while(1){
        // atualiza a cada 1 seg (1000 mseg)
        Sleep(1000);

        // Se direcionado para direita
        if(dir == 0){
            // Andar p/ baixo
            if (lab[num_linha+1][num_coluna] == 0 || lab[num_linha+1][num_coluna] == 2 || lab[num_linha+1][num_coluna] == 3 ){
                num_linha = num_linha+1;
                if (lab[num_linha][num_coluna] == 0){
                    lab[num_linha][num_coluna] = 2;
                }
                else {
                    lab[num_linha][num_coluna] = 3;
                }
                dir = 3;
            }
            // Andar p/ direita
            else if (lab[num_linha][num_coluna+1] == 0 || lab[num_linha][num_coluna+1] == 2 || lab[num_linha][num_coluna+1] == 3 ){
                num_coluna = num_coluna+1;
                if (lab[num_linha][num_coluna] == 0){
                    lab[num_linha][num_coluna] = 2;
                }
                else {
                    lab[num_linha][num_coluna] = 3;
                }
                dir = 0;
            }
            // Andar p/ cima
            else if (lab[num_linha-1][num_coluna] == 0 || lab[num_linha-1][num_coluna] == 2 || lab[num_linha-1][num_coluna] == 3 ){
                num_linha = num_linha-1;
                if (lab[num_linha][num_coluna] == 0){
                    lab[num_linha][num_coluna] = 2;
                }
                else {
                    lab[num_linha][num_coluna] = 3;
                }
                dir = 1;
            }
            // Andar p/ esquerda
            else if (lab[num_linha][num_coluna-1] == 0 || lab[num_linha][num_coluna-1] == 2 || lab[num_linha][num_coluna-1] == 3 ){
                num_coluna = num_coluna-1;
                if (lab[num_linha][num_coluna] == 0){
                    lab[num_linha][num_coluna] = 2;
                }
                else {
                    lab[num_linha][num_coluna] = 3;
                }
                dir = 2;
            }
        }
        // Se direcionado para cima
        else if(dir == 1){
            // Andar p/ direita
            if (lab[num_linha][num_coluna+1] == 0 || lab[num_linha][num_coluna+1] == 2 || lab[num_linha][num_coluna+1] == 3 ){
                num_coluna = num_coluna+1;
                if (lab[num_linha][num_coluna] == 0){
                    lab[num_linha][num_coluna] = 2;
                }
                else {
                    lab[num_linha][num_coluna] = 3;
                }
                dir = 0;
            }
            // Andar p/ cima
            else if (lab[num_linha-1][num_coluna] == 0 || lab[num_linha-1][num_coluna] == 2 || lab[num_linha-1][num_coluna] == 3 ){
                num_linha = num_linha-1;
                if (lab[num_linha][num_coluna] == 0){
                    lab[num_linha][num_coluna] = 2;
                }
                else {
                    lab[num_linha][num_coluna] = 3;
                }
                dir = 1;
            }
            // Andar p/ esquerda
            else if (lab[num_linha][num_coluna-1] == 0 || lab[num_linha][num_coluna-1] == 2 || lab[num_linha][num_coluna-1] == 3 ){
                num_coluna = num_coluna-1;
                if (lab[num_linha][num_coluna] == 0){
                    lab[num_linha][num_coluna] = 2;
                }
                else {
                    lab[num_linha][num_coluna] = 3;
                }
                dir = 2;
            }
            // Andar p/ baixo
            else if (lab[num_linha+1][num_coluna] == 0 || lab[num_linha+1][num_coluna] == 2 || lab[num_linha+1][num_coluna] == 3 ){
                num_linha = num_linha+1;
                if (lab[num_linha][num_coluna] == 0){
                    lab[num_linha][num_coluna] = 2;
                }
                else {
                    lab[num_linha][num_coluna] = 3;
                }
                dir = 3;
            }
        }
        // Se direcionado para esquerda
        else if(dir == 2){
            // Andar p/ cima
            if (lab[num_linha-1][num_coluna] == 0 || lab[num_linha-1][num_coluna] == 2 || lab[num_linha-1][num_coluna] == 3 ){
                num_linha = num_linha-1;
                if (lab[num_linha][num_coluna] == 0){
                    lab[num_linha][num_coluna] = 2;
                }
                else {
                    lab[num_linha][num_coluna] = 3;
                }
                dir = 1;
            }
            // Andar p/ esquerda
            else if (lab[num_linha][num_coluna-1] == 0 || lab[num_linha][num_coluna-1] == 2 || lab[num_linha][num_coluna-1] == 3 ){
                num_coluna = num_coluna-1;
                if (lab[num_linha][num_coluna] == 0){
                    lab[num_linha][num_coluna] = 2;
                }
                else {
                    lab[num_linha][num_coluna] = 3;
                }
                dir = 2;
            }
            // Andar p/ baixo
            else if (lab[num_linha+1][num_coluna] == 0 || lab[num_linha+1][num_coluna] == 2 || lab[num_linha+1][num_coluna] == 3 ){
                num_linha = num_linha+1;
                if (lab[num_linha][num_coluna] == 0){
                    lab[num_linha][num_coluna] = 2;
                }
                else {
                    lab[num_linha][num_coluna] = 3;
                }
                dir = 3;
            }
            // Andar p/ direita
            else if (lab[num_linha][num_coluna+1] == 0 || lab[num_linha][num_coluna+1] == 2 || lab[num_linha][num_coluna+1] == 3 ){
                num_coluna = num_coluna+1;
                if (lab[num_linha][num_coluna] == 0){
                    lab[num_linha][num_coluna] = 2;
                }
                else {
                    lab[num_linha][num_coluna] = 3;
                }
                dir = 0;
            }
        }
        // Se direcionado para baixo
        else if(dir == 3){
            // Andar p/ esquerda
            if (lab[num_linha][num_coluna-1] == 0 || lab[num_linha][num_coluna-1] == 2 || lab[num_linha][num_coluna-1] == 3 ){
                num_coluna = num_coluna-1;
                if (lab[num_linha][num_coluna] == 0){
                    lab[num_linha][num_coluna] = 2;
                }
                else {
                    lab[num_linha][num_coluna] = 3;
                }
                dir = 2;
            }
            // Andar p/ baixo
            else if (lab[num_linha+1][num_coluna] == 0 || lab[num_linha+1][num_coluna] == 2 || lab[num_linha+1][num_coluna] == 3 ){
                num_linha = num_linha+1;
                if (lab[num_linha][num_coluna] == 0){
                    lab[num_linha][num_coluna] = 2;
                }
                else {
                    lab[num_linha][num_coluna] = 3;
                }
                dir = 3;
            }
            // Andar p/ direita
            else if (lab[num_linha][num_coluna+1] == 0 || lab[num_linha][num_coluna+1] == 2 || lab[num_linha][num_coluna+1] == 3 ){
                num_coluna = num_coluna+1;
                if (lab[num_linha][num_coluna] == 0){
                    lab[num_linha][num_coluna] = 2;
                }
                else {
                    lab[num_linha][num_coluna] = 3;
                }
                dir = 0;
            }
            // Andar p/ cima
            else if (lab[num_linha-1][num_coluna] == 0 || lab[num_linha-1][num_coluna] == 2 || lab[num_linha-1][num_coluna] == 3 ){
                num_linha = num_linha-1;
                if (lab[num_linha][num_coluna] == 0){
                    lab[num_linha][num_coluna] = 2;
                }
                else {
                    lab[num_linha][num_coluna] = 3;
                }
                dir = 1;
            }
        }
        // impressao do labirinto com o agente trocando os inteiros pelos caracteres char:
        printf("\n");
        for (int i = 0; i < 12; i++) {
	        printf("  ");
	        for (int j = 0; j < 12; j++)
	            if (lab[i][j] == 1){
					printf(" %c",219);
				}
				else if(lab[i][j] == 2){
					printf(" +");
				}
				else if(lab[i][j] == 3){
					printf(" x");
				}
				else{
					printf(" .");
				}
	        printf("\n");
        }
        printf("\n");

        // Chegada!!!
        if ( num_linha == 2 && num_coluna == 11){
            printf(" Labirinto finalizado!!!\n");
            break;
        }
    }

}

int main(void){
    int lab[12][12] = {};
    gerarLabirinto(lab);
    percorrerLabirinto(lab);
    return(0);
}
