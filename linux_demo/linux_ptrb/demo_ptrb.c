/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author   tony.chen@mstarsemi.com
  * @version  V1.0.0
  * @date     2018-01-24
  * @brief
			@brief  ���������ʹ��	
            void _demo_printarray(int *para)
            void _demo_printarray(int para[])
            void _demo_printarray(int para[10])

            ʵ�κ��β�֮���ǵ����ֵ���ݵĹ���   _demo_changeparaptr _demo_changepara

             
             ��һά������Ϊ����������ʱ�򣬱��������ǽ��������һ��ָ������Ԫ�ص�ַ��ָ��
             ��������ֵҲ���������� ֻ����һ��ָ��
  
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
  * @brief  ���������ʹ��	
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
  * @brief  ����ͨ��������������ǿ��Ըı������ֵ�ģ���Ϊ�����ϴ��ݵĶ���������Ԫ�صĵ�ַ
  
  * @param  ====>  void _demo_printarray(int para[10]) ���鲻�Ӻ����Ĵ�С ��Ϊ��������û������
  
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
