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
	
typedef enum  E_DEMO_VALUE
{
	E_DEMO_VALUE_A = 0x00,

	E_DEMO_VALUE_B,

	E_DEMO_VALUE_C,

	E_DEMO_VALUE_D,

	E_DEMO_VALUE_E,

	E_DEMO_VALUE_MAX

}DEMO_VALUE_E;


MI_BOOL _demo_switch_A(DEMO_VALUE_E param)
{
	switch(param)
	{
		case E_DEMO_VALUE_A:
			MI_PRINT("IN E_DEMO_VALUE_A case %s\n",__FUNCTION__);
			
		case E_DEMO_VALUE_B:
			MI_PRINT("IN E_DEMO_VALUE_B case %s\n",__FUNCTION__);
			
		case E_DEMO_VALUE_C:
			MI_PRINT("IN E_DEMO_VALUE_C case %s\n",__FUNCTION__);

		case E_DEMO_VALUE_D:
			MI_PRINT("IN E_DEMO_VALUE_D case %s\n",__FUNCTION__);

		case E_DEMO_VALUE_E:
			MI_PRINT("IN E_DEMO_VALUE_E case %s\n",__FUNCTION__);

		default:
			MI_PRINT("IN DEFAULT case %s \n",__FUNCTION__);
	}


	return 0;

}


MI_BOOL _demo_switch_B(DEMO_VALUE_E param)
{
	switch(param)
	{
		case E_DEMO_VALUE_A:
			MI_PRINT("IN E_DEMO_VALUE_A case %s\n",__FUNCTION__);
			break;
			
		case E_DEMO_VALUE_B:
			MI_PRINT("IN E_DEMO_VALUE_B case %s\n",__FUNCTION__);
			break;
			
		case E_DEMO_VALUE_C:
			MI_PRINT("IN E_DEMO_VALUE_C case %s\n",__FUNCTION__);
			break;
			
		case E_DEMO_VALUE_D:
			MI_PRINT("IN E_DEMO_VALUE_D case %s\n",__FUNCTION__);
			break;
			
		case E_DEMO_VALUE_E:
			MI_PRINT("IN E_DEMO_VALUE_E case %s\n",__FUNCTION__);
			break;

		default:
			MI_PRINT("IN DEFAULT case %s\n",__FUNCTION__);
	}


	return 0;

}


MI_BOOL _demo_switch_C(DEMO_VALUE_E param)
{
	switch(param)
	{
		default:
			MI_PRINT("IN DEFAULT case \n");
			
		case E_DEMO_VALUE_A:
			MI_PRINT("IN E_DEMO_VALUE_A case %s\n",__FUNCTION__);
			break;
			
		case E_DEMO_VALUE_B:
			MI_PRINT("IN E_DEMO_VALUE_B case %s\n",__FUNCTION__);
			break;
			
		case E_DEMO_VALUE_C:
			MI_PRINT("IN E_DEMO_VALUE_C case %s\n",__FUNCTION__);
			break;
			
		case E_DEMO_VALUE_D:
			MI_PRINT("IN E_DEMO_VALUE_D case %s\n",__FUNCTION__);
			break;
			
		case E_DEMO_VALUE_E:
			MI_PRINT("IN E_DEMO_VALUE_E case %s\n",__FUNCTION__);
			break;

	}


	return 0;

}

MI_BOOL _demo_switch_D(DEMO_VALUE_E param)
{
	switch(param)
	{
		case E_DEMO_VALUE_A:
			{
				int i,j;
				i = 10;
				j = 11;
				MI_PRINT("IN E_DEMO_VALUE_A case %s\n",__FUNCTION__);
				MI_PRINT("The value i=%d j=%d \n",i,j);
			}
			break;
			
		case E_DEMO_VALUE_B:
			{
				int i,j;
				i = 10;
				j = 11;
				MI_PRINT("IN E_DEMO_VALUE_B case %s\n",__FUNCTION__);
				MI_PRINT("The value i=%d j=%d \n",i,j);
			}
			break;
			
		case E_DEMO_VALUE_C:
			{
				MI_PRINT("IN E_DEMO_VALUE_C case %s\n",__FUNCTION__);
			}
			break;
			
		case E_DEMO_VALUE_D:
			{
				MI_PRINT("IN E_DEMO_VALUE_D case %s\n",__FUNCTION__);
			}
			break;
			
		case E_DEMO_VALUE_E:
			{
				MI_PRINT("IN E_DEMO_VALUE_E case %s\n",__FUNCTION__);
			}
			break;

		default:
			MI_PRINT("IN DEFAULT case %s\n",__FUNCTION__);
	}


	return 0;

}


int main(int argc,char * argv[])
{
   
   _demo_switch_A(E_DEMO_VALUE_A);
   _demo_switch_A(E_DEMO_VALUE_B);
   MI_PRINT("\n------------------------------------\n");

	_demo_switch_B(E_DEMO_VALUE_A);
	_demo_switch_B(E_DEMO_VALUE_B);
   MI_PRINT("\n------------------------------------\n");

	_demo_switch_C(E_DEMO_VALUE_A);
	_demo_switch_C(E_DEMO_VALUE_B);
	_demo_switch_C(10);
   MI_PRINT("\n------------------------------------\n");

     _demo_switch_D(E_DEMO_VALUE_A);
	 _demo_switch_D(E_DEMO_VALUE_B);


	 
	return 0;
}

