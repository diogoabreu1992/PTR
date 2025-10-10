#include <stdio.h>
#include <stdlib.h>

double integral(double (*func)(double), double inicio, double fim, double n_part) {
    double h_trap = (fim - inicio) / n_part; 
    double somatorio = 0.0;
    double a = inicio;
    double b = inicio + h_trap;

    for(int i = 0; i < n_part; i++){
        somatorio = somatorio + (((func(a) + func(b)) * h_trap) / (double)2);
        a = b;
        b = b + h_trap;  
    }
    return somatorio;
}