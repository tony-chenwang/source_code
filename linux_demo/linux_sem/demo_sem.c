/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date  2018-04-01
  
  * @brief this is my demo for sem
     P  获取临界资源 -1
     V  释放临界资源 +1

     PV 之间的区域称为临界区 就是同一时间只允许单一进程访问
     
  * @History
*******************************************************************************/
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/ipc.h>
#include <sys/sem.h>


// MI must define before mi_common.h 
#define  MI_ENABLE_DBG  true
#define  DBG_LEVEL  MI_DBG_ALL

#include "mi_common.h"
#include "mi_internal.h"

int sem_id = 1;

int DEMO_SEM_Init()
{

    key_t key = 0x1234;  
    int ret = semget(key, 1, 0666 | IPC_CREAT);  
    if(ret < 0)  
    {  
        perror("sem get  error: \n");  
        return -1;  
    }

    sem_id = ret;

    MI_PRINT("The semid is %d \n",sem_id);

	if (semctl(sem_id, 0, SETVAL, 1) == -1)
	{
	    perror("Initialize semaphore");
	    return -1;
	}

    
    return 0;
}

void DEMO_SEM_Create()
{
   sem_id = semget((key_t)1234,1,0666|IPC_CREAT);
}


int DEMO_SEM_P()
{
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = -1;
    sem_b.sem_flg = SEM_UNDO;
    if(semop(sem_id,&sem_b,1)==-1)
    {
        fprintf(stderr,"semaphore_p failed\n");
        return 0;
    }
    return 1;
}



int DEMO_SEM_V()
{
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = 1;
    sem_b.sem_flg = SEM_UNDO;
    if(semop(sem_id,&sem_b,1)==-1)
    {
        fprintf(stderr,"semaphore_v failed\n");
        return 0;
    }
    return 1;
}


void DEMO_SEM_Delete()
{
    if(semctl(sem_id,0,IPC_RMID,0)==-1)
    {
        fprintf(stderr,"Failed to delete semaphore\n");
     }
}


int main(int argc,char * argv[])
{
    MI_PRINT("This is my first demo! %s builddate:%s %s\n",__FUNCTION__,__DATE__,__TIME__);

    DEMO_SEM_Init();

    pid_t pid;

    pid = fork();

    if(pid == 0)
    {
         MI_PRINT("this is the child process !! \n");
         DEMO_SEM_P();
         MI_PRINT("[child]NOW I get the sem !!! \n");
         sleep(5);
         DEMO_SEM_V();
    }
    else if(pid > 0)
    {
        MI_PRINT("this is the father process !! \n");
        //sleep(1);
        DEMO_SEM_P();
        MI_PRINT("[father]NOW I get the sem !!! \n");
        sleep(10);
        DEMO_SEM_V();
        pause();
    }
    else
    {
		perror("fork process error please check !! \n");
    }
   
    DEMO_SEM_Delete();
    return 0;
}
