#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "utils.h"
#include "mutex.h"

void* interface(void* caixa){
    FILE *arquivo, *grafico;

    arquivo = fopen("interface.txt", "w");
    grafico = fopen("graficos.txt", "w");

    if (arquivo == NULL && grafico == NULL) {
        perror("Erro ao abrir o arquivo");
    }


    double t = 0.0;
    struct timespec inicio, fim, inicio_ciclo, fim_ciclo;

    clock_gettime(CLOCK_MONOTONIC,&inicio);
    while(t<20){
        clock_gettime(CLOCK_MONOTONIC, &inicio_ciclo);
        clock_gettime(CLOCK_MONOTONIC,&fim);
        t = intervalo_tempo(&inicio,&fim);

        printf("%f %f %f %f %f %f\n", t, get_y1(caixa), get_y2(caixa), get_teta(caixa), get_xref(caixa), get_yref(caixa));
        fprintf(grafico, "%f %f %f %f\n", get_y1(caixa), get_y2(caixa), get_xref(caixa), get_yref(caixa)); 

        struct timespec req = {.tv_sec = 0, .tv_nsec = 50000000};
        nanosleep(&req, NULL);

        clock_gettime(CLOCK_MONOTONIC, &fim_ciclo); // Fim do ciclo
        double ciclo_time = intervalo_tempo(&inicio_ciclo, &fim_ciclo);
        fprintf(arquivo, "%f\n", ciclo_time); 
    }

    return NULL;
}