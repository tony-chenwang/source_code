/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date     
  * @brief
     #if + 表达式 表达式内容为真 则会执行
     #if #else #endif              #if #elif #elif #endif 
  

     exit()  退出进程 会做一些善后处理的工作  退出状态码 可以 echo %?
     _exit() 立刻退出进程

     abort()  非正常退出 产生coredump 退出状态码 134

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

#define USE_MODE  4

int main(int argc,char * argv[])
{
    MI_PRINT(" This is my first demo! \n");

    #if ( USE_MODE == 1 )
	exit(1);
	#endif

    #if ( USE_MODE == 2 )
	exit(2);
	#endif

    #if ( USE_MODE == 3 )
	exit(3);
	#endif

    #if ( USE_MODE == 4 )
	abort();
	#endif

    return 0;
}
