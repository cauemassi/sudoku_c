#include <stdio.h>

typedef struct quadrado{
	int mutavel;
	int num_possiveis[9];
	int valor_real;
	
} quadrado;

int verifica_preenchido(int v[9][9], int n, int m){
	if(v[n][m] != 0) return 1;
	return 0;
}

int verifica_linha(int v[9][9], int n, int m, int num){
	int i;
	for(i = 0; i < 9; i++){
		if(v[i][m] == num && i != n) return 0;
	}
	return 1;
}

int verifica_coluna(int v[9][9], int n, int m, int num){
	int i;
	for(i = 0; i < 9; i++){
		if(v[n][i] == num && i != m) return 0;
	}
	return 1;
}

int verifica_quadrado(int v[9][9], int n, int m, int num){
	 int i, j;
    for (i=(n/3)*3; i<((n/3)+1)*3; i++){
        for (j=(m/3)*3; j<((m/3)+1)*3; j++){
			if(i != n && j != m && v[i][j] == num) return 0;
        }
    }
	return 1;
}

void print_sudoku(int v[9][9],int n,int m){
	int i, j;
	printf(" ------------------ \n");
	for(i = 0; i < n; i++){
		printf("|");
		for(j = 0; j < m; j++){
			if((j+1)%3 == 0){
				printf("%d|",v[i][j]);
			}
			else{
				printf("%d ",v[i][j]);
			}
		}
		if((i+1)%3 == 0) printf("\n ------------------ ");
		printf("\n",v[i][j]);
	}
	
	
}

void print_quadrado(quadrado v[9][9],int n,int m){
	int i, j;
	printf(" ------------------ \n");
	for(i = 0; i < n; i++){
		printf("|");
		for(j = 0; j < m; j++){
			if((j+1)%3 == 0){
				printf("%d|",v[i][j].mutavel);
			}
			else{
				printf("%d ",v[i][j].mutavel);
			}
		}
		if((i+1)%3 == 0) printf("\n ------------------ ");
		printf("\n",v[i][j].mutavel);
	}	
}
void print_quadrado_valores(quadrado v[9][9],int n,int m){
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


void preenche_sudoku(int v[9][9],int n,int m){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf("%d", &v[i][j]);
		}
	}	
}

void matriz_mutavel(int sudoku[9][9],quadrado matriz[9][9]){
	int i, j;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			matriz[i][j].valor_real = sudoku[i][j];
			if(sudoku[i][j] != 0){
				matriz[i][j].mutavel = 1;
			}
			else{
				matriz[i][j].mutavel = 0;
			}
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

void verifica_valores_possiveis(int sudoku[9][9], int n, int m, int *num_possiveis){
	int i, k = 0;
	for(i = 0; i < 9; i++){
		if(	verifica_coluna(sudoku, n, m, i) &&
			verifica_linha(sudoku, n, m, i) &&
			verifica_quadrado(sudoku, n, m, i))
				num_possiveis[k++] = i;		
	}
}

void preenche_vetor(int *vetor, int n){
	int i;
	for(i = 0; i < n; i ++) vetor[i] = 0;	
}

void matriz_possiveis(int sudoku[9][9], quadrado matriz[9][9]){
	int i, j, k = 0;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){			
			preenche_vetor(matriz[i][j].num_possiveis, 9);		
			if(!matriz[i][j].mutavel){
				verifica_valores_possiveis(
					sudoku, i, j, matriz[i][j].num_possiveis);
			}
		}
	}
}

void print_quadrado_num_possiveis(int sudoku[9][9], quadrado matriz[9][9]){
	int i, j, k = 0;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){			
			printf("Printando vetor da linha %d coluna %d de numeros possiveis\n",i, j);		
			print_vetor(matriz[i][j].num_possiveis, 9);			
		}
	}
}

void resolve_sudoku(quadrado matriz[9][9], int lin, int col, int sudoku[9][9]){
	printf("Comecando a resolver! Com linha %d e coluna %d\n", lin, col);
	int t;
	if(lin == 9) printf("Sudoku Resolvido!\n");
	else{
		int k = 0;
		printf("Entrou aqui\n");
		while(matriz[lin][col].num_possiveis[k] != 0){
			if(	verifica_coluna(sudoku, lin, col, matriz[lin][col].num_possiveis[k]) &&
			verifica_linha(sudoku, lin, col, matriz[lin][col].num_possiveis[k]) &&
			verifica_quadrado(sudoku, lin, col, matriz[lin][col].num_possiveis[k])){
				t = matriz[lin][col].num_possiveis[k];
				matriz[lin][col].valor_real = matriz[lin][col].num_possiveis[k];
				if(col == 8) resolve_sudoku(matriz,lin+1,0,sudoku);
				else resolve_sudoku(matriz, lin, col+1,sudoku);
				matriz[lin][col].num_possiveis[k] = t;			
			}
			k++;
		}
	}
}
