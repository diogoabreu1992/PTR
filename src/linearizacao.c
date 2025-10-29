#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "utils.h"
#include "mutex.h"
#include "matrix.h"


Matrix calc_u(void *caixa){
    double v1, v2;
    Matrix u, l, aux, v;

    matrix_criar(&u,2,1);
    matrix_criar(&l,2,2);
    matrix_criar(&aux,2,2);
    matrix_criar(&v,2,1);

    matrix_set(&l,0,0,cos(get_teta(caixa)));
    matrix_set(&l,0,1,-R*sin(get_teta(caixa)));
    matrix_set(&l,1,0,sin(get_teta(caixa)));
    matrix_set(&l,1,1,R*cos(get_teta(caixa)));

    v1 = get_v1(caixa);
    v2 = get_v2(caixa);
    matrix_set(&v,0,0,v1);
    matrix_set(&v,1,0,v2);

    aux = matrix_inver(&l);

    u = matrix_mult(&aux,&v);

    return u;
}

void* linearizacao(void* caixa){
    FILE *arquivo;

    arquivo = fopen("linearizacao.txt", "w");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
    }

    double t = 0.0, v, w;
    struct timespec inicio, fim, inicio_ciclo, fim_ciclo;

    clock_gettime(CLOCK_MONOTONIC,&inicio);
    while(t<20){
        clock_gettime(CLOCK_MONOTONIC, &inicio_ciclo);
        clock_gettime(CLOCK_MONOTONIC,&fim);
        t = intervalo_tempo(&inicio,&fim);

        Matrix u;
        u = calc_u(caixa);

        v = matrix_get(&u,0,0);
        w = matrix_get(&u,1,0);


        set_v(caixa,v);
        set_w(caixa,w);

        struct timespec req = {.tv_sec = 0, .tv_nsec = 40000000};
        nanosleep(&req, NULL);

        clock_gettime(CLOCK_MONOTONIC, &fim_ciclo); // Fim do ciclo
        double ciclo_time = intervalo_tempo(&inicio_ciclo, &fim_ciclo);
        fprintf(arquivo, "%f\n", ciclo_time); 
    }

    return NULL;
}