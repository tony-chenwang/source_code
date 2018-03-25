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

typedef enum
{
    PRIVATE_DBG_NONE = 0,
    PRIVATE_DBG_ERR,
    PRIVATE_DBG_WRN,
    PRIVATE_DBG_INFO,
    PRIVATE_DBG_ALL
}PRIVATE_DBG_LEVEL_e;



#define PrivateDebuglevel PRIVATE_DBG_ALL

MI_U32  u32PrivateDebuglevel = PRIVATE_DBG_ALL;


#define PRIVATE_DBG_INFO(fmt, args...)      ({do{if(PrivateDebuglevel>=PRIVATE_DBG_INFO){printf(ASCII_COLOR_GREEN);printf(fmt, ##args);printf(ASCII_COLOR_END);}}while(0);})
#define PRIVATE_DBG_WRN(fmt, args...)       ({do{if(PrivateDebuglevel>=PRIVATE_DBG_WRN){printf(ASCII_COLOR_YELLOW);printf(fmt, ##args);printf(ASCII_COLOR_END);}}while(0);})
#define PRIVATE_DBG_ERR(fmt, args...)       ({do{if(PrivateDebuglevel>=PRIVATE_DBG_ERR){printf(ASCII_COLOR_RED"[MI ERR ]: %s[%d]: ", __FUNCTION__,__LINE__);printf(fmt, ##args);printf(ASCII_COLOR_END);}}while(0);})

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
    MI_PRINT("This is my dynamic debug level demo! %s builddate:%s %s\n",__FUNCTION__,__DATE__,__TIME__);

    u32PrivateDebuglevel = atoi(argv[1]);
    
    PRIVATE_DBG_INFO("This is private INFO!! \n");
    PRIVATE_DBG_WRN("This is private WARN!! \n");
    PRIVATE_DBG_ERR("This is private ERR!! \n");
    
     return 0;
}
