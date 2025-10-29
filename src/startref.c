#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "utils.h"
#include "mutex.h"

void* startref(void* caixa){
    FILE *arquivo;

    arquivo = fopen("startref.txt", "w");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
    }

    double t = 0.0;
    struct timespec inicio, fim, inicio_ciclo, fim_ciclo;

    clock_gettime(CLOCK_MONOTONIC,&inicio);
    while(t<20){
        clock_gettime(CLOCK_MONOTONIC, &inicio_ciclo);
        clock_gettime(CLOCK_MONOTONIC,&fim);
        t = intervalo_tempo(&inicio,&fim);

        set_xref(caixa, (5.0/PI)*cos(0.2*PI*t));
        if(t>=0 && t<10){
            set_yref(caixa, (5.0/PI)*sin(0.2*PI*t));
        }else if(t>=10){
            set_yref(caixa, -(5.0/PI)*sin(0.2*PI*t));
        }else{
            printf("Erro: Tempo negativo!\n");
            break;
        }

        struct timespec req = {.tv_sec = 0, .tv_nsec = 120000000};
        nanosleep(&req, NULL);

        clock_gettime(CLOCK_MONOTONIC, &fim_ciclo); // Fim do ciclo
        double ciclo_time = intervalo_tempo(&inicio_ciclo, &fim_ciclo);
        fprintf(arquivo, "%f\n", ciclo_time); 
    }

    return NULL;
}