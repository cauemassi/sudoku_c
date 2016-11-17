#include <stdio.h>
#include <stdlib.h>

typedef struct quadrado{
	int mutavel;
	int num_possiveis[9];
	int valor_real;
	
} quadrado;

int verifica_linha(quadrado v[9][9], int n, int m, int num);
int verifica_coluna(quadrado v[9][9], int n, int m, int num);
int verifica_quadrado(quadrado v[9][9], int n, int m, int num);
void preenche_quadrado(quadrado v[9][9],int n,int m);
void print_vetor(int *vetor, int n);
void verifica_valores_possiveis(quadrado sudoku[9][9], int n, int m);
void print_quadrado(quadrado v[9][9],int n,int m);
void matriz_possiveis(quadrado matriz[9][9]);
void preenche_vetor(int *vetor, int n);
void print_quadrado_num_possiveis(quadrado matriz[9][9]);
void print_quadrado_valores(quadrado v[9][9],int n,int m);
int resolve_sudoku(quadrado matriz[9][9], int lin, int col);
void copia_solucao(quadrado sudoku);