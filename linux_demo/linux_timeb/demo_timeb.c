/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Name : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date    2018-03-11
  * @brief
  * @History
		clock_gettime func
  
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

#include "time.h"

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

    struct timespec time1 = {0, 0};  // 秒为单位  纳秒为单位 

    while(1)
    {
    //返回从 1970 年到现在的 所经过的 秒数 
    clock_gettime(CLOCK_REALTIME, &time1);        
    printf("CLOCK_REALTIME: %d, %d\n", time1.tv_sec, time1.tv_nsec);  


    // 从系统启动的时刻到现在的秒数 功能 和 cat /proc/uptime 是一致的
    clock_gettime(CLOCK_MONOTONIC, &time1);        
    printf("CLOCK_MONOTONIC: %d, %d\n", time1.tv_sec, time1.tv_nsec);    

    // skip 
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);        
    printf("CLOCK_PROCESS_CPUTIME_ID: %d, %d\n", time1.tv_sec, time1.tv_nsec);   

    // skip 
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time1);        
    printf("CLOCK_THREAD_CPUTIME_ID: %d, %d\n", time1.tv_sec, time1.tv_nsec);   
     
    printf("\n%d\n", time(NULL)); 

    usleep(100000);

    }
    
 
    return 0;
}


