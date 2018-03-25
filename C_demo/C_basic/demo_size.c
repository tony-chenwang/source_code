/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Name : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date    2018-03-14 
  * @brief
         验证 在 64 bit 的系统上 各个基本数据类型所占的字节数

         注意 指针变量 所占的字节数都是一定的
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

    MI_PRINT("The size of short is %d \n",sizeof(short));
    MI_PRINT("The size of char is %d \n",sizeof(char));
    MI_PRINT("The size of int is %d \n",sizeof(int));
    MI_PRINT("The size of double is %d \n",sizeof(double));
    MI_PRINT("The size of long is %d \n",sizeof(long));
    MI_PRINT("The size of float is %d \n",sizeof(float));

    MI_PRINT("The size of int* is %d \n",sizeof(int*));
    MI_PRINT("The size of char* is %d \n",sizeof(char*));
    MI_PRINT("The size of float* is %d \n",sizeof(float*));
    MI_PRINT("The size of long* is %d \n",sizeof(long*));
    MI_PRINT("The size of short* is %d \n",sizeof(short*));
    
     return 0;
}
