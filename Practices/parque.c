#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define P 10
#define C 2

int coche1;
int pasajeros[C]; 	//paseantes con coches

sem_t cocheLibre;	//semáforo de coche libre u ocupado
sem_t pasajeroIn[C];	//semáforo de pasajeros en coche
sem_t fin[P];		//semáforo de fin de vuelta en coche
pthread_mutex_t usando = PTHREAD_MUTEX_INITIALIZER;	//mutex usando el coche o no

void *pasajero (void *); //función pasajero
void *coche (void *);	 //función coche

void *pasajero(void *ID){
	int n = (int) ID;							//hacemos casting porque es void
	int thisCoche;								//coche que vamos a usar para la función
	int seg = (1 + rand () % 5); 						//tiempo random que va a esperar cada pasajero
	printf("Pasajero %d paseando por el museo por %d segundos\n",n,seg);	
	sleep(seg);								//se pone a pasear al pasajero

	sem_wait(&cocheLibre);							//pasajero espera un coche libre

	thisCoche=coche1;				//inicializar el coche con el ID que se le pasa de la función coche

	pthread_mutex_unlock(&usando);			//desbloquea el coche para poder usarlo

	pasajeros[thisCoche] = n;			//coche que se está usando

	sem_post(&pasajeroIn[thisCoche]);		//se pone en uso el semáforo del coche que se ha cogido
	printf("Pasajero %d disfrutando del paseo en coche\n",n);

	sem_wait(&fin[n]);				//espera al semáforo de fin de vuelta en coche
	printf("Pasajero %d sale del coche\n",n);

}

void *coche(void *ID){
	int nC = (int) ID;				//hacemos casting porque es void
	int thisPasajeo;

	while(1){
		pthread_mutex_lock(&usando);		//bloquea el coche para no poder usarlo
		coche1 = nC;

		sem_post(&cocheLibre);			//pasa a estar ocupado

		sem_wait(&pasajeroIn[nC]);		//espera que un pasajero se monte
		thisPasajeo=pasajeros[nC];		//inicializamos al pasajero que se monta
		printf("Coche %d hace su recorrido\n",nC);
		sleep(2);				//tiempo del recorrido

		sem_post(&fin[thisPasajeo]);		//finaliza el recorrido del pasajero
		printf("Coche %d ha terminado su recorrido\n",nC);
	}
}


int main(){
	printf("\nParque de las Culturas\n\n");

	pthread_t coches[C];
	pthread_t paseantes[P];
	
	sem_init(&cocheLibre, 0, 0);

	int i,j;

	for(i=0;i<C;i++){
		sem_init(&pasajeroIn[i], 0, 0);
	}

	for(j=0;j<P;j++){
		sem_init(&fin[j], 0, 0);
	}
	
	//creamos los procesos	
	for(i=0;i<P;i++){
		pthread_create(&paseantes[i],NULL,pasajero,(void *)i);
	}

	for(j=0;j<C;j++){
		pthread_create(&coches[j],NULL,coche,(void *)j);
	}
	
	//esperamos los procesos
	for(i=0;i<P;i++){
		pthread_join(paseantes[i],NULL);
	}
	
	printf("\nGracias por su visita\n\n");
	return 0;
}

