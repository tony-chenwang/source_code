/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date     
  * @brief:
  			socket pair 的作用类似于  pipe 无名管道 ，但是它最大的特点是
  			无名管道 写段和读的一端是固定的  但是socketpair 不区分写端和读端
  * @History
*******************************************************************************/
#include <sys/types.h>
#include <sys/socket.h>   //must define this for socket pair demo 

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

#define BUFFERSIZE 50
#define debug_module  2

#define CHECK_RET(X)  \
    {   \
        if( X < 0 )  \
        {   \
            DBG_ERR("INVALID RETURN VALUE \n");  \
            fprintf(stderr," error msg is :%s\n",strerror(errno));\
            exit(-1);\
        }   \
    }   \


MI_S32 socketfd[2] = {0};
MI_S8* WriteString = "This is tony call 2018 0203";

MI_S8 Readbuffer[BUFFERSIZE] = {0};
pid_t pid = 0;


MI_BOOL _demo_createsopa(void)
{
	CHECK_RET(socketpair(AF_UNIX,SOCK_STREAM,0,socketfd));
	return TRUE;
}



int main(int argc,char * argv[])
{
    MI_PRINT("This is my socket pair  demo! \n");
    
    _demo_createsopa();

#if (debug_module == 1)
    CHECK_RET(write(socketfd[0] , WriteString , strlen(WriteString)));
    sleep(5);
	CHECK_RET(read(socketfd[1], Readbuffer , BUFFERSIZE ));
    MI_PRINT("Read string in same process : %s \n",Readbuffer); 
    MI_PRINT("reach the end of main \n");
	
#elif (debug_module == 2)

    if((pid = fork()) > 0)
	{ 
        MI_PRINT("Parent process's pid is %d\n",getpid()); 
        close(socketfd[1]); 
        CHECK_RET(write(socketfd[0] ,WriteString ,strlen(WriteString) ));
        MI_PRINT("Send string success!! \n");
	}
	else if(pid == 0)
	{ 
        MI_PRINT("Fork child process successed\n"); 
        MI_PRINT("Child process's pid is :%d\n",getpid()); 
        close(socketfd[0]);
		sleep (10);
		MI_S8 eRet = read(socketfd[1] ,Readbuffer ,BUFFERSIZE);
		if( eRet == -1)
			MI_PRINT("Read string  error in process %d :\n",getpid()); 
		else
			MI_PRINT("Read string %s in process %d\n",Readbuffer,getpid());
	}
	else
	{ 
	        printf("Fork failed:%s\n",strerror(errno)); 
	        exit(-1); 
	} 

#endif

#if 0
    MI_S8 eRet = read(socketfd[1] ,Readbuffer ,BUFFERSIZE);

    if( eRet == -1)
		MI_PRINT("Read string  error in process %d :\n",getpid()); 
    else
		MI_PRINT("Read string %s in process \n",Readbuffer,getpid());
#endif

    MI_PRINT("reach the end of main %d \n",getpid());
    pause();
    return TRUE;

}


