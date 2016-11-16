#include <stdio.h>
#include <stdlib.h>

typedef struct quadrado{
	int mutavel;
	int *num_possiveis[9];
	int valor_real;
	
} quadrado;

int verifica_preenchido(int v[9][9], int n, int m);
int verifica_linha(int v[9][9], int n, int m, int num);
int verifica_coluna(int v[9][9], int n, int m, int num);
int verifica_quadrado(int v[9][9], int n, int m, int num);
void print_sudoku(int v[9][9],int n,int m);
void preenche_sudoku(int v[9][9],int n,int m);
void matriz_mutavel(int sudoku[9][9],quadrado matriz[9][9]);
void print_vetor(int **vetor, int n);
void verifica_valores_possiveis(int sudoku[9][9], int n, int m, int *num_possiveis);
void print_quadrado(quadrado v[9][9],int n,int m);
void matriz_possiveis(int sudoku[9][9], quadrado matriz[9][9]);
void preenche_vetor(int *vetor, int n);
void print_quadrado_num_possiveis(int sudoku[9][9], quadrado matriz[9][9]);
void print_quadrado_valores(quadrado v[9][9],int n,int m);
void resolve_sudoku(quadrado matriz[9][9], int lin, int col, int sudoku[9][9]);