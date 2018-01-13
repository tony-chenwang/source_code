/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date     
  * @brief  including rand & srand fucntion


             srand(time(NULL)); 必须先执行一次 否则程序每次运行产生的随机数都是一致的
             
             rand() 每次返回一个随机数


  
  * @History
*******************************************************************************/
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// MI must define before mi_common.h 
#define  MI_ENABLE_DBG  true
#define  DBG_LEVEL  MI_DBG_ALL

#include "mi_common.h"
#include "mi_internal.h"

#define RANDARRAY_LENGTH 10

#define srand_mac 1

volatile MI_U8 RANDARRAY[RANDARRAY_LENGTH] = {0};

int main(int argc,char * argv[])
{
    int i = 0;
    MI_PRINT(" This is my random demo! \n");
    DBG_WRN("The MAX of random value is %d HEX %x \n", RAND_MAX,RAND_MAX);

#ifdef srand_mac
    srand(time(NULL));
#endif	

    for (i = 0;i < 10; i++)
		RANDARRAY[i] = rand()%0xffff;
	
    DBG_WRN("RANDARRAY 0-9 is %d %d %d %d %d %d %d %d %d %d \n", \
		RANDARRAY[0],RANDARRAY[1],RANDARRAY[2],RANDARRAY[3],RANDARRAY[4],RANDARRAY[5],RANDARRAY[6], \
		RANDARRAY[7],RANDARRAY[8],RANDARRAY[9]);

    for (i = 0;i < 10; i++)
	RANDARRAY[i] = rand()%0xffff;
	
    DBG_WRN("RANDARRAY 0-9 is %d %d %d %d %d %d %d %d %d %d \n", \
		RANDARRAY[0],RANDARRAY[1],RANDARRAY[2],RANDARRAY[3],RANDARRAY[4],RANDARRAY[5],RANDARRAY[6], \
		RANDARRAY[7],RANDARRAY[8],RANDARRAY[9]);
	
		
    return 0;
}
