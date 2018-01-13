/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date     2018 01-13
  * @brief
          learn string function demo 1
          including
          memset
          memcpy
          memcmp
          memchr
          memmove

memmove  void* memmove(void *dst ,const void* source ,unsigned int count)
         从src 指向的 的 memory 拷贝 count 字节到 dst 指向的 memory 中
         但是其考虑内存重叠问题
         http://blog.csdn.net/li_ning_/article/details/51418400


memcpy    void* memcpy(void *dst ,const void* source ,unsigned int count)


memcmp    int memcmp(const void*buf1 , const void* buf2,usigned count)
          =0 buf1 == buf2  比较前count字节的大小
          >0 buf1 > buf2
          <0 buf1 < buf2  注意其比较的是ASCII 码

memchr    void * memchr(const void* buf1 , int c ,unsigned count)
          从 buf1 前count 字节中 查找 字符 如果找到 或者 count 字节完毕 查找结束
          返回的是 c 位置的 指针

memset   void * memset(void *buf ,int value ,unsigned count)

  			
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


#define  DEMO_MEM_LENGTH  100

const MI_S8* psrcString = "Happy new year";

const MI_S8* psrcStringMove = "I am tony";


const MI_S8  key_char ='n';

int main(int argc,char * argv[])
{
    MI_PRINT(" This is my demo for string! \n");
    MI_U8 * pDemomemory = NULL;
    pDemomemory = (MI_U8*)malloc(sizeof(MI_U8)*DEMO_MEM_LENGTH);
	if(!pDemomemory) 
		goto FAIL;

    MI_PRINT("After malloc pDemomemory 0-5 %d,%d,%d,%d,%d \n", \
		pDemomemory[0],pDemomemory[1],pDemomemory[2],pDemomemory[3],pDemomemory[4]);

	memset(pDemomemory,0x00,sizeof(MI_U8)*DEMO_MEM_LENGTH);
	
    MI_PRINT("After memset 0x00 pDemomemory 0-5 %d,%d,%d,%d,%d \n", \
	pDemomemory[0],pDemomemory[1],pDemomemory[2],pDemomemory[3],pDemomemory[4]);


	memset(pDemomemory,0xAB,sizeof(MI_U8)*DEMO_MEM_LENGTH);

	MI_PRINT("After memset 0x00 pDemomemory 0-5 %x,%x,%x,%x,%x \n", \
	pDemomemory[0],pDemomemory[1],pDemomemory[2],pDemomemory[3],pDemomemory[4]);

    /*cp string to pDemomemory when not equal  must be +1 for \0 end*/
	/* memcpy(dst ,src )*/
    memcpy(pDemomemory,psrcString,strlen(psrcString)+1);
    MI_PRINT("the value of pDemomemory is %s\n",pDemomemory);

   MI_U8 eRet = 0xFF;
   eRet = memcmp(pDemomemory,psrcString,strlen(psrcString)+1);
   MI_PRINT("the memcmp %d Byte result is %d\n",strlen(psrcString)+1,eRet);

   /*this means memcmp donnot think of overflow becase it compare as string */
   /*
   eRet = 0xFF; 
   eRet = memcmp(pDemomemory,psrcString,strlen(psrcString)+10);
   MI_PRINT("the memcmp %d Byte result is %d\n",strlen(psrcString)+10,eRet);
   
   	MI_PRINT("After memset 0x00 pDemomemory 0-5 %x,%x,%x,%x,%x \n", \
	pDemomemory[16],pDemomemory[17],pDemomemory[18],pDemomemory[19],pDemomemory[20]);

	MI_PRINT("After memset 0x00 psrcString 0-5 %x,%x,%x,%x,%x \n", \
	psrcString[16],psrcString[17],psrcString[18],psrcString[19],psrcString[20]);
   */

#ifdef memcmp_demo
    eRet = 0;
    pDemomemory[0] = 0xab;
    eRet = memcmp(pDemomemory,psrcString,strlen(psrcString)+1);
    MI_PRINT("after change the memcmp %d Byte result is %d\n",strlen(psrcString)+1,eRet);
#endif

   // it means location must be +1 to get real pos
   MI_S8 * pkeychar= NULL;
   pkeychar = memchr(pDemomemory,key_char,strlen(psrcString)+1);
   MI_PRINT("the res of keychar is %s pointer is %x start is %x location is %d\n", \
   		pkeychar,pkeychar,pDemomemory, (MI_U8)((MI_U8*)pkeychar - (MI_U8*)pDemomemory) +1);
 

   
    memmove(pDemomemory,psrcStringMove,strlen(psrcStringMove)+1);
    MI_PRINT("the value of pDemomemory is %s\n",pDemomemory);

	

    return 0;

FAIL:
    perror("FAIL to malloc memory !! \n");
    return 0;
}
