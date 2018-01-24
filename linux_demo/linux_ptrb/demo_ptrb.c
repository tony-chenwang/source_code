/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author   tony.chen@mstarsemi.com
  * @version  V1.0.0
  * @date     2018-01-24
  * @brief
			@brief  数组参数的使用	
            void _demo_printarray(int *para)
            void _demo_printarray(int para[])
            void _demo_printarray(int para[10])

            实参和形参之间是单向的值传递的过程   _demo_changeparaptr _demo_changepara

             
             当一维数组作为函数参数的时候，编译器总是将其解析成一个指向其首元素地址的指针
             函数返回值也不能是数组 只能是一个指针
  
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


#define demo_caseb 

/*
void _demo_printarray(int para[])
{
    MI_PRINT("Now in function:%s line:%d \n",__FUNCTION__,__LINE__);
	MI_PRINT("the size of para array is %d \n",sizeof(para));
    MI_PRINT("the value of para array is %d %d %d %d %d \n",
					para[0],para[1],para[2],para[3],para[4]);
    
}
*/

/****************************************************
  * @functionName _demo_printarray
  * @brief  数组参数的使用	
            void _demo_printarray(int *para)
            void _demo_printarray(int para[])
            void _demo_printarray(int para[10])
  * @param
  * @retval
****************************************************/
void _demo_printarray(int *para)
{
    MI_PRINT("Now in function:%s line:%d \n",__FUNCTION__,__LINE__);
	MI_PRINT("the size of para array is %d \n",sizeof(para));
    MI_PRINT("the value of para array is %d %d %d %d %d \n",
					para[0],para[1],para[2],para[3],para[4]);
    
}


#ifdef demo_casea
/****************************************************
  * @functionName _demo_printarray
  * @brief  函数通过传递数组参数是可以改变数组的值的，因为本质上传递的都是数组首元素的地址
  
  * @param  ====>  void _demo_printarray(int para[10]) 建议不加函数的大小 因为参数本身没有意义
  
  * @retval
****************************************************/
void _demo_printarray(int para[])
{
    MI_PRINT("Now in function:%s line:%d \n",__FUNCTION__,__LINE__);
	MI_PRINT("the size of para array is %d \n",sizeof(para));
    MI_PRINT("the value of para array is %d %d %d %d %d \n",
					para[0],para[1],para[2],para[3],para[4]);
    para[0] += 1;
	para[1] += 1;
	para[2] += 1;
	para[3] += 1;
	para[4] += 1;
}
#endif

void _demo_changepara(int para)
{
	MI_PRINT("Now in function:%s line:%d \n",__FUNCTION__,__LINE__);
	para = 2;
}

void _demo_changeparaptr(int *para)
{
	MI_PRINT("Now in function:%s line:%d \n",__FUNCTION__,__LINE__);
	*para = 2;
}


int main(int argc,char * argv[])
{
    MI_PRINT("This is my pointer array demo! \n");

    int arrays[5] = {1,2,3,4,5};
	//int arrays[50] = {0};
    _demo_printarray(arrays);   

    int var = 10;
    _demo_changepara(var);
	MI_PRINT("the value of var is %d \n",var);

	_demo_changeparaptr(&var);
	MI_PRINT("the value of var is %d \n",var);	

     return 0;
}
