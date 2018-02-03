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



MI_BOOL _demo_createsopa(void)
{
	CHECK_RET(socketpair(AF_UNIX,SOCK_STREAM,0,socketfd));
	return TRUE;
}



int main(int argc,char * argv[])
{
    MI_PRINT("This is my socket pair  demo! \n");
    
    _demo_createsopa();
    CHECK_RET(write(socketfd[0] , WriteString , strlen(WriteString)));


    sleep(5);
	
	CHECK_RET(read(socketfd[1], Readbuffer , BUFFERSIZE ));
    MI_PRINT("Read string in same process : %s \n",Readbuffer); 
    MI_PRINT("reach the end of main \n");


    /*CHECK_RET(read(socketfd[0], Readbuffer, BUFFERSIZE));
    printf("Read from s0 :%s\n",buf); 
    return 0;*/
}


