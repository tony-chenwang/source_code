/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Name : demo_macrob.c
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date    2018-01-20
  * @brief
        gcc compile macro __LINE__ __FILE__ __FUNCTION__ __DATE__ __TIME__
        #ifdef #else #endif #ifndef #else #endif   //ע�� Ҫѡ�е� �� ֱ�� #define a �Ϳ����� 

        #if #else #endif
        #if #elif #elif #endif  // �����ж��ص�ѡ��

		#error  �ڱ����ʱ�򱨴�

		#progma message()  �����ʱ���ӡ��Ϣ�����Բ鿴�ļ��Ƿ񱻱��뵽��
  	
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


#define demo_a false
//#define demo_b

#define demo_c 2


int main(int argc,char * argv[])
{
    MI_PRINT("This is my macrob demo! \n");

    MI_PRINT("Base Info function:%s/ date:%s/ time:%s /file :%s/line:%d\n",__FUNCTION__,__DATE__,__TIME__,__FILE__,__LINE__);


    #ifdef demo_a
    	MI_PRINT("now we in demo_a A\n");
	#else
		MI_PRINT("now we in demo_a B\n");
	#endif

	#ifndef demo_b
		MI_PRINT("now we in demo_b A\n");
	#else
		MI_PRINT("now we in demo_b B\n");
	#endif


    #if (demo_a == true)
	//#if (demo_a)
		MI_PRINT("demoa == true \n");
    #else
		MI_PRINT("demoa != true \n");
	#endif

    //����ʹ�ó������ʽ  ע�� ����ڱ����ʱ�� ѡ�������ļ� ���� �����������д��
    #if (demo_c == 1)
		MI_PRINT("demo_C = 1 \n");
    #elif (demo_c == 2)
		MI_PRINT("demo_C = 2 \n");
    #elif (demo_c == 3)
	    MI_PRINT("demo_C = 3\n");
	    #error this is my error
    #elif (demo_c == 4)
	    MI_PRINT("demo_C = 4\n");
		#error this is my error
	#endif


    // �ڱ����ʱ�� ���Զ���ӡ������ַ�
    #pragma message("now we run into this \n")



    pause();
    return 0;
}
