/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Name: 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date  2018-01-15
  * @brief

     pthread_mutex_init(pthread_mutex_t * mutex,const pthread_mutexattr_t *attr);
     mutex 传入一个 pthread_mutex_t 结构
     attr 默认值为0
     一般不接返回值

     pthread_mutex_lock(pthread_mutex_t *mutex);加锁 如果获取不到则阻塞等待
     pthread_mutex_unlock(pthread_mutex_t *mutex);释放锁
 
     pthread_mutex_trylock 
     调用后立即返回。因为它调用WaitForSingleObject函数时传递的第二个参数是0，表示不等待，立即返回。
     调用lock或者tryLock后，都需要调用unlock来解锁
         
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

#define MI_DBG_Mutex true

pthread_t thread_handle[2];

//mutex for thread
pthread_mutex_t mutex;



void *thread1()
{
   while(1)
   {

#ifdef  MI_DBG_Mutex
     pthread_mutex_lock(&mutex);  
#endif
     MI_PRINT("%s is running A\n",__FUNCTION__);
     sleep(10);
	 MI_PRINT("%s is running B\n",__FUNCTION__);

#ifdef  MI_DBG_Mutex
	 pthread_mutex_unlock(&mutex);
#endif

	 sleep(1);
   }
   
   pthread_exit("thread1 exit");
}


void *thread2()
{
   MI_U8 ret = 0;
	while(1)
	{

	 // must be care of lock & try lock function
#ifdef  MI_DBG_Mutex
	 pthread_mutex_lock(&mutex);  
     //ret = pthread_mutex_trylock(&mutex);
     //perror("thread2 ----------\n");
#endif
     MI_PRINT("%s is running A\n",__FUNCTION__);
     usleep(2000);
	 MI_PRINT("%s is running B\n",__FUNCTION__);
#ifdef  MI_DBG_Mutex
	  pthread_mutex_unlock(&mutex);
#endif

	 sleep(1);
	}
	pthread_exit("thread2 exit");
	//pthread_exit("thread2 is over please check ");
 }

MI_U8 demo_init_mutex(void)
{
   // 默认的属性为 NULL
   pthread_mutex_init(&mutex,NULL);  
   return 1;

}


int main(int argc,char * argv[])
{
    MI_PRINT(" This is my posix thread demo! \n");

    demo_init_mutex();
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

	 pthread_mutex_destroy(&mutex);  

	 return 1;
	 
FAIL:
    perror("Thread Creat fail!! please check \n");

    return 0;
}
