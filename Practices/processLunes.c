#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int whichone, first, second;
    int howmany;
    int status;
    
    if ((first=fork())==0) /* Parent spawns 1st child */
    {
        printf("Hi, I am the first child, "
               "and my id is %d\n", 
               getpid()
               );
        sleep(2); /* Sleep 2 sec, then exit */
        exit(0);   
    }
    else if (first == -1)
    {
        perror("1st fork: something went bananas\n");
        exit(1);
    }
    else if ((second=fork())==0) /* Parent spawns 2nd  child */
    {
        printf("Hi, I am the second child, "
               "and my id is %d\n", 
               getpid()
               );
        sleep(4); /* Sleep 4 sec, then exit */
        exit(0);   
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
