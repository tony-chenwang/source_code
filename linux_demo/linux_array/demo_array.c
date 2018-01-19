/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date  2018-01-19     
  * @brief
  * @History
		we know this case
		&array[0] +1 = address + sizeof(MI_U8)
		&array +1  = address + sizeof(MI_U8)*arraylength
	

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
    MI_PRINT("This is my array pointer demo! \n");

    MI_U8 demo_arry[10] = {10,11,12,13,14,15,16,17,18,19};
    MI_U8 (*p)[10] = {20,21,22,23,24,25,26,27,28,29};


	MI_U8* ptr = &demo_arry[0];
    //MI_U8* ptr = demo_arry;
    //MI_U8* ptr = &demo_arry;
	
    DBG_ERR("The address of demo_arry is %p \n",demo_arry);
	DBG_ERR("The address of demo_arry[0] is %p value is %d\n",&demo_arry[0],demo_arry[0]);
	DBG_ERR("The address of demo_arry[1] is %p value is %d\n",&demo_arry[1],demo_arry[1]);
	DBG_ERR("The address of demo_arry[2] is %p value is %d\n",&demo_arry[2],demo_arry[2]);

   
   	DBG_ERR("The address of demo_arry[0] +1 is %p value is %d\n",&demo_arry[0]+1,*(&demo_arry[0]+1));
	DBG_ERR("The address of demo_arry[1] +1 is %p value is %d\n",&demo_arry[1]+1,*(&demo_arry[1]+1));
	DBG_ERR("The address of demo_arry[2] +1 is %p value is %d\n",&demo_arry[2]+1,*(&demo_arry[2]+1));
  
  
    DBG_ERR("The address of demo_arry +1 is %p value is %d\n",&demo_arry+1,*(demo_arry+1));
	DBG_ERR("The address of demo_arry +1 is %p value is %d\n",&demo_arry+2,*(demo_arry+2));

    DBG_ERR("------------------------------------------------\n");

    DBG_ERR("the value of p[0] is %d address %x\n",p[0],p);
	DBG_ERR("the value of p[1] is %d address %x\n",p[1],&p[1]);
    DBG_ERR("the value of p[1] is %d address %x\n",p[2],&p[2]);

	DBG_ERR("------------------------------------------------\n");
    DBG_ERR("the value of p[0] is %d address %x\n",*ptr,ptr);
	DBG_ERR("the value of p[1] is %d address %x\n",*ptr+1,ptr+1);
    DBG_ERR("the value of p[2] is %d address %x\n",*ptr+2,ptr+2);
	DBG_ERR("------------------------------------------------\n");
    DBG_ERR("the value of p[0] is %d address %x\n",ptr[0],ptr);
	DBG_ERR("the value of p[1] is %d address %x\n",ptr[1],ptr+1);
    DBG_ERR("the value of p[2] is %d address %x\n",ptr[2],ptr+2);	
    pause();

     return 0;
}
