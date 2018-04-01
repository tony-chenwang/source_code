/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date     
  * @brief
          alarm() send signal to self process alarm пе╨е
          rasie()  send signal to self
          kill(pid,sign_no) send sign_no to pid 
  
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


#define CHECK_RET(X)  \
    {   \
        if( X < 0 )  \
        {   \
            DBG_ERR("INVALID RETURN VALUE \n");  \
            fprintf(stderr," error msg is :%s\n",strerror(errno));\
            exit(-1);\
        }   \
    }   \

void SIGNAL_HANDLER(int sign_no)
{
   MI_PRINT("The get signal number is %d \n",sign_no);

}


int main(int argc,char * argv[])
{
    MI_PRINT("This is my first demo! %s builddate:%s %s\n",__FUNCTION__,__DATE__,__TIME__);

    signal(SIGALRM,SIGNAL_HANDLER);
    signal(SIGINT,SIGNAL_HANDLER);
    signal(SIGTSTP,SIGNAL_HANDLER);

#if 0
    alarm(10);

    sleep(5);

    raise(SIGALRM);
#endif

    int status;
    pid_t pid = fork();

    if(pid == 0)
    {
 	    MI_PRINT("[child]This is the child process !!\n");
        MI_PRINT("[chid]The pid number is %d ppid number is  %d \n",getpid(),getppid());
        pause();
    }
    else if(pid > 0)
    {
       MI_PRINT("[father]This is the father process !! \n");
       MI_PRINT("[father]The pid number is %d !! \n",pid);

       sleep(5);
       kill(pid,SIGINT);
 
  	   wait(&status);
       MI_PRINT( "child process return %d\n", status);
    }
    else
    {
    	MI_PRINT("fork error please check !!\n");
    }


    return 0;
}
