
/*Faça um programa em C, que seja divido em funções, com passagem de
parâmetros para realizar o jogo de batalha naval versão alfa. Na batalha
naval versão alfa, há dois jogadores e dois tabuleiros com dimensão 10x10
e conta com as seguintes fases realizadas na sequï¿½ncia.

a. Fase de inicialização: Inicialmente cada tabuleiro deve ser zerado (
colocando todas as posições em zero),

b. Fase de distribuição dos navios: Cada jogador determina onde seus
dez navios estão, mencionando a coluna e linha a ser preenchida
(sugiro valor 1) no seu respectivo tabuleiro. O jogador 1 pode ter
navio na mesma posição do jogador 2, já que estão em tabuleiros
diferentes.O preenchimento do tabuleiro não precisa ser alternando,
ou seja pode ser lido todo o tabuleiro do jogador 1 e depois o
tabuleiro do jogador 2.

c. Fase de ataque: cada jogador alternadamente indica uma célula de
ataque no tabuleiro oponente ( mencionando a linha e a coluna de
ataque), o programa então deve avaliar se o jogador conseguiu
acertar um navio no tabuleiro do oponente e contabilizar a pontuação.
Cada acerto vale 1 ponto. Ganha o jogo quem acertar todos os navios
do jogador oponente primeiro (ou seja, quem fizer 10 pontos
primeiro). Caso os dois jogadores alcancem os dez pontos na mesma
jogada, então haverá empate.*/


#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#include <ctype.h>//toupper(var)

struct jogador{
	
    char nome[30];
    int pontos = 0;
    int tabuleiro[10][10] = 
        {{0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0}};
         
}typedef jogador;


jogador jogadores[2];
	

void faseAtaque(){
	
	int c=0, i=0, j=0, linha;
	char coluna, letras[10]={'A','B','C','D','E','F','G','H','I','J'};
	
	printf("======================\n");
	printf("||||Fase de ataque||||\n");
	printf("======================\n");
	
	for(c=0; c<16; c++){
		
		for(j=0; j<16; j++){
			
			if(j%2==0){
				//vez do jogador 1
				fflush(stdin);
				printf("Jogador %s é a sua vez!\n", jogadores[0].nome);
				printf("\nDigite a posição do navio %d: ", c+1);
				scanf("%d %c", &linha, &coluna);
				fflush(stdin);
				
				for(i=0; i<10; i++){
					
					if(toupper(coluna) == letras[i]){
						
						if(jogadores[1].tabuleiro[linha-1][i] == 1){
							
							jogadores[0].pontos++;
							jogadores[1].tabuleiro[linha-1][i] = 0;
							printf("%s marcou 1 ponto\n", jogadores[0].nome);
							
						}else{
							
							printf("%s não marcou ponto\n", jogadores[0].nome);
							
						}
					}
				}
				
				puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				
			}else{
				//vez do jogador 2
				fflush(stdin);
				printf("Jogador %s é a sua vez!\n", jogadores[1].nome);
				printf("\nDigite a posição do navio %d: ", c+1);
				scanf("%d %c", &linha, &coluna);
				fflush(stdin);
				
				for(i=0; i<10; i++){
					
					if(toupper(coluna) == letras[i]){
						
						if(jogadores[0].tabuleiro[linha-1][i] == 1){
							
							jogadores[1].pontos++;
							jogadores[0].tabuleiro[linha-1][i] = 0;
							printf("%s marcou 1 ponto\n", jogadores[1].nome);
							
						}else{
							
							printf("%s não marcou ponto\n", jogadores[1].nome);
							
						}
					}
				}
				
				puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				
				
				if(jogadores[1].pontos==10 && jogadores[0].pontos==10){//empate
					printf("\n\nOs dois jogadores ganharam\n\n", jogadores[1].nome, jogadores[1].pontos);
					c=16;
					j=16;
				}else if(jogadores[0].pontos==10){//jogador 1 ganhou
					printf("\n\n%s ganhou com %d pontos!!!!!\n\n", jogadores[0].nome, jogadores[0].pontos);
					c=16;
					j=16;
				}else if(jogadores[1].pontos==10){//jogador 2 ganhou
					printf("\n\n%s ganhou com %d pontos!!!!!\n\n", jogadores[1].nome, jogadores[1].pontos);
					c=16;
					j=16;
				}
			}
		}
	}
	
	
}

void mostrarTabuleiro(int n){
	
    int c = 0, i = 0;
    
    for(c=0; c<10; c++){
    	
    	if(c==0){
    		
    		printf("\n\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ");
    		printf("\n     _______________________________________________________________________________");
		}
		
		if(c+1==10){
			
    		printf("\n %d |", c+1);
    		
		}else{
			
    		printf("\n %d  |", c+1);
    		
		}
    	for(i=0; i<10; i++){
    		
    		printf("   %d   |", jogadores[n].tabuleiro[c][i]);
    		
		}
	}
	
	printf("\n");
	
}

void cadastrarTabuleiro(int n){
		
	int linha, c=0, i=0;
    char coluna, letras[10]={'A','B','C','D','E','F','G','H','I','J'};
	
	printf("\n\n\nExemplo: 1 A\nSempre linha e coluna com espaço entre.\n");
	
	for(c=0; c<10; c++){
		
		fflush(stdin);
		printf("\nDigite a posição do navio %d: ", c+1);
		scanf("%d %c", &linha, &coluna);
		fflush(stdin);
		
		puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		
		for(i=0; i<10; i++){
			
			if(toupper(coluna) == letras[i]){
				
				if(jogadores[n].tabuleiro[linha-1][i] == 1){
					
					printf("=============================================");
					printf("\n||||Você já colocou um navio neste local!||||\n");
					printf("=============================================");
					c--;
					
				}else{
					
					jogadores[n].tabuleiro[linha-1][i] = 1;
					
				}
			}
		}
		mostrarTabuleiro(n);
	}
		
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    
    //cadastrando jogador 2
    printf("Digite seu nome: ");
    scanf("%s", &jogadores[0].nome);
    printf("Bem vindo %s! vamos escolher onde você vai colocar seus navios de batalha!\n", jogadores[0].nome);
    printf("\n0 = Água\n1 = Navio\n");
    
    /*
    for(w=0; w<10; w++){
		for(z=0; z<10; z++){
			if(w==0){
				jogador1.tabuleiro[w][z] = 1;
			}else{
				jogador1.tabuleiro[w][z] = 0;
			}
		}
	}
	*/
	
	mostrarTabuleiro(0);
    cadastrarTabuleiro(0);
    
    //cadastrando jogador 2
    printf("Digite seu nome: ");
    scanf("%s", &jogadores[1].nome);
    printf("Bem vindo %s! vamos escolher onde você vai colocar seus navios de batalha!\n", jogadores[1].nome);
    printf("\n0 = Água\n1 = Navio\n");
    
	/*
	for(w=0; w<10; w++){
		for(z=0; z<10; z++){
			if(w==0){
				jogador2.tabuleiro[w][z] = 1;
			}else{
				jogador2.tabuleiro[w][z] = 0;
			}
		}
	}*/
	
	mostrarTabuleiro(1);
    cadastrarTabuleiro(1);
    
    
    faseAtaque();
    
	
	return 0;
	
}
