#include <stdio.h>

typedef struct quadrado{
	int mutavel;
	int num_possiveis[9];
	int valor_real;
	
} quadrado;


int verifica_linha(quadrado v[9][9], int n, int m, int num){
	int i;
	for(i = 0; i < 9; i++){
		if(v[i][m].valor_real == num && i != n) return 0;
	}
	return 1;
}

int verifica_coluna(quadrado v[9][9], int n, int m, int num){
	int i;
	for(i = 0; i < 9; i++){
		if(v[n][i].valor_real == num && i != m) return 0;
	}
	return 1;
}

int verifica_quadrado(quadrado v[9][9], int n, int m, int num){
	 int i, j;
    for (i=(n/3)*3; i<((n/3)+1)*3; i++){
        for (j=(m/3)*3; j<((m/3)+1)*3; j++){
			if(i != n && j != m && v[i][j].valor_real == num) return 0;
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
				printf("%d|",v[i][j].valor_real);
			}
			else{
				printf("%d ",v[i][j].valor_real);
			}
		}
		if((i+1)%3 == 0) printf("\n ------------------ ");
		printf("\n",v[i][j].valor_real);
	}	
}


void preenche_quadrado(quadrado v[9][9],int n,int m){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf("%d", &v[i][j].valor_real);
			if(v[i][j].valor_real) v[i][j].mutavel = 0;
			else v[i][j].mutavel = 1;
		}
	}	
}

void print_vetor(int *vetor, int n){
	int i;
	for (i = 0; i < n; i ++){
		printf("%d ",vetor[i]);
	}
	printf("\n");
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

void matriz_possiveis(quadrado matriz[9][9]){
	int i, j, k = 0;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			preenche_vetor(matriz[i][j].num_possiveis, 9);	
			if(matriz[i][j].mutavel) verifica_valores_possiveis(matriz, i, j);
		}
	}
}

void print_quadrado_num_possiveis(quadrado matriz[9][9]){
	int i, j, k = 0;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){			
			printf("Printando vetor da linha %d coluna %d de numeros possiveis\n",i, j);		
			print_vetor(matriz[i][j].num_possiveis, 9);			
		}
	}
}


void resolve_sudoku(quadrado matriz[9][9], int lin, int col){
	//printf("Comecando a resolver! Com linha %d e coluna %d\n", lin, col);
	if(lin == 9 ){
		printf("EUREKA! Sudoku resolvido!\n");
		print_quadrado(matriz,9,9);	
		return;
	}
	int k;		
	if(matriz[lin][col].mutavel){
		for(k = 0; matriz[lin][col].num_possiveis[k] != 0; k++){
			if(	verifica_coluna(matriz, lin, col, matriz[lin][col].num_possiveis[k]) &&
				verifica_linha(matriz, lin, col, matriz[lin][col].num_possiveis[k]) &&
				verifica_quadrado(matriz, lin, col, matriz[lin][col].num_possiveis[k])){
					matriz[lin][col].valor_real = matriz[lin][col].num_possiveis[k];
					if(col == 8) resolve_sudoku(matriz,lin+1,0); 
					else resolve_sudoku(matriz, lin, col+1);
			}			
		}
		matriz[lin][col].valor_real = 0;
	}
	else{
		if(col == 8) resolve_sudoku(matriz,lin+1,0);
		else resolve_sudoku(matriz, lin, col+1);
	}		
	
}
