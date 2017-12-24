/*******************************************************************************
  * Copyright(C),2017,Mstar semi.co.,Ltd
  * @file Name
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date  2017/12/15
  * @brief
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

#define  sz_filename "testfile.txt"

int main(int argc,char * argv[])
{
    long int fd = -1;
    int i = 0;
 
	while (1) 
	{
	    if ( i == 0)
	    {
            fd = open(sz_filename,O_RDONLY | O_CREAT,0x700);
	    }
	    else
	    {
            fd = open(sz_filename,O_RDONLY,0x700); 
	    }
	    
	    if (0 > fd ) goto Fail;
	    printf("The crate fd is %ld round %d\n",fd,i);
	 
	    usleep(50000);
        i++;
	}
    printf("Cannot run into there\n");
    return 1;

Fail:
	// create File fd fail please check!!: Too many open files
    perror("create File fd fail please check!!");
	// close error msg is :Too many open files
	fprintf(stderr,"close error msg is :%s\n",strerror(errno));
    return 0;
}
