#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "utils.h"
#include "mutex.h"


const double DELTA2 = 0.030;

//Matrix X
static double xc = 0.0;
static double yc = 0.0;
static double teta = 0.0;

double calc_xc(double v) {
	static double xc_d_anterior = 0.0;

	double xc_d = v * cos(teta);
	xc +=  ((xc_d + xc_d_anterior) * DELTA2) / 2;
	xc_d_anterior = xc_d;

	return xc;
}

double calc_yc(double v) {
	static double yc_d_anterior = 0.0;

	double yc_d = v * sin(teta);
	yc +=  (yc_d + yc_d_anterior) * DELTA2 / 2;
	yc_d_anterior = yc_d;

	return yc;
}

double calc_teta(double w) {
	static double teta_d_anterior = 0.0;

	double teta_d = w;
	teta += (teta_d + teta_d_anterior) * DELTA2 / 2;
	teta_d_anterior = teta_d;

	return teta;
}

double calc_y1(void *caixa) {
	double y1;

	y1 = get_xc(caixa) +  R * cos(get_teta(caixa));

	return y1;
}

double calc_y2(void *caixa) {
	double y2;

	y2 = get_yc(caixa) +  R * sin(get_teta(caixa));

	return y2;
}

void *robo(void *caixa) {
	FILE *arquivo;

    arquivo = fopen("robo.txt", "w");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
    }

	double t, v, w, xc, yc, teta, y1, y2;
    struct timespec tp_start, tp_stop,  inicio_ciclo, fim_ciclo;

    t = 0.0;
    clock_gettime(CLOCK_MONOTONIC, &tp_start);
    while(t < 20.0) {	//t in seconds
		clock_gettime(CLOCK_MONOTONIC, &inicio_ciclo);
        clock_gettime(CLOCK_MONOTONIC, &tp_stop);
        t = intervalo_tempo(&tp_start, &tp_stop);

		v = get_v(caixa);               
        w = get_w(caixa);   

		xc = calc_xc(v);
		yc = calc_yc(v);
		teta = calc_teta(w);
		y1 = calc_y1(caixa);
		y2 = calc_y2(caixa);

		set_xc(caixa,xc);
		set_yc(caixa,yc);
		set_teta(caixa,teta);
		set_y1(caixa,y1);
		set_y2(caixa,y2);

        struct timespec req = {.tv_sec = 0, .tv_nsec = 30000000};
        nanosleep(&req, NULL);

		clock_gettime(CLOCK_MONOTONIC, &fim_ciclo); // Fim do ciclo
        double ciclo_time = intervalo_tempo(&inicio_ciclo, &fim_ciclo);
        fprintf(arquivo, "%f\n", ciclo_time);
	}

	return NULL;
}
