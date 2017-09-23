#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main() {
	int pid = 0, status = 0, n=0;
	if ((pid = fork()) == -1) {
		printf("Error al crear proceso hijo\n");
		exit(1);
	}
	if (pid == 0) { /* Proceso */
		int varPrueba = 10;
		printf("Hijo: El PID de mi proceso padre es %d mi PID es %d\n", getppid(),getpid());
		printf("Hijo: La variable varPrueba vale %d \n",varPrueba);
		printf("Hijo: Introduzca valor de la variable: ");
		scanf("%d",&varPrueba);
		printf("Hijo: La variable varPrueba vale %d \n",varPrueba);
		printf("Hijo: voy a dormir 2 segundos\n");
		sleep(2);
		exit (1);
	}
	else { /* Proceso Padre */
		int varPrueba = 10;
		printf("Padre: Mi PID es el %d y he creado un proceso hijo cuyo pid es %d\n", getpid(), pid);
		printf("Padre: La variable varPrueba vale %d \n",varPrueba);
		printf("Padre: Espero a mi hijo\n");
		wait(&status);
		varPrueba += 35;
		printf("Padre: La variable varPrueba vale %d \n",varPrueba);
		printf("\nPadre: El proceso hijo finalizo con el estado %d \n", status);
		exit (0);
	}
}

