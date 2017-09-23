#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#define N 5

int main()
{
    int tuberias[N][2];
    int pids[N];
    char buffer[3];
    int i;
    int doble=0;
    char aux[2];
	
    int resultado = 0;
    int suma=0;

    for(i=0; i<N; i++){
        if(pipe(tuberias[i]) == -1){
            perror("pipe");
            exit(1);
        }

        pids[i]=fork();//Creamos proceso hijo

        if(pids[i]==-1){
            printf("Se ha producido un error al crear el fork\n");
        }else{
        	if(pids[i]==0){
		    close(tuberias[i][0]);//El proceso hijo cierra lectura de la pipe
		    doble = 2*i;
		    sprintf(aux,"%d",doble); //pasamos de int a char[]
		    write(tuberias[i][1],aux,2);
		    exit(0);
		}else{		//PADRE
			close(tuberias[i][1]);//El proceso padre cierra la parte de escritura de la pipe
			read(tuberias[i][0],buffer,sizeof(buffer));
			printf("El proceso %d devuelve %s\n",i,buffer);
			suma = atoi (buffer);
			resultado+=suma;
		}
	}
	
    }
    
    printf("La suma total es %d\n",resultado);
    return 0;
}
