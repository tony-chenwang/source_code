/*******************************************************************************
  * Copyright(C),2017,Mstar semi.co.,Ltd
  * @file Namev : filerd.c
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date 2017-12-24
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

int main(int argc,char * argv[])
{
    MI_U32 Filefd = -1;
    MI_U32 Filelength = -1;
    MI_U32 Readfilelength = -1;
    
    // the last para is if the file does not exsit  we create for this perms
    MI_U8* ReadBuffer =  (MI_U8 *)malloc(sizeof(MI_U8)*Buffersize);
    if ( NULL == Buffersize ) goto Fail;
    memset(ReadBuffer,0,sizeof(MI_U8)*Buffersize);
    //DBG_INFO("The read buffer size is %ld \n",sizeof(ReadBuffer));  
    //memset(ReadBuffer,0,sizeof(ReadBuffer));   //cannot use this style remind me  
    
    
    Filefd = open(pathname,O_RDONLY | O_CREAT,0755);
    if ( 0 > Filefd )  goto Fail;
    
    // set the file pointer to file end  to get  the file size 
    DBG_INFO("set the file pointer to end\n");
    Filelength = lseek(Filefd,0,SEEK_END);
    if ( 0 > Filelength) goto Fail;
    DBG_INFO("length of file is %d B  %d K\n",Filelength,Filelength/1024);
    
    // set the file pointer to file start
    DBG_INFO("set the file pointer to end\n");  
    Filelength = lseek(Filefd,0,SEEK_SET);    
    DBG_INFO("The value of  is Filelength %d \n",Filelength);    
 
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
   
    return 0;
    
Fail:
  	perror("operation Failed!\n");  
    return -1;
}
