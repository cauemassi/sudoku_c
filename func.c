//Caue Massi Correa 11079413
//Thamires Tecila de Souza 11055613
//Programacao Estruturada - Fabricio Olivetti
//Projeto: Sudoku

#include <stdio.h>

typedef struct quadrado{
	int mutavel;
	int num_possiveis[9];
	int valor;
	
} quadrado;


int verifica_linha(quadrado v[9][9], int n, int m, int num){
	int i;
	for(i = 0; i < 9; i++){
		if(v[i][m].valor == num && i != n) return 0;
	}
	return 1;
}

int verifica_coluna(quadrado v[9][9], int n, int m, int num){
	int i;
	for(i = 0; i < 9; i++){
		if(v[n][i].valor == num && i != m) return 0;
	}
	return 1;
}

int verifica_quadrado(quadrado v[9][9], int n, int m, int num){
	 int i, j;
    for (i=(n/3)*3; i<((n/3)+1)*3; i++){
        for (j=(m/3)*3; j<((m/3)+1)*3; j++){
			if(i != n && j != m && v[i][j].valor == num) return 0;
        }
    }
	return 1;
}

void print_quadrado(quadrado v[9][9],int n,int m){
	int i, j;
	printf(" ------------------ \n");
	for(i = 0; i < n; i++){
		printf("|");
		for(j = 0; j < m; j++){
			if((j+1)%3 == 0){
				printf("%d|",v[i][j].valor);
			}
			else{
				printf("%d ",v[i][j].valor);
			}
		}
		if((i+1)%3 == 0) printf("\n ------------------ ");
		printf("\n");
	}	
}


void preenche_quadrado(quadrado v[9][9],int n,int m){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf("%d", &v[i][j].valor);
			if(v[i][j].valor) v[i][j].mutavel = 0;
			else v[i][j].mutavel = 1;
		}
	}	
}


void verifica_valores_possiveis(quadrado sudoku[9][9], int n, int m){
	int i, k = 0;
	for(i = 1; i < 10; i++){
		if(	verifica_coluna(sudoku, n, m, i) &&
			verifica_linha(sudoku, n, m, i) &&
			verifica_quadrado(sudoku, n, m, i))
				sudoku[n][m].num_possiveis[k++] = i;		
	}
}

void preenche_vetor(int *vetor, int n){
	int i;
	for(i = 0; i < n; i ++) vetor[i] = 0;	
}

void matriz_possiveis(quadrado sudoku[9][9]){
	int i, j, k = 0;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			preenche_vetor(sudoku[i][j].num_possiveis, 9);	
			if(sudoku[i][j].mutavel) verifica_valores_possiveis(sudoku, i, j);
		}
	}
}


void resolve_sudoku(quadrado sudoku[9][9], int lin, int col){
	if(lin == 9 ){
		printf("EUREKA! Sudoku resolvido!\n");
		print_quadrado(sudoku,9,9);	
		return;
	}
	int k;		
	if(sudoku[lin][col].mutavel){
		for(k = 0; sudoku[lin][col].num_possiveis[k] != 0; k++){
			if(	verifica_coluna(sudoku, lin, col, sudoku[lin][col].num_possiveis[k]) &&
				verifica_linha(sudoku, lin, col, sudoku[lin][col].num_possiveis[k]) &&
				verifica_quadrado(sudoku, lin, col, sudoku[lin][col].num_possiveis[k])){
					sudoku[lin][col].valor = sudoku[lin][col].num_possiveis[k];
					if(col == 8) resolve_sudoku(sudoku,lin+1,0); 
					else resolve_sudoku(sudoku, lin, col+1);
			}			
		}
		sudoku[lin][col].valor = 0;
	}
	else{
		if(col == 8) resolve_sudoku(sudoku,lin+1,0);
		else resolve_sudoku(sudoku, lin, col+1);
	}		
	
}
