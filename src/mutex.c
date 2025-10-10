#include <stdio.h>
#include <stdlib.h>
#include "mutex.h"
#include <pthread.h>

void mutex_criar(Recurso_Compartilhado *caixa){
    caixa->v = 0.0;
    caixa->w = 0.0;
    caixa->xc = 0.0;
    caixa->yc = 0.0;
    caixa->teta = 0.0;
    caixa->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
} 

void mutex_destruir(Recurso_Compartilhado *caixa){
    pthread_mutex_destroy(&(caixa->lock));
    caixa->v = 0.0;
    caixa->w = 0.0;
    caixa->xc = 0.0;
    caixa->yc = 0.0;
    caixa->teta = 0.0;
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
