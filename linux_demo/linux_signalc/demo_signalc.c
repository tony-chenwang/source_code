/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date     
  * @brief:
  			raise 函数是 发送信号给自己的进程 
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

#include "signal.h"
#include <sys/wait.h>

int main(int argc,char * argv[])
{
    MI_PRINT("This is my first demo! %s builddate:%s %s\n",__FUNCTION__,__DATE__,__TIME__);

   pid_t pid;
   int status;

   pid = fork();

   if(pid == 0)
   {
        MI_PRINT("this is the child process !! \n");
        sleep(5);
        raise(SIGKILL);
        
   }
   else if(pid > 0)
   {
        MI_PRINT("this is the father process !! \n");
        wait(&status);

        MI_PRINT("The child process status is %d \n",status);
   }
   else
   {
        perror("process create fail!! \n");
   }

     return 0;
}
