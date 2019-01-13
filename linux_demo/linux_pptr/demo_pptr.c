/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date     2018-01-24
  * @brief
		1. real para only pass to seeming para ne way
		2. change pointer value using pptr or function return value

  
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

/****************************************************
  * @functionName demo_getmemory
  * @brief  this function says we cannot change real para 
  * @param
  * @retval NULL
****************************************************/
void demo_getmemory( int *p, MI_U16 length )
{
    p = (int *)malloc(sizeof(int)*length);
    ASSERT(p);
}

int * demo_getmemoryptr(MI_U16 length)
{
    int *p = (int *)malloc(sizeof(int)*length);
    ASSERT(p);

    return p;
}


int * demo_getmemorypptr(int **p,MI_U16 length)
{
    *p = (int *)malloc(sizeof(int)*length);
    ASSERT(p);

    return *p;
}



int main(int argc,char * argv[])
{
    MI_PRINT("This is my pptr demo! \n");
	
    int *pointer = NULL;
    demo_getmemory(pointer,100);
    MI_PRINT("The address of pointer is %p \n",pointer);


    pointer = NULL;
    pointer = demo_getmemoryptr(100);
    MI_PRINT("The address of pointer is %p \n",pointer);
    memset(pointer,0xAA,100);



   pointer = NULL;
   int * eRetpointer = NULL;
   eRetpointer = demo_getmemorypptr(&pointer,100);
   MI_PRINT("The address of pointer is %p \n",pointer);
   MI_PRINT("The address of eRetpointer is %p \n",eRetpointer);

     return 0;
}
