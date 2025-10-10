#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "utils.h"
#include "mutex.h"

/*

    Tempo 30ms
    
    -> Leitura de u(t)
    -> Calculo de y(t)


*/

const double D = 0.30;
const double DELTA = 0.050;

//Matrix X
static double xc = 0.0;
static double yc = 0.0;
static double teta = 0.0;

double calc_xc(double v) {
	static double xc_d_anterior = 0.0;

	double xc_d = v * sin(teta);
	xc +=  ((xc_d + xc_d_anterior) * DELTA) / 2;
	xc_d_anterior = xc_d;

	return xc + 0.5 * D * cos(teta) * xc;
}

double calc_yc(double v) {
	static double yc_d_anterior = 0.0;

	double yc_d = v * cos(teta);
	yc +=  (yc_d + yc_d_anterior) * DELTA / 2;
	yc_d_anterior = yc_d;

	return yc + 0.5 * D * sin(teta) * yc;
}

double calc_teta(double w) {
	static double teta_d_anterior = 0.0;

	double teta_d = w;
	teta += (teta_d + teta_d_anterior) * DELTA / 2;
	teta_d_anterior = teta_d;

	return teta + teta;
}

void *thread2(void *caixa) {
	double t, v, w, xc, yc, teta;
    struct timespec tp_start, tp_stop;

    t = 0.0;
    clock_gettime(CLOCK_MONOTONIC, &tp_start);
    while(t < 20.0) {	//t in seconds
        clock_gettime(CLOCK_MONOTONIC, &tp_stop);
        t = intervalo_tempo(&tp_start, &tp_stop);

		//getU
		v = get_v(caixa);               
        w = get_w(caixa);   

		//calc Y
		xc = calc_xc(v);
		yc = calc_yc(v);
		teta = calc_teta(w);

		//setY
		set_xc(caixa,xc);
		set_yc(caixa,yc);
		set_teta(caixa,teta);

        struct timespec req = {.tv_sec = 0, .tv_nsec = 50000000};
        nanosleep(&req, NULL);
	}

	return NULL;
}
