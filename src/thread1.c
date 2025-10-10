#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "utils.h"
#include "mutex.h"

/*

    Tempo 30ms
    
    -> Geração de u(t)
    -> Leitura de y(t)
    -> Armazenamento de valores: t, u(t), y(t) 


*/

/* 

    Geração de u(t)
        [ 0; 0] para (t < 0);
        [ 1;  0.2*pi] para (0 <= t < 10);
        [ 1; -0.2*pi] para (t >= 10).

    u(t) = [v; w] = [velocidade linear; velocidade angular]
*/
void gerar_u(Recurso_Compartilhado *caixa, double t){
    if(t < 0.0){
        set_v(caixa,0.0);
        set_w(caixa, 0.0);
    }else if(t >= 0 && t < 10){
        set_v(caixa,1.0);
        set_w(caixa, 0.2*PI);
    }else{
        set_v(caixa,1.0);
        set_w(caixa, -0.2*PI);
    }
}

/* 

    Leitura de yf(t)

*/

void* thread1(void* caixa){

    double t = 0.0, v, w, xc, yc, teta;
    struct timespec inicio, fim;

    clock_gettime(CLOCK_MONOTONIC,&inicio);
    while(t<20){
        clock_gettime(CLOCK_MONOTONIC,&fim);
        t = intervalo_tempo(&inicio,&fim);
        gerar_u(caixa,t);                                                   //Gerar u(t)

        xc = get_xc(caixa);                                                 //Ler yf(t)
        yc = get_yc(caixa);                                                 //Ler yf(t)
        teta = get_teta(caixa);                                             //Ler yf(t)

        v = get_v(caixa);               
        w = get_w(caixa);               
        printf("%f %f %f %f %f %f\n", t, v, w, xc, yc, teta);     //Armazenamento dos Valores

        struct timespec req = {.tv_sec = 0, .tv_nsec = 30000000};
        nanosleep(&req, NULL);
    }

    return NULL;
}