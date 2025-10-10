#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix {
    double **bloco;
	int nl,nc;
} Matrix;

void matrix_criar(Matrix *m, int lnh, int col);
void matrix_preencher(Matrix *m);
void matrix_set(Matrix *m, int lnh, int col, double n);
double matrix_get(Matrix *m, int lnh, int col);
Matrix matrix_soma(Matrix *m1, Matrix *m2);
Matrix matrix_sub(Matrix *m1, Matrix *m2);
Matrix matrix_mult(Matrix *m1, Matrix *m2);
Matrix matrix_esoma(Matrix *m, double e);
Matrix matrix_esub(Matrix *m, double e);
Matrix matrix_emult(Matrix *m, double e);
Matrix matrix_transp(Matrix *m);
Matrix matrix_inver(Matrix *m);
double matrix_deter(Matrix *m);
void matrix_mostrar(Matrix *m);

#endif