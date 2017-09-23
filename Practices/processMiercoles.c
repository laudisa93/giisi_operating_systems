#include <stdlib.h>
#include <stdio.h>

int functionChild1(int id, int seconds) {
	printf("Child %d: I am the child number %d, my pid is %d \n",id,id,getpid());
	printf("Child %d: I simulate the first process\n",id);
	printf("Child %d: going to sleep for %d seconds\n",id,seconds);
	sleep(seconds);
	exit(0);
}

int functionChild2(int id) {
	char name[124];
	int seconds = 0;
	printf("Child %d: I am the child number %d, my pid is %d \n",id,id,getpid());
	printf("Child %d: Introduce your name: ",id);
	scanf("%s",name);
	printf("Child %d: Introduce number of second for your request: ",id);
	scanf("%d",&seconds);
	printf("Child %d: Hi %s I am going to attend to your request, so to sleep for %d seconds\n",id,name,seconds);
	sleep(seconds);
	printf("Child %d: done\n",id);
	exit(0);
}

int main(int argc, char *argv[])
{
    int whichone, first, second;
    int howmany;
    int status;
    int i = 1;
    int seconds = 10;	

    if ((first=fork())==0) /* Parent spawns 1st child */
    {
        functionChild1(i,seconds);
    }
    else if (first == -1)
    {
        perror("1st fork: something went bananas\n");
        exit(1);
    }
    else if ((second=fork())==0) /* Parent spawns 2nd  child */
    {
	i++;
        functionChild2(i);  
    }
    else if (second == -1)
    {
        perror("2nd fork: something went bananas\n");
        exit(1);
    }
           
    //printf("This is the parent\n");
    
    howmany=0; 
    while (howmany < 2) /* Wait twice */
    {
	printf("Parent: waiting...\n");
        whichone=wait(&status);
        howmany++;
        
        if (whichone==first)
           printf("Parent: First child with id %d  exited ",whichone);
        else
           printf("Parent: Second child with id %d exited ",whichone);
    
        if ((status & 0xffff)==0)
           printf("correctly\n");
        else
           printf("uncorrectly\n");
    }

    return 0;
}
