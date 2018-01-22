/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date   2018-01-20 
  * @brief
		demo for  double free cannor double free & must ptr = NULL after free
		demo for  macro
		demo for  assert        we define ASSERT(x) only x=null it will coredump 
        demo for  backtrace     only can use in android 
  
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

#define demo_mem_length 100

#define TIME_CUS  

int main(int argc,char * argv[])
{
#ifdef TIME_CUS
    FUNCTION_IN_TIME  // use this macro we can calulate the time of function
#endif

    MI_PRINT("This is my pointer demo! \n");

	MI_U8* ptr = NULL;
    ptr = (MI_U8 *)malloc(sizeof(MI_U8)*demo_mem_length);
    ASSERT(ptr);

	free(ptr);
	//free(ptr);  // cannot free ptr double or will dump heap

    ptr = NULL;  //  free 完空间之后 一定要将 指针设置为 NULL  否则无法使用 ASSERT 函数
    //ASSERT(ptr);

#ifdef TIME_CUS
    usleep(1000); 
    RETURN(0); // use this macro we can calulate the time of function
#else
    pause();
    return 0;
#endif
}
