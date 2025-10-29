#include <stdio.h>
#include <stdlib.h>
#include "mutex.h"
#include <pthread.h>

void mutex_criar(Recurso_Compartilhado *caixa){
    caixa->xref = 0.0;
    caixa->yref = 0.0;
    caixa->ymx = 0.0;
    caixa->ymy = 0.0;
    caixa->v1 = 0.0;
    caixa->v2 = 0.0;
    caixa->a1 = 3.0;
    caixa->a2 = 3.0;
    caixa->v = 0.0;
    caixa->w = 0.0;
    caixa->xc = 0.0;
    caixa->yc = 0.0;
    caixa->teta = 0.0;
    caixa->y1 = 0.0;
    caixa->y2 = 0.0;
    caixa->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
} 

void mutex_destruir(Recurso_Compartilhado *caixa){
    pthread_mutex_destroy(&(caixa->lock));
    caixa->xref = 0.0;
    caixa->yref = 0.0;
    caixa->ymx = 0.0;
    caixa->ymy = 0.0;
    caixa->v1 = 0.0;
    caixa->v2 = 0.0;
    caixa->a1 = 3.0;
    caixa->a2 = 3.0;
    caixa->v = 0.0;
    caixa->w = 0.0;
    caixa->xc = 0.0;
    caixa->yc = 0.0;
    caixa->teta = 0.0;
    caixa->y1 = 0.0;
    caixa->y2 = 0.0;
}

void set_a1(Recurso_Compartilhado *caixa, double a1){
    pthread_mutex_lock(&caixa->lock);
        caixa->a1 = a1;
    pthread_mutex_unlock(&caixa->lock);
}

double get_a1(Recurso_Compartilhado *caixa){
    double a1;
    pthread_mutex_lock(&caixa->lock);
        a1 = caixa->a1;
    pthread_mutex_unlock(&caixa->lock);
    return a1;
}

void set_a2(Recurso_Compartilhado *caixa, double a2){
    pthread_mutex_lock(&caixa->lock);
        caixa->a2 = a2;
    pthread_mutex_unlock(&caixa->lock);
}

double get_a2(Recurso_Compartilhado *caixa){
    double a2;
    pthread_mutex_lock(&caixa->lock);
        a2 = caixa->a2;
    pthread_mutex_unlock(&caixa->lock);
    return a2;
}

void set_xref(Recurso_Compartilhado *caixa, double xref){
    pthread_mutex_lock(&caixa->lock);
        caixa->xref = xref;
    pthread_mutex_unlock(&caixa->lock);
}

double get_xref(Recurso_Compartilhado *caixa){
    double xref;
    pthread_mutex_lock(&caixa->lock);
        xref = caixa->xref;
    pthread_mutex_unlock(&caixa->lock);
    return xref;
}

void set_yref(Recurso_Compartilhado *caixa, double yref){
    pthread_mutex_lock(&caixa->lock);
        caixa->yref = yref;
    pthread_mutex_unlock(&caixa->lock);
}

double get_yref(Recurso_Compartilhado *caixa){
    double yref;
    pthread_mutex_lock(&caixa->lock);
        yref = caixa->yref;
    pthread_mutex_unlock(&caixa->lock);
    return yref;
}

void set_ymx(Recurso_Compartilhado *caixa, double ymx){
    pthread_mutex_lock(&caixa->lock);
        caixa->ymx = ymx;
    pthread_mutex_unlock(&caixa->lock);
}

double get_ymx(Recurso_Compartilhado *caixa){
    double ymx;
    pthread_mutex_lock(&caixa->lock);
        ymx = caixa->ymx;
    pthread_mutex_unlock(&caixa->lock);
    return ymx;
}

void set_ymy(Recurso_Compartilhado *caixa, double ymy){
    pthread_mutex_lock(&caixa->lock);
        caixa->ymy = ymy;
    pthread_mutex_unlock(&caixa->lock);
}

double get_ymy(Recurso_Compartilhado *caixa){
    double ymy;
    pthread_mutex_lock(&caixa->lock);
        ymy = caixa->ymy;
    pthread_mutex_unlock(&caixa->lock);
    return ymy;
}

void set_v(Recurso_Compartilhado *caixa, double v){
    pthread_mutex_lock(&caixa->lock);
        caixa->v = v;
    pthread_mutex_unlock(&caixa->lock);
}

double get_v(Recurso_Compartilhado *caixa){
    double v;
    pthread_mutex_lock(&caixa->lock);
        v = caixa->v;
    pthread_mutex_unlock(&caixa->lock);
    return v;
}

void set_v1(Recurso_Compartilhado *caixa, double v1){
    pthread_mutex_lock(&caixa->lock);
        caixa->v1 = v1;
    pthread_mutex_unlock(&caixa->lock);
}

double get_v1(Recurso_Compartilhado *caixa){
    double v1;
    pthread_mutex_lock(&caixa->lock);
        v1 = caixa->v1;
    pthread_mutex_unlock(&caixa->lock);
    return v1;
}

void set_v2(Recurso_Compartilhado *caixa, double v2){
    pthread_mutex_lock(&caixa->lock);
        caixa->v2 = v2;
    pthread_mutex_unlock(&caixa->lock);
}

double get_v2(Recurso_Compartilhado *caixa){
    double v2;
    pthread_mutex_lock(&caixa->lock);
        v2 = caixa->v2;
    pthread_mutex_unlock(&caixa->lock);
    return v2;
}

void set_w(Recurso_Compartilhado *caixa, double w){
    pthread_mutex_lock(&caixa->lock);
        caixa->w = w;
    pthread_mutex_unlock(&caixa->lock);
}

double get_w(Recurso_Compartilhado *caixa){
    double w;
    pthread_mutex_lock(&caixa->lock);
        w = caixa->w;
    pthread_mutex_unlock(&caixa->lock);
    return w;
}

void set_xc(Recurso_Compartilhado *caixa, double xc){
    pthread_mutex_lock(&caixa->lock);
        caixa->xc = xc;
    pthread_mutex_unlock(&caixa->lock);
}

double get_xc(Recurso_Compartilhado *caixa){
    double xc;
    pthread_mutex_lock(&caixa->lock);
        xc = caixa->xc;
    pthread_mutex_unlock(&caixa->lock);
    return xc;
}

void set_yc(Recurso_Compartilhado *caixa, double yc){
    pthread_mutex_lock(&caixa->lock);
        caixa->yc = yc;
    pthread_mutex_unlock(&caixa->lock);
}

double get_yc(Recurso_Compartilhado *caixa){
    double yc;
    pthread_mutex_lock(&caixa->lock);
        yc = caixa->yc;
    pthread_mutex_unlock(&caixa->lock);
    return yc;
}

void set_teta(Recurso_Compartilhado *caixa, double teta){
    pthread_mutex_lock(&caixa->lock);
        caixa->teta = teta;
    pthread_mutex_unlock(&caixa->lock);
}

double get_teta(Recurso_Compartilhado *caixa){
    double teta;
    pthread_mutex_lock(&caixa->lock);
        teta = caixa->teta;
    pthread_mutex_unlock(&caixa->lock);
    return teta;
}

void set_y1(Recurso_Compartilhado *caixa, double y1){
    pthread_mutex_lock(&caixa->lock);
        caixa->y1 = y1;
    pthread_mutex_unlock(&caixa->lock);
}

double get_y1(Recurso_Compartilhado *caixa){
    double y1;
    pthread_mutex_lock(&caixa->lock);
        y1 = caixa->y1;
    pthread_mutex_unlock(&caixa->lock);
    return y1;
}

void set_y2(Recurso_Compartilhado *caixa, double y2){
    pthread_mutex_lock(&caixa->lock);
        caixa->y2 = y2;
    pthread_mutex_unlock(&caixa->lock);
}

double get_y2(Recurso_Compartilhado *caixa){
    double y2;
    pthread_mutex_lock(&caixa->lock);
        y2 = caixa->y2;
    pthread_mutex_unlock(&caixa->lock);
    return y2;
}