//Caue Massi Correa 11079413
//Thamires Tecila de Souza XXXXXXXX
//Programacao Estruturada - Fabricio Olivetti
//Projeto: Sudoku

#include "func.h"

#define MAX 9

int main(){
	int sudoku[9][9];
	quadrado matriz[9][9];
	preenche_sudoku(sudoku, MAX, MAX);
	matriz_mutavel(sudoku, matriz);
	print_quadrado_valores(matriz,MAX,MAX);
	matriz_possiveis(sudoku, matriz);
	resolve_sudoku(matriz,0,0,sudoku);
	print_quadrado_valores(matriz,MAX,MAX);
	
	return 0;
}
