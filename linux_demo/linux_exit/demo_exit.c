/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date     
  * @brief
     #if + expression  if expression is true then compile
     #if #else #endif   #if #elif #elif #endif 
  

     exit()  exit task will do some opoeration use echo $? to get exit code 
     _exit() exit immediately

     abort() will cause coredump signal 6
     
  * @History
      19/02/24 review pass
      
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

#define USE_MODE  2

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
