/*******************************************************************************
  * Copyright(C),2017,Mstar semi.co.,Ltd
  * @file Namev : filerd.c
  
  * @author   tony.chen@mstarsemi.com
 
  * @version  V1.0.0
  
  * @date     2017-12-24
  
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
// get the BufferSize is 2000 B 
#define Buffersize  2000

const char * pathname = "demo.txt";


#define demo_normal 1

int main(int argc,char * argv[])
{
    MI_U32 Filefd = -1;
    MI_U32 Filelength = -1;
    MI_U32 Readfilelength = -1;
    
    // the last para is if the file does not exsit  we create for this perms
    MI_U8* ReadBuffer =  (MI_U8 *)malloc(sizeof(MI_U8)*Buffersize);
    if ( NULL == ReadBuffer ) goto Fail;
    memset(ReadBuffer,0,sizeof(MI_U8)*Buffersize);


    // 这里要注意 使用 sizeof获取 buffer 长度的区别	
    MI_U32 demoBuffer[100] = {0};
    DBG_INFO("The read buffer size is %ld \n",sizeof(ReadBuffer));  
	DBG_INFO("The demo buffer size is %ld \n",sizeof(demoBuffer)); 



#if  demo_normal == 1

    Filefd = open(pathname,O_RDONLY | O_CREAT,0777);

#elif demo_normal == 2

    Filefd = open(pathname,O_RDWR| O_CREAT,0777);

#endif

    if ( 0 > Filefd )  goto Fail;
    
    // set the file pointer to file end  to get  the file size 
    DBG_INFO("set the file pointer to end\n");
    Filelength = lseek(Filefd,0,SEEK_END);
    if ( 0 > Filelength) goto Fail;
    DBG_INFO("length of file is %d B  %d K\n",Filelength,Filelength/1024);
    
    // set the file pointer to file start
    DBG_INFO("set the file pointer to start\n");  
    Filelength = lseek(Filefd,0,SEEK_SET);    
    DBG_INFO("The value of  is Filelength %d \n",Filelength);    



#if demo_normal == 1

   while(1) 
   {
        Readfilelength = read(Filefd,ReadBuffer,10);
        DBG_INFO("The Readfilelength is %d \n",Readfilelength);
        if ( Readfilelength > 0 )
        {
          DBG_INFO("read buffer is %s \n",ReadBuffer);
          DBG_ERR("now the position is %ld \n",lseek(Filefd,0,SEEK_CUR));
        }
        else if ( Readfilelength == 0 )
        {
          DBG_INFO("get the end of this file \n");
          break;
        }
        else
          goto  Fail;    
      
        usleep(100000);
   }
   
#elif demo_normal == 2
    MI_U32 offset = 0;
    MI_S32 eRet = 0;

	eRet = write(Filefd,"I am tony",strlen("I am tony"));
    if ( eRet < 0 ) goto Fail;

	
	DBG_INFO("The write return value is %d \n",eRet);
	offset = lseek(Filefd,1024UL*1024UL*1024UL,SEEK_END);
    DBG_INFO("The current offset is %ld \n",offset);
    DBG_ERR("now the position is %ld \n",lseek(Filefd,0,SEEK_CUR));

#endif

    return 0;
    
Fail:
  	perror("operation Failed!\n");  
    return -1;
}
