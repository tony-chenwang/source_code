 /*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date  2018-01-26
  
  * @brief:
  		  main function API:
          fork :
             这个函数 调用 一次 返回两次 相当于拷贝了
          程序的地址空间，所以可以认为是有两个 main 函数，只是 fork以前的部分 都已经执行
          完毕了。

          pause
          	进程阻塞等待信号的输入
          	
          wait
          	 进程挂起 一直到其任意一个子进程退出 
          	
          getpid  获取当前进程 的 PID
          
          getppid 获取当前父进程的 PID

          
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

// child process is normal exit or abort
#define NORMAL_MODE 1
/*
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
*/

pid_t pid;
int variable = 0;

/****************************************************
  * @functionName : _demo_dumpenv
  * @brief:
           This is the No1.0 method of dumpenv 
  
  * @param
  * @retval  void
****************************************************/
void _demo_dumpenv(char **para_env)
{
    DBG_ERR("dump the localhost env info %s \n",__FUNCTION__);
    while(*para_env)
    {
		DBG_ERR("%s \n",*para_env);
		para_env ++;
    }
}

void _demo_child_process(void)
{
    MI_U16 i = 0;
	MI_PRINT("%s : pid:%d ppid:%d\n",__FUNCTION__,getpid(),getppid());
	while(1)
	{
		MI_PRINT("I am in child process !! variable:%d \n",variable);
		usleep(100000);

		//norla exit
		#if (NORMAL_MODE == 1 )
	    	if(i > 20) break;
		#else
			if(i > 20) abort();  //abnormal exit
		#endif
		
		i++;
		variable++;
	}

}

void _demo_father_process(void)
{
    MI_U16 i = 0;
	
	MI_PRINT("%s pid:%d child pid:%d\n",__FUNCTION__,getpid(),pid);
	while(1)
	{
		MI_PRINT("I am in father process !! variable:%d \n",variable);
		usleep(100000);
		if(i > 10) break;
		i++;
		variable += 3;
	}

#if 0
	int status = 0 ;
	int eRetpid = 0 ;
	MI_PRINT("%s wait for child process exit %d\n",__FUNCTION__,getpid());
    eRetpid = wait(&status);
	MI_PRINT("The exit status is %d Ret PID is %d \n",status,eRetpid);
#endif

}

int main(int argc,char * argv[], char * env[])
{
    MI_PRINT("This is my process demo! %s build time:%s %s\n",__FUNCTION__,__DATE__,__TIME__);
    // dump env No1.0 method
    _demo_dumpenv(env);


    // No2.0 this is the second method of get env 
    MI_PRINT("We get the path env is %s \n",getenv("PATH"));
	MI_PRINT("We get the path env is %s \n",getenv("SHELL"));


    // This is the FILENO of this three file des
    MI_PRINT("The value of stderr is %d \n",STDIN_FILENO);
    MI_PRINT("The value of stdin is %d \n",STDOUT_FILENO);
    MI_PRINT("The value of stdout is %d \n",STDERR_FILENO);

    pid = fork();

	if(pid == 0)
	{
		_demo_child_process();
	}
	else if(pid > 0)
	{
		_demo_father_process();
	}
	else
	{
		MI_PRINT("fork error \n");
	}  

    int status = 0 ;
	int eRetpid = 0 ;
	MI_PRINT("%s wait for child process exit %d\n",__FUNCTION__,getpid());
    eRetpid = wait(&status);
	MI_PRINT("The exit status is %d Ret PID is %d \n",status,eRetpid);

	
    MI_PRINT("%s end of the main fucntion %d\n",__FUNCTION__,getpid());
	//pause();
     return 0;
}
