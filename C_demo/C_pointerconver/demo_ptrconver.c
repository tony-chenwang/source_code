/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Name : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date     2018 - 04 -02
  * @brief:
  		ÿÈç¹û MI_U32 µÄÖµĞ¡ÓÚ 0xFF µÄ»° ²»»á²úÉúÎÊÌâ
  		  Èç¹û ´óÓÚ 0xFF Ôò»á²úÉúÎÊÌâ
  		  
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

    MI_U32 * ptr = NULL;

    //MI_U32 value = 100;
    MI_U32 value = 0xFFFF;
    ptr = &value;
    MI_PRINT("The value of ptr is %p %x \n",ptr,*ptr);


    // conver pointer will cause problem
    *((MI_U8*)ptr) = 0;
    MI_PRINT("The value of ptr is %p %x \n",ptr,*ptr);


    
    



     return 0;
}
