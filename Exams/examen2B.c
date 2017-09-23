#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO-B "deAaB"
#define FIFO-B2 "deBaC"

void main (){

	int fd,num,fd2;
	char buffer [10] ;
	mknod(FIFO-B,S_IFIFO | 0666,0);
	mknod(FIFO-B2,S_IFIFO | 0666,0);

	fd = open(FIFO-B,O_RDONLY);
	fd2 = open (FIFO-B2,O_WRONLY);

	do {
		if ((num=read(fd,buffer,10))==-1){
			perror("ERROR\n");
		} else {
			int s = atoi(buffer);
			if (s%2==0){
				if ((num = write(fd2,buffer,10))==-1){
					perror ("ERROR");
				} else {
					printf ("B envia %d\n",s);
				}	
			} else {
				sprintf(buffer,"%d",1);
				if ((num = write(fd2,buffer,10))==-1){
					perror("ERROR\n");
				} else {
					printf("B envia 1\n");
				}	
			}		
		}
	} while (num>0);
}
