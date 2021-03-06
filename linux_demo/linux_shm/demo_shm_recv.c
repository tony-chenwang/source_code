/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Name: 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date     
  * @brief
  * @History
*******************************************************************************/
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// MI must define before mi_common.h 
#define  MI_ENABLE_DBG  true
#define  DBG_LEVEL  MI_DBG_ALL

#include "mi_common.h"
#include "mi_internal.h"

// head file for share memory 
#include <sys/mman.h>
#include <sys/stat.h> 
#include <sys/shm.h>



#define CHECK_RET(X)  \
    {   \
        if( X < 0 )  \
        {   \
            DBG_ERR("INVALID RETURN VALUE \n");  \
            fprintf(stderr," error msg is :%s\n",strerror(errno));\
            exit(-1);\
        }   \
    }   \

        
#define SHMNAME  "MYSHAREMEM"

#define SHMSIZE  4096


int main(int argc,char *argv[])
{

    int fd = shm_open(SHMNAME,O_RDWR|O_CREAT|O_EXCL,0777);
    if(fd < 0)
    {
        fd = shm_open(SHMNAME,O_RDWR,0777);
    }
    else
        ftruncate(fd,SHMSIZE);
    
    void *ptr = mmap(NULL,SHMSIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    
    if( ptr == MAP_FAILED)
    {
         printf("MAP memory failed !!! \n");
    }

    while(1)
    {
       printf("The string of shm is %s \n",(char*)ptr);
      
       sleep(2);
    }

    pause();
    shm_unlink(SHMNAME);
    close(fd);
    return 0;
}



