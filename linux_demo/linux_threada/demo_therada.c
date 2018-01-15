/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Name: 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date  2018-01-14
  * @brief
        makefile  -lpthread ���������������� �����޷��ҵ����� ���˺þ�
        main ���������˳� �����߳��˳�

        int pthread_create(pthread_t *tidp,const pthread_attr_t *attr, \
(void*)(*start_rtn)(void*),void *arg);

        tidp �߳�ID handle
        attr  �߳����� Ĭ��Ϊ NULL ���� 
        (void*)(*start_rtn)(void*) �̵߳ĺ������
        void *arg ���ݸ��̵߳Ĳ���


        int pthread_join(pthread_t thread, void **retval);
        �������ķ�ʽ�ȴ�threadָ�����߳̽���������������ʱ�����ȴ��̵߳���Դ���ջء�
        ��������Ѿ���������ô�ú������������ء�����threadָ�����̱߳�����joinable��


        void  pthread_exit��void  *retval��
        �߳�������ֹ�Լ� ���Դ����߳���Ҫ���صĴ�ӡ��Ϣ

         
  * @History 2018-01-15
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

// use posix therad must use this 
#include <pthread.h>


#define loop_length 10

pthread_t thread_handle[2];


void *thread1()
{
   MI_U8 loop_time = 0;
   while(1)
   {
    MI_PRINT("%s is running \n",__FUNCTION__);
	sleep(2);

	if(loop_time > 10)
	{
		break;
	}
	
	 MI_PRINT("%s the loop count is %d \n",__FUNCTION__,loop_time);
	 loop_time++;
   }
   MI_PRINT("%s will exit!!\n",__FUNCTION__);

}


void *thread2()
{
    MI_U8 loop_time = 0;
	while(1)
	{
	 MI_PRINT("%s is running \n",__FUNCTION__);
	 sleep(1);
	if(loop_time > 30)
	{
		break;
	}
     MI_PRINT("%s the loop count is %d \n",__FUNCTION__,loop_time);
	 loop_time++;
	}
	pthread_exit(NULL);
	//pthread_exit("thread2 is over please check ");
 }


int main(int argc,char * argv[])
{
    MI_PRINT(" This is my posix thread demo! \n");

    MI_U8 eRet = -1;
    memset(thread_handle,0x00,sizeof(pthread_t));

    eRet = 0;
    eRet = pthread_create(&thread_handle[0], NULL, thread1, NULL);
    if(eRet)
 		goto FAIL;


    eRet = pthread_create(&thread_handle[1], NULL, thread2, NULL);
    if(eRet)
 		goto FAIL;



     pthread_join(thread_handle[0],NULL);

	 // we use pthread join to get some extra value
     void *Ptr= NULL;
	 pthread_join(thread_handle[1], &Ptr);
	 MI_PRINT("The return message is %s \n", (char *)Ptr);

	 return 1;
	 
FAIL:
    perror("Thread Creat fail!! please check \n");

    return 0;
}
