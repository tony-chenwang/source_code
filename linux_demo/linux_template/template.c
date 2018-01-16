/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
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

int main(int argc,char * argv[])
{
    MI_PRINT(" This is my first demo! \n");
    MI_U32 ValueA = 100;
	MI_U32 ValueB = 200;
    MI_U32 ValueC = 300;
	MI_U32 ValueMAX = 0;
	MI_U32 ValueMIN = 0;
   
     while(1)
     {
        system("clear");	
	MI_U32 ALIGNVALUE = 13+16;
	MI_PRINT("The ALIGN value  is %d \n",ALIGN_DOWNTO_16(ALIGNVALUE));
	MI_PRINT("The ALIGN value  is %d \n",MEM_ALIGN(ALIGNVALUE,16));

	GETMAX(ValueMAX,ValueA,ValueB,ValueC)
        MI_PRINT("The MAX value of A&B&C is %d \n",ValueMAX);

	GETMIN(ValueMIN,ValueA,ValueB,ValueC)
	MI_PRINT("The MIN value of A&B&C is %d \n",ValueMIN);
        sleep(2);    
    } 
     return 0;
}
