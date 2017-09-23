#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO-C "deBaC"

void main (){
	
	int fd,num;
	char buffer[10];

	mknod(FIFO-C,S_IFIFO | 0666,0);
	
	fd = open(FIFO-C,O_RDONLY);
	
	do{
		if ((num=read(fd,buffer,10))==-1){
			perror("ERROR\n");
		} else {
			int s = atoi(buffer);
			printf ("El número enviado es %d\n",s);
		}
	} while (num>0);
}
