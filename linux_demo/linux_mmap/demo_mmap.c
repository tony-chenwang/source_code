/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
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

#include <sys/mman.h>


#define CHECK_RET(X)  \
    {   \
        if( X < 0 )  \
        {   \
            DBG_ERR("INVALID RETURN VALUE \n");  \
            fprintf(stderr," error msg is :%s\n",strerror(errno));\
            exit(-1);\
        }   \
    }   \


int main(int argc,char * argv[])
{
    MI_PRINT("This is my first demo! %s builddate:%s %s\n",__FUNCTION__,__DATE__,__TIME__);

    int fd = -1;
    char * pmapaddr = NULL;
    MI_U32 u32PageSize = 0;
    MI_U32 u32MapLength = 1024*4;
    
    if( argc < 2) 
    {
         MI_PRINT("The para is error please check !! \n");
    }

    fd = open(argv[1],O_RDWR);     
    CHECK_RET(fd);

    u32PageSize = sysconf(_SC_PAGESIZE);  
    MI_PRINT("pagesize is %d\n",u32PageSize);

    
    pmapaddr = mmap(NULL,u32MapLength,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

    if ( pmapaddr == NULL )
        MI_PRINT(" map failed  please check !! \n");

    
    MI_PRINT("The buffer is %s \n",pmapaddr);

    strcpy(pmapaddr,"HaHaha I am a shine boy");

    munmap(pmapaddr,u32PageSize);


    pause();
     return 0;
}
