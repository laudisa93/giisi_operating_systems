#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO-A "deAaB"


void main (){
	
	int s;
	char buffer[10];
	int fd,num;

	mknod(FIFO-A,S_IFIFO | 0666,0);
	fd = open(FIFO-A,O_WRONLY);
	while (1){
		s = (rand()%10)+1;
		sprintf(buffer,"%d",s);
		if ((num = write(fd,buffer,300))==-1){
			perror ("ERROR");
		} else {
			printf ("A envia %d\n",s);
		}
		sleep(s);
	}
}
