#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include "thread1.h"
#include "thread2.h"
#include "mutex.h"

int main() {

	pthread_t thr_1;
	pthread_t thr_2;

	Recurso_Compartilhado caixa;
	
	mutex_criar(&caixa);

	pthread_create(&thr_1, NULL, thread1, &caixa);
	pthread_create(&thr_2, NULL, thread2, &caixa);
	
	pthread_join(thr_1, NULL);
	pthread_join(thr_2, NULL);

	mutex_destruir(&caixa);

	return 0;
}
