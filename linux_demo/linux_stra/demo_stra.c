/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date   2018-01-13  
  * @brief
           这时的buffer 是输入
sscanf int sscanf(char *buffer,const char *format[argument])


format %s 字符串
       %*s 忽略某个字符串
       %[^/] 匹配字符 /
       %[^=] 匹配字符 =
       %*[^/] 忽略开始到 / 中间的字符串
       %4s  截取前面四个字符串

      这时的buffer 是输出
      int sprintf(char *buffer,const char *format[argument])


  
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
 
#define InputBufferlength  100
int main(int argc,char * argv[])
{
    MI_PRINT(" This is my first demo! \n");
	MI_U8 ValueA = 0;
	MI_U8 ValueB = 0;
	MI_U8 StringBufferP[100] = {0};
	MI_U8 StringBufferV[100] = {0};

	/* %*s 表示忽略 某个字符串  */
	/*读取字符串截止的标志是 空格 跳格 或者 换行*/
    MI_U8 InputBuffer[InputBufferlength] = "3 + 5 = 4";
	sscanf(InputBuffer,"%d %s %d",&ValueA,StringBufferP,&ValueB);
	MI_PRINT("The ValueA is %d ValueB is %d \n",ValueA,ValueB);


	strcpy(InputBuffer,"tony like reading");
    sscanf(InputBuffer,"%s %*s %s",StringBufferP,&StringBufferV);
    MI_PRINT("The stringbufferP is %s \n",StringBufferP);
	MI_PRINT("The stringbufferV is %s \n",StringBufferV);

    /*用于字符串的截取 特定的长度*/
    strcpy(InputBuffer,"GodBlessyou");
    sscanf(InputBuffer,"%3s",StringBufferP);
	sscanf(InputBuffer,"%8s",StringBufferV);
    MI_PRINT("The stringbufferP is %s \n",StringBufferP);
	MI_PRINT("The stringbufferV is %s \n",StringBufferV);


    strcpy(InputBuffer,"bootvideo=/system/media/bootvideo.mp4");
    sscanf(InputBuffer,"%[^=] %*1s %s",StringBufferP,StringBufferV);
    MI_PRINT("The stringbufferP is %s \n",StringBufferP);
	MI_PRINT("The stringbufferV is %s \n",StringBufferV);

	strcpy(InputBuffer,"/system/media/bootvideo.mp4");
    sscanf(InputBuffer,"%*[^/] %s %*[^/]",StringBufferP);
    MI_PRINT("The stringbufferP is %s \n",StringBufferP);


    MI_PRINT("--------------------- \n");
    memset(InputBuffer,0x00,sizeof(InputBuffer));
	ValueA = 100;
	ValueB= 200;
	sprintf(InputBuffer,"%d is %s %d %s %d",ValueA+ValueB,"equal",ValueA,"+",ValueB);
    MI_PRINT("The InputBuffer is %s \n",InputBuffer);

    return 0;
}
