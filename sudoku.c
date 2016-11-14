//Caue Massi Correa 11079413
//Thamires Tecila de Souza XXXXXXXX
//Programacao Estruturada - Fabricio Olivetti
//Projeto: Sudoku

#include <stdio.h>
#include <stdlib.h>

#define MAX 9


void print_sudoku(int v[9][9],int n,int m){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf("%d ",v[i][j]);
		}
		printf("\n",v[i][j]);
	}
	
}

void preenche_sudoku(int v[9][9],int n,int m){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf("%d", &v[i][j]);
		}
	}
	
}

int main(){
	int sudoku[9][9];
	preenche_sudoku(sudoku, MAX, MAX);
	print_sudoku(sudoku, MAX, MAX);
	
	return 0;
}
