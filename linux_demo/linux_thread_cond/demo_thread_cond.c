/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Name: 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date  2018-01-15
  * @brief

     pthread_cond_init pthread_cond_init(pthread_cond_t *cv, \
const pthread_condattr_t *cattr);
     attr 默认值为0
     一般不接返回值

      pthread_cond_wait(pthread_cond_t *cv, pthread_mutex_t *mutex)
      函数将解锁mutex参数指向的互斥锁，并使当前线程阻塞在cv参数指向的条件变量上。

      int pthread_cond_signal(pthread_cond_t *cv);

      int pthread_cond_timedwait(pthread_cond_t *cv, pthread_mutex_t *mp, const structtimespec * abstime);

      int pthread_cond_broadcast(pthread_cond_t *cv);
      会解锁所有的线程

      int pthread_cond_destroy(pthread_cond_t *cv);
         
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
static pthread_mutex_t mutex;
static pthread_cond_t  cond = PTHREAD_COND_INITIALIZER; 


void *thread1()
{
   while(1)
   {
  
#ifdef  MI_DBG_Mutex
     pthread_mutex_lock(&mutex);  
#endif
     pthread_cond_wait(&cond, &mutex);

     MI_PRINT("%s is running A\n",__FUNCTION__);
	 sleep(2);
	 
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
   MI_U8 loop = 0;
	while(1)
	{

	 // must be care of lock & try lock function
#ifdef  MI_DBG_Mutex
	 pthread_mutex_lock(&mutex);  
     //ret = pthread_mutex_trylock(&mutex);
     //perror("thread2 ----------\n");
#endif
     
	 MI_PRINT("%s is running B\n",__FUNCTION__);
     sleep(1);

	 if( loop > 10 )
	 {
	    MI_PRINT("now we send thread signal \n");
  		pthread_cond_signal(&cond);
	 }

	 loop++;
	 
#ifdef  MI_DBG_Mutex
	  pthread_mutex_unlock(&mutex);
#endif
      sleep(1);
	 
	}
	pthread_exit("thread2 exit");
	//pthread_exit("thread2 is over please check ");
 }

MI_U8 _demo_init(void)
{
   // 默认的属性为 NULL
	pthread_mutex_init(&mutex,NULL);  
	pthread_cond_init(&cond, NULL);
	return 1;

}


int main(int argc,char * argv[])
{
    MI_PRINT(" This is my posix thread demo! \n");    
    MI_U8 eRet = -1;
	void *Ptr= NULL;
	_demo_init();
    memset(thread_handle,0x00,sizeof(pthread_t));

    eRet = pthread_create(&thread_handle[0], NULL, thread1, NULL);
    eRet = pthread_create(&thread_handle[1], NULL, thread2, NULL);
    if(eRet)
 		goto FAIL;

	 // we use pthread join to get some extra value
	 pthread_join(thread_handle[1], &Ptr);
	 MI_PRINT("The return message is %s \n", (char *)Ptr);
     pthread_join(thread_handle[0],NULL);
	 pthread_mutex_destroy(&mutex);  
	 pthread_cond_destroy(&cond);

	 return 1;
	 
FAIL:
    perror("Thread Creat fail!! please check \n");

    return 0;
}
