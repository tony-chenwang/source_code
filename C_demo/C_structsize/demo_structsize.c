/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Name : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date   2018-04-01  
  * @brief
  		ÿÔÚ struct µÄ¶¨ÒåÖÐ×¢Òâ ±àÒëÆ÷»á¶Ô struct µÄ´óÐ¡½øÐÐÓÅ»¯ 

  		
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

typedef struct DEMOStruct_s
{
	MI_U32 u32a;
    MI_U8  u8b;
    MI_U64 u64c;
}DEMOStruct_t;


typedef struct DEMOStructpacked_s
{
	MI_U32 u32a;
    MI_U8  u8b;
    MI_U64 u64c;
}__attribute__((packed)) DEMOStructpaced_t;


int main(int argc,char * argv[])
{
    MI_PRINT("This is my first demo! %s builddate:%s %s\n",__FUNCTION__,__DATE__,__TIME__);

    DEMOStruct_t stDemoStruct;
    MI_PRINT("The size of stDemoStruct is %d \n",sizeof(stDemoStruct));

    DEMOStructpaced_t stDEMOStructpaced;
    MI_PRINT("The size of stDEMOStructpaced is %d \n",sizeof(DEMOStructpaced_t));

}
