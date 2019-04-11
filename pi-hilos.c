#include "stdio.h"		// printf, perror
#include "stdlib.h"		// exit
#include "pthread.h"	// pthread_create, pthread_join 
#include "time.h"		// clock, CLOCKS_PER_SEC, time
#define N 4			// numero de hilos
#define t 4000000000	// iteraciones

pthread_t hilo[N];
double parcialPi[N];

double calcPi(long long k) {
	long long max = t*(k+1);
	long long min = t*k;
	double x = 0;
	long long minusOne = -1;
	long long sig = -1;
	
	long long i;
	for(i=min+1; i<max; i=i+2){
		sig *= minusOne;
		x += sig*(double)4/i;
	}
	return x;
}

void *threadPi(void *i){
	int k;
	k = *((int*)i);
	parcialPi[k] = calcPi(k);
	return NULL;
}

void valoresParcialesPi(){
	int i;
	for(i=0; i<N; i++){
		printf("parcialPi[%d] = %.20f\n", i, parcialPi[i]);
	}
}

double valorPi(){
	int i; double pi = 0.0;
	for (i=0; i<N; i++){
		pi += parcialPi[i];
	}
	return pi;
}

int main(){
	// Variables básicas
	int r, i;
	void *retval;
	clock_t begin;
	double time = 0.0;
	printf("Calculo de Pi con hilos\n"); // Titulo

	begin = clock(); // Inicia cronometro

	// Creacion de los hilos
	for(i=0; i<N; i++){
		r = pthread_create(&hilo[i], NULL, threadPi, &i);
		if(r<0){perror("error pthread_create\n"); exit(-1);}
	}
	
	// Join de los hilos
	for(i=0; i<N; i++){
		r = pthread_join(hilo[i], &retval);
		if(r<0){perror("error pthread_join\n"); exit(-1);}
	}

	// Calculo final de tiempo de ejecucion
	time = (double)(clock() - begin) / CLOCKS_PER_SEC; 
	printf("hilos: %d, tiempo: %.2f seg\n", N, time);

	// Seccion adicional (opcional)
	valoresParcialesPi();
	printf("Pi = %.20f\n", valorPi());

	return 0;
}