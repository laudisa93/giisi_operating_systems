#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdlib.h> 

int main() { 

int pid = 0,status;
int pid1 = 0,status1;
			
		
		if((pid=fork()) == 0)
		{
			
			sleep(2);	
			
			printf("Hola,soy el primer hijo con id %d\n",getpid());
			
			exit(1);	
	
		}else if(pid==-1)
		{
			printf("ERROR hijo 1");	
		exit(-1);
		
		}
		else if((pid1=fork())==0){
	
			sleep(4);			
			
			printf("Hola,soy el segundo hijo con id %d\n",getpid());
						
			exit(1);	
	
		}else if(pid1==-1)
		{
			printf("ERROR hijo 2");	
		exit(-1);	

		}
		else
		{
			
			
			wait(&status);
			printf("Padre:esperando...\n");
			wait(&status1);
				if(WIFEXITED(status) != 0 && WEXITSTATUS(status) == 1){
					printf("Padre:Primer hijo con id %d ha finalizado\n",pid);				
														
				}
			wait(NULL);
			printf("Padre:esperando...\n");

				if(WIFEXITED(status1) != 0 && WEXITSTATUS(status1) == 1){
					printf("Padre:Segundo hijo con id %d ha finalizado\n",pid1);				
														
				}


		exit(0);	
			
		}
	
}
