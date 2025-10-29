#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include "startref.h"
#include "modelref.h"
#include "controle.h"
#include "linearizacao.h"
#include "robo.h"
#include "mutex.h"
#include "interface.h"

int main() {

	double a1, a2;

	pthread_t thr_0;
	pthread_t thr_1;
	pthread_t thr_2;
	pthread_t thr_3;
	pthread_t thr_4;
	pthread_t thr_5;

	Recurso_Compartilhado caixa;
	
	mutex_criar(&caixa);

	printf("Informe os valores de a1 e a2: \n");
	scanf("%lf",&a1);
	set_a1(&caixa,a1);
	scanf("%lf",&a2);
	set_a2(&caixa,a2);

	pthread_create(&thr_0, NULL, interface, &caixa);
	pthread_create(&thr_1, NULL, startref, &caixa);
	pthread_create(&thr_1, NULL, startref, &caixa);
	pthread_create(&thr_2, NULL, modelref, &caixa);
	pthread_create(&thr_3, NULL, controle, &caixa);
	pthread_create(&thr_4, NULL, linearizacao, &caixa);
	pthread_create(&thr_5, NULL, robo, &caixa);
	
	pthread_join(thr_0, NULL);
	pthread_join(thr_1, NULL);
	pthread_join(thr_2, NULL);
	pthread_join(thr_3, NULL);
	pthread_join(thr_4, NULL);
	pthread_join(thr_5, NULL);

	mutex_destruir(&caixa);

	return 0;
}
