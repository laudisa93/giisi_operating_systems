#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
//#include <string.h>
int main()
{
int pid=0,pid1=0,status=0,status1=0;
int n=10,m;
 

	if((pid1=fork())==0){
		char nombre[20] ;
		printf("Hola,soy el segundo hijo con id %d\n",getpid());
		printf("Introduce nombre: \n");
		scanf("%s",nombre);
		printf("Introduce el numero de segundos: ");
		scanf("%d",&m);
		printf("Hola %s: voy a atender tu peticion asi que voy a dormir %d sg\n",nombre,m);
		sleep(m);
		printf("OK\n");
		exit(0);
		
	}else if((pid=fork())==0)
	{
		printf("Hola,soy el primer hijo con id %d\n",getpid());
		printf("Voy a simular el 1 proceso \n");
		printf("Voy a dormir %d sg\n",n);
		sleep(n);
		exit(0);	
			
	}else
	{
		wait(&status1);
		printf("Padre:esperando...\n");
			if(WIFEXITED(status1) != 0 && WEXITSTATUS(status1) == 0){
					printf("Padre:Segundo hijo con id %d ha finalizado \n",pid1);
														
				}
		wait(&status);
			printf("Padre:esperando...\n");
			if(WIFEXITED(status) != 0 && WEXITSTATUS(status) == 0){
					printf("Padre:Primer hijo con id %d ha finalizado\n",pid);				
														
				}
	}

		exit(0);

}














