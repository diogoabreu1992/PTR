#ifndef MUTEX_H
#define MUTEX_H

#include <pthread.h>

typedef struct rc {
    double a1, a2;
    double v1, v2;
    double xref, yref, ymx, ymy;
    double v, w, xc, yc, teta;
    double y1, y2;
    pthread_mutex_t lock; 
} Recurso_Compartilhado;

void mutex_criar(Recurso_Compartilhado *caixa);
void mutex_destruir(Recurso_Compartilhado *caixa);

void set_v1(Recurso_Compartilhado *caixa, double v1);
double get_v1(Recurso_Compartilhado *caixa);

void set_v2(Recurso_Compartilhado *caixa, double v2);
double get_v2(Recurso_Compartilhado *caixa);

void set_xref(Recurso_Compartilhado *caixa, double xref);
double get_xref(Recurso_Compartilhado *caixa);

void set_yref(Recurso_Compartilhado *caixa, double yref);
double get_yref(Recurso_Compartilhado *caixa);

void set_ymx(Recurso_Compartilhado *caixa, double ymx);
double get_ymx(Recurso_Compartilhado *caixa);

void set_ymy(Recurso_Compartilhado *caixa, double ymy);
double get_ymy(Recurso_Compartilhado *caixa);

void set_a1(Recurso_Compartilhado *caixa, double a1);
double get_a1(Recurso_Compartilhado *caixa);

void set_a2(Recurso_Compartilhado *caixa, double a2);
double get_a2(Recurso_Compartilhado *caixa);

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

void set_y1(Recurso_Compartilhado *caixa, double y1);
double get_y1(Recurso_Compartilhado *caixa);

void set_y2(Recurso_Compartilhado *caixa, double y2);
double get_y2(Recurso_Compartilhado *caixa);


#endif