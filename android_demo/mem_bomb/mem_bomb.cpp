#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>
#include <sys/mman.h>

#define  MEM_NUM  1024

int main(int argc,char*argv[])
{
    printf("Memory Bomb Version 1.0.0 %s %s\n",__DATE__,__TIME__); 
    unsigned long n=atoi(argv[1]);
    long i = 0;
  
    while(1)
    {
        int* ptr = (int*)malloc(sizeof(int)*1024*MEM_NUM);
        if(!ptr)  
          goto Fail;  

        memset(ptr,0,sizeof(int)*1024*MEM_NUM);
        printf("Get memory size %d MB round %d\n",sizeof(int),i); 
        printf("Memory page available %d  and total is %d\n",sysconf(_SC_AVPHYS_PAGES),sysconf(_SC_PHYS_PAGES)); 
        i++;  
        usleep(500*1000);
    }
      return 1;
      
Fail:
    printf("malloc memory fail round %d\n",i);
     return 0;
}


