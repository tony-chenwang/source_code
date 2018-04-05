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

#include <sys/ipc.h> 
#include <sys/msg.h> 


#define CHECK_RET(X)  \
    {   \
        if( X < 0 )  \
        {   \
            DBG_ERR("INVALID RETURN VALUE \n");  \
            fprintf(stderr," error msg is :%s\n",strerror(errno));\
            exit(-1);\
        }   \
    }   \

        
#define MSGKEY 7777


struct msgstru    
{    
   long msgtype;    
   char msgtext[2048];     
};


/*子进程，监听消息队列*/    
void _DEMO_Msg_Recv()
{    
  struct msgstru msgs;    
  int msgid,ret_value;     
      
  while(1)
  {    
     msgid = msgget(MSGKEY,IPC_EXCL );/*检查消息队列是否存在 */    
     
     if(msgid < 0)
     {    
        printf("msq not existed! errno=%d [%s]\n",errno,strerror(errno));    
        sleep(2);    
        continue;    
     }    

     
     /*接收消息队列 IPC_NOWAIT 表示立刻返回  而 选择 0 表示会 阻塞进程 等待 接收到消息*/    
     //ret_value = msgrcv(msgid,&msgs,sizeof(struct msgstru),0,0);    
     ret_value = msgrcv(msgid,&msgs,sizeof(struct msgstru),0,IPC_NOWAIT);

     
     if(ret_value < 0)
        printf("message queue recieve error please check !! \n");
     else
     {
        printf("text=[%s] pid=[%d]\n",msgs.msgtext,getpid());   
     }

     usleep(300000);
  }    
  return;    
} 



int main(int argc,char * argv[])
{
    MI_PRINT("This is my first demo! %s builddate:%s %s\n",__FUNCTION__,__DATE__,__TIME__);
    
    _DEMO_Msg_Recv();

    
     return 0;
}
