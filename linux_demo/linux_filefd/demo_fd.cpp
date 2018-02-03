/*******************************************************************************
  * Copyright(C),2017,Mstar semi.co.,Ltd
  * @file Name
  * @author  tony.chen@mstarsemi.com
  
  * @version V1.0.0
  
  * @date  2017/12/15
  
  * @brief  verify one process can open filefd up to 1024
            & 0 1 2 is used for STDIN_FILENO  STDOUT_FILENO  STDERR_FILENO


                if we close file descriptror 1 the new creat fd must be 1 
            so we can use this method to redirect log
            
  * @History
*******************************************************************************/
// we usually use this head file 
#include <sys/types.h> 
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

//C standard head file 
#include <stdio.h>
#include <string.h>

#define  demo_filename "testfile.txt"


#define  demo_EXLOG    1

int main(int argc,char * argv[])
{
    long int fd = -1;
    int i = 0;

#if (demo_EXLOG == 0)

	while (1) 
	{
	    if ( i == 0)
	    {   // note that we use 
            fd = open(demo_filename,O_RDONLY | O_CREAT,0x700);
	    }
	    else
	    {
            fd = open(demo_filename,O_RDONLY,0x700); 
	    }
	    
	    if (0 > fd ) goto Fail;
	    printf("The crate fd is %ld round %d\n",fd,i);
	 
	    usleep(50000);
        i++;
	}
	
#elif (demo_EXLOG == 1)

     int demologfd = -1;

     close(STDOUT_FILENO);
     demologfd = open("demo_log.log", O_CREAT | O_RDWR, 0664);
     printf("The demolog file fd is %d \n",demologfd);
	 
#endif

    printf("Cannot run into there\n");

    return 1;

Fail:
	// create File fd fail please check!!: Too many open files
    perror("create File fd fail please check!!");
	// close error msg is :Too many open files
	fprintf(stderr,"close error msg is :%s\n",strerror(errno));
    return 0;
}
