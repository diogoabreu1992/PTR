#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#define m0 ((Matrix){ .bloco = NULL, .nl = 0, .nc = 0 })

void matrix_criar(Matrix *m, int lnh, int col){ 
    m->nl = lnh;
    m->nc = col;
    m->bloco = (double **)malloc(lnh * sizeof(double *));
    for(int i = 0; i<lnh; i++){
        m->bloco[i] = (double *)malloc(col * sizeof(double));
    }
}

void matrix_preencher(Matrix *m){
    for (int i = 0; i < m->nl; i++){
        for (int j = 0; j < m->nc; j++){
            scanf("%lf",&m->bloco[i][j]);
        }
    }
}

void matrix_set(Matrix *m, int l, int c, double n){ 
    if((l>m->nl)||(l<0)||(c>m->nc)||(c<0)){
        printf("Error: Indices invalidos\n");
    }else{
        m->bloco[l][c] = n;
    }
}

double matrix_get(Matrix *m, int l, int c){ 
    if((l>m->nl)||(l<0)||(c>m->nc)||(c<0)){
        printf("Error: Indices invalidos\n");
        return 0.0;
    }else{
        return m->bloco[l][c];
    }
}

Matrix matrix_soma(Matrix *m1, Matrix *m2){
    Matrix msoma;
    matrix_criar(&msoma,m1->nl,m1->nc);
    if((m1->nc==m2->nc)&&(m1->nl==m2->nl)){
        for(int i=0; i<m1->nl; i++){
            for(int j=0; j<m1->nc; j++){
                msoma.bloco[i][j] = m1->bloco[i][j] + m2->bloco[i][j];
            }
        }
    }else{
        printf("Error: Não é possivel somar matrizes de dimensões diferentes.\n ");
        return m0;
    }
    return msoma;
}

Matrix matrix_sub(Matrix *m1, Matrix *m2){
    Matrix msub;
    matrix_criar(&msub,m1->nl,m1->nc);
    if((m1->nc==m2->nc)&&(m1->nl==m2->nl)){
        for(int i=0; i<m1->nl; i++){
            for(int j=0; j<m1->nc; j++){
                msub.bloco[i][j] = m1->bloco[i][j] - m2->bloco[i][j];
            }
        }
    }else{
        printf("Error: Não é possivel subtrair matrizes de dimensões diferentes.\n ");
        return m0;
    }
    return msub;
}

Matrix matrix_mult(Matrix *m1, Matrix *m2){
    Matrix mmult;
    matrix_criar(&mmult,m1->nl,m2->nc);
    if(m1->nc==m2->nl){
        for(int i=0; i<m1->nl; i++){
            for(int j=0; j<m2->nc; j++){
                double acumulador = 0.0;
                for(int l=0; l<m1->nc; l++){
                    acumulador = acumulador + (m1->bloco[i][l] * m2->bloco[l][j]);
                }
                mmult.bloco[i][j] = acumulador;
            }
        }
    }else{
        printf("Error: Não foi possivel multiplicar as matrizes.\n ");
        return m0;
    }
    return mmult;
}

Matrix matrix_esoma(Matrix *m, double e){
    Matrix mesoma;
    matrix_criar(&mesoma,m->nl,m->nc);
    for(int i=0; i<m->nl; i++){
        for(int j=0; j<m->nc; j++){
            mesoma.bloco[i][j] = m->bloco[i][j] + e;
        }
    }
    return mesoma;
}

Matrix matrix_esub(Matrix *m, double e){
    Matrix mesub;
    matrix_criar(&mesub,m->nl,m->nc);
    for(int i=0; i<m->nl; i++){
        for(int j=0; j<m->nc; j++){
            mesub.bloco[i][j] = m->bloco[i][j] - e;
        }
    }
    return mesub;
}

Matrix matrix_emult(Matrix *m, double e){
    Matrix memult;
    matrix_criar(&memult,m->nl,m->nc);
    for(int i=0; i<m->nl; i++){
        for(int j=0; j<m->nc; j++){
            memult.bloco[i][j] = m->bloco[i][j] * e;
        }
    }
    return memult;
}

Matrix matrix_transp(Matrix *m){
    Matrix mtrans;
    matrix_criar(&mtrans,m->nc,m->nl);
    for(int i=0; i<m->nl; i++){
        for(int j=0; j<m->nc; j++){
            mtrans.bloco[j][i] = m->bloco[i][j];
        }
    }
    return mtrans;
}

double matrix_deter(Matrix *m){
    if((m->nc!=m->nl)||(m->nl>3)){
        printf("Erro: não foi possivel calcular o determinante!\n");
        return NAN;
    }else{
        if(m->nl==1){
            return m->bloco[0][0];
        }else if(m->nl==2){
            return (m->bloco[0][0]*m->bloco[1][1])-(m->bloco[0][1]*m->bloco[1][0]);
        }else{
            double x = 0.0;
            x = x + (m->bloco[0][0]*m->bloco[1][1]*m->bloco[2][2]);
            x = x + (m->bloco[0][1]*m->bloco[1][2]*m->bloco[2][0]);
            x = x + (m->bloco[0][2]*m->bloco[1][0]*m->bloco[2][1]);
            x = x - (m->bloco[2][0]*m->bloco[1][1]*m->bloco[0][2]);
            x = x - (m->bloco[2][1]*m->bloco[1][2]*m->bloco[0][0]);
            x = x - (m->bloco[2][2]*m->bloco[1][0]*m->bloco[0][1]);
            return x;
        }
    }
}

Matrix matrix_inver(Matrix *m){
    Matrix aux;
    if((matrix_deter(m)==0.0)||(m->nc!=m->nl)||(m->nc>3)||m->nl>3){
        printf("Error: Essa matriz não possui inversa.\n");
        return m0;
    }else{
        matrix_criar(&aux,m->nc,m->nl);
        if(m->nl==1){
            aux.bloco[0][0] = 1 / m->bloco[0][0];
        }
        if(m->nl==2){
            double c = 1/(matrix_deter(m));
            aux.bloco[0][0] =  c*m->bloco[1][1];
            aux.bloco[0][1] = -c*m->bloco[0][1];
            aux.bloco[1][0] = -c*m->bloco[1][0];
            aux.bloco[1][1] =  c*m->bloco[0][0];
        }else{
            double determinante = matrix_deter (m);
            aux.bloco[0][0] = ((m->bloco[1][1]*m->bloco[2][2])-(m->bloco[2][1]*m->bloco[1][2]))/determinante;
            aux.bloco[0][1] = ((m->bloco[2][1]*m->bloco[0][2])-(m->bloco[0][1]*m->bloco[2][2]))/determinante;
            aux.bloco[0][2] = ((m->bloco[0][1]*m->bloco[1][2])-(m->bloco[1][1]*m->bloco[0][2]))/determinante;
            aux.bloco[1][0] = ((m->bloco[1][2]*m->bloco[2][0])-(m->bloco[2][2]*m->bloco[1][0]))/determinante;
            aux.bloco[1][1] = ((m->bloco[2][2]*m->bloco[0][0])-(m->bloco[0][2]*m->bloco[2][0]))/determinante;
            aux.bloco[1][2] = ((m->bloco[0][2]*m->bloco[1][0])-(m->bloco[1][2]*m->bloco[0][0]))/determinante;
            aux.bloco[2][0] = ((m->bloco[1][0]*m->bloco[2][1])-(m->bloco[2][0]*m->bloco[1][1]))/determinante;
            aux.bloco[2][1] = ((m->bloco[2][0]*m->bloco[0][1])-(m->bloco[0][0]*m->bloco[2][1]))/determinante;
            aux.bloco[2][2] = ((m->bloco[0][0]*m->bloco[1][1])-(m->bloco[1][0]*m->bloco[0][1]))/determinante;
        }
        return aux;
    }
}

void matrix_mostrar(Matrix *m){
    for(int i=0; i<m->nl; i++){
        for(int j=0; j<m->nc; j++){
            printf("%f ",m->bloco[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}