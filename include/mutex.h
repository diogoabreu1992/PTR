#ifndef MUTEX_H
#define MUTEX_H

#include <pthread.h>

typedef struct rc {
    double v, w, xc, yc, teta;
    pthread_mutex_t lock; 
} Recurso_Compartilhado;

void mutex_criar(Recurso_Compartilhado *caixa);
void mutex_destruir(Recurso_Compartilhado *caixa);

void set_v(Recurso_Compartilhado *caixa, double v);
double get_v(Recurso_Compartilhado *caixa);

void set_w(Recurso_Compartilhado *caixa, double w);
double get_w(Recurso_Compartilhado *caixa);

void set_xc(Recurso_Compartilhado *caixa, double xc);
double get_xc(Recurso_Compartilhado *caixa);

void set_yc(Recurso_Compartilhado *caixa, double yc);
double get_yc(Recurso_Compartilhado *caixa);

void set_teta(Recurso_Compartilhado *caixa, double teta);
double get_teta(Recurso_Compartilhado *caixa);


#endif