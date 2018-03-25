 /*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Name : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date  2018-01-26
  
  * @brief:
        #include <unistd.h>  
  
		int execl(const char *path, const char *arg, ...);  
		  
		int execlp(const char *file, const char *arg, ...);  
		  
		int execle(const char *path, const char *arg, ..., char *const envp[]);  
		  
		int execv(const char *path, char *const argv[]);  
		  
		int execvp(const char *file, char *const argv[]);  
		  
		int execve(const char *path, char *const argv[], char *const envp[]);  

        ������ exec +  ִ���ļ�����, �����������,������������

        e ����,     ���������������������,   �����������ֲ������Ϊִ��exec�����ڼ�Ļ�������, �Ƚ�����
        l ����,     ����������ֱ�����"," ���, ���1���������������NULL
        v ����,     ����������ֱ�����1����NULL��β���ַ���ָ�������ͷ��ָ��.        
                      ����char * pstr����1���ַ�����ָ��, char * pstr[] ����������, �ֱ�ָ������ַ���.
        p ����,     ִ���ļ����ֿ��Բ���·��, exec��������$PATH����
          
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

#define debug 6   // ע�� #if ���ܴ��� �ַ������͵� ���� ֻ�ܴ������ε�����

int main(int argc,char * argv[], char * env[])
{
    MI_PRINT("This is my processb demo! %s build time:%s %s\n",__FUNCTION__,__DATE__,__TIME__);
    int status;

    pid_t pid;
    pid = fork();

   
    //child process
	if(pid == 0)
	{
		char * execv_str_execv[] = {"echo", "this is execv    child process demo",NULL};  
        char * execv_strp_execvp[] = {"echo", "this is execvp(path)child process demo",NULL};  

         char * execve_str_execve[] = {"env",NULL};  
        char * env[] = {"PATH=/tmp", "USER=lei", "STATUS=testing", NULL};  
        
#if   debug == 1
        if (execv("/bin/echo",execv_str_execv) <0 )  // ���� ���ַ�������Ϊ ���� ���һ������Ϊ NULL 
#elif  debug == 2
		if (execvp("echo",execv_strp_execvp) <0 )     // ���Բ���ʽ��ָ��·��
#elif  debug == 3
		if (execve("/usr/bin/env",execve_str_execve,env) < 0)
#elif  debug == 4
		if (execve("/usr/bin/env",execve_str_execve,env) < 0)
#elif  debug == 5
		if (execl("/bin/echo","echo","executed by execl" ,NULL) <0 )
#elif  debug == 6
		if (execlp("echo","echo","executed by execlp" ,NULL) <0 )
#endif
        {  
        	perror("error on exec");  
        	exit(errno);
        }
	}
    //father process
	else if(pid > 0)
	{	
		wait(&status);
        MI_PRINT( " child process return %d\n", status);
	
	}
	else
	{
		MI_PRINT("fork error \n");
	}  

     return 0;
}
