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



int main(int argc,char * argv[])
{
    MI_PRINT("This is my first demo! %s builddate:%s %s\n",__FUNCTION__,__DATE__,__TIME__);
    
    int msqid = 0; // message queue id 
    int msg_type;
    char str[100];
    struct msgstru msgs;    
    int ret_value;
    
    msqid=msgget(MSGKEY,IPC_EXCL);  /*检查消息队列是否存在*/  
    
    if(msqid < 0)
    {    
        msqid = msgget(MSGKEY,IPC_CREAT|0666);/*创建消息队列*/    
        if(msqid <0)
        {    
            printf("failed to create msq | errno=%d [%s]\n",errno,strerror(errno));    
            exit(-1);    
        }    
     } 

     while(1)
     {
		printf("input message type(end:0):");    
		scanf("%d",&msg_type);    
        
		if (msg_type == 0)    
		break;    
        
		printf("input message to be sent:");    
		scanf ("%s",str);    
		msgs.msgtype = msg_type;    
		strcpy(msgs.msgtext, str);    

        
		/* 发送消息队列 如果消息队列无法立刻发送 函数会立刻返回 IPC_NOWAIT*/    
		ret_value = msgsnd(msqid,&msgs,sizeof(struct msgstru),IPC_NOWAIT);    
		if ( ret_value < 0 ) 
        {    
		    printf("msgsnd() write msg failed,errno=%d[%s]\n",errno,strerror(errno));    
		    exit(-1); 
        }

    }

    msgctl(msqid,IPC_RMID,0); //删除消息队列     
    

     return 0;
}
