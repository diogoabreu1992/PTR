#ifndef UTILS_H
#define UTILS_H

#define PI  3.141592653589793238462643
#define R 0.60

static inline double intervalo_tempo(struct timespec *inicio, struct timespec *fim) {
    struct timespec aux;
    aux.tv_sec = fim->tv_sec - inicio->tv_sec;
    aux.tv_nsec = fim->tv_nsec - inicio->tv_nsec;

    if (aux.tv_nsec < 0) {
        --aux.tv_sec;
        aux.tv_nsec += 1000000000L;
    }
    return (double)aux.tv_sec + ((double)aux.tv_nsec / 1000000000.0);
}

#endif