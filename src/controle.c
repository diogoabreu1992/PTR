#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "utils.h"
#include "mutex.h"


double calc_v1(void* caixa) {
	double v1, ymx_dot;

    ymx_dot = get_a1(caixa)*(get_xref(caixa)-get_ymx(caixa));
    v1 = ymx_dot + get_a1(caixa)*(get_ymx(caixa)-get_y1(caixa));

	return v1;
}

double calc_v2(void* caixa) {
	double v2, ymy_dot;

    ymy_dot = get_a2(caixa)*(get_yref(caixa)-get_ymy(caixa));
    v2 = ymy_dot + get_a2(caixa)*(get_ymy(caixa)-get_y2(caixa));

	return v2;
}

void* controle(void *caixa) {
    FILE *arquivo;

    arquivo = fopen("controle.txt", "w");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
    }

	double t, v1, v2;
    struct timespec inicio, fim, inicio_ciclo, fim_ciclo;

    t = 0.0;
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    while(t < 20.0) {	
        clock_gettime(CLOCK_MONOTONIC, &inicio_ciclo);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        t = intervalo_tempo(&inicio, &fim);

        v1 = calc_v1(caixa);
        v2 = calc_v2(caixa);

        set_v1(caixa,v1);
        set_v2(caixa,v2);

        struct timespec req = {.tv_sec = 0, .tv_nsec = 50000000};
        nanosleep(&req, NULL);

        clock_gettime(CLOCK_MONOTONIC, &fim_ciclo); // Fim do ciclo
        double ciclo_time = intervalo_tempo(&inicio_ciclo, &fim_ciclo);
        fprintf(arquivo, "%f\n", ciclo_time); 
	}

	return NULL;
}
