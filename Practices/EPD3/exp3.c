#include <unistd.h>
#include <stdlib.h> 
#include <stdio.h> 
int main() { 
    int pid; 
    /* let's create a child process */ 
    pid = fork(); 
    if (!pid) { 
      /* this is a child: dies immediately and becomes zombie */ 
      printf("\nChild: pid: %d\n",getpid()); 
      exit(0); 
    } 
    /* parent process: just asks for the user input */ 
    sleep(1); 
    printf("\nPlease,   press   enter   after   looking   at   the   zombie process..."); 
    (void)getchar() ; 
}
