/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Name: 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date  2018-01-14
  * @brief
        makefile  -lpthread 必须放在语句的最后面 否则无法找到函数 搞了好久
        main 函数不能退出 否则线程退出

        int pthread_create(pthread_t *tidp,const pthread_attr_t *attr, \
(void*)(*start_rtn)(void*),void *arg);

        tidp 线程ID handle
        attr  线程属性 默认为 NULL 属性 
        (void*)(*start_rtn)(void*) 线程的函数入口
        void *arg 传递给线程的参数


        int pthread_join(pthread_t thread, void **retval);
        以阻塞的方式等待thread指定的线程结束。当函数返回时，被等待线程的资源被收回。
        如果进程已经结束，那么该函数会立即返回。并且thread指定的线程必须是joinable的


        void  pthread_exit（void  *retval）
        线程主动终止自己 可以传入线程想要返回的打印信息

         
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
