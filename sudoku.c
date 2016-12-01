//Caue Massi Correa 11079413
//Thamires Tecila de Souza 11055613
//Programacao Estruturada - Fabricio Olivetti
//Projeto: Sudoku

#include "func.h"

#define MAX 9

int main(){
	quadrado sudoku[MAX][MAX];
	preenche_quadrado(sudoku, MAX, MAX);
	printf("Seu Sudoku é:\n");
	print_quadrado(sudoku,MAX,MAX);	
	matriz_possiveis(sudoku);
	resolve_sudoku(sudoku,0,0);
	return 0;
}


