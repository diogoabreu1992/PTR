#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "utils.h"
#include "mutex.h"

const double DELTA1 = 0.050;

static double ymx = 0.0;
static double ymy = 0.0;

double calc_ymx(void* caixa) {
	static double ymx_d_anterior = 0.0;

	double ymx_d = get_a1(caixa) * (get_xref(caixa) - ymx);
	ymx +=  ((ymx_d + ymx_d_anterior) * DELTA1) / 2;
	ymx_d_anterior = ymx_d;

	return ymx;
}

double calc_ymy(void* caixa) {
	static double ymy_d_anterior = 0.0;

	double ymy_d = get_a2(caixa) * (get_yref(caixa) - ymy);
	ymy +=  ((ymy_d + ymy_d_anterior) * DELTA1) / 2;
	ymy_d_anterior = ymy_d;

	return ymy;
}

void* modelref(void *caixa) {
	FILE *arquivo;

    arquivo = fopen("modelref.txt", "w");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
    }

	double t, ymx, ymy;
    struct timespec inicio, fim, inicio_ciclo, fim_ciclo;

    t = 0.0;
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    while(t < 20.0) {	
		clock_gettime(CLOCK_MONOTONIC, &inicio_ciclo);
        clock_gettime(CLOCK_MONOTONIC, &fim);
        t = intervalo_tempo(&inicio, &fim);

		ymx = calc_ymx(caixa);
		ymy = calc_ymy(caixa);

		set_ymx(caixa, ymx);
		set_ymy(caixa, ymy);

        struct timespec req = {.tv_sec = 0, .tv_nsec = 50000000};
        nanosleep(&req, NULL);

		clock_gettime(CLOCK_MONOTONIC, &fim_ciclo); // Fim do ciclo
        double ciclo_time = intervalo_tempo(&inicio_ciclo, &fim_ciclo);
        fprintf(arquivo, "%f\n", ciclo_time); 
	}

	return NULL;
}
