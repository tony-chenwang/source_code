/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version  V1.0.0
  * @date     2018-02-26
  * @brief    linux signal demo 
  * @History
             2018-02-06 first edit
     1) SIGHUP	 2) SIGINT	 3) SIGQUIT	 4) SIGILL	 5) SIGTRAP
	 6) SIGABRT	 7) SIGBUS	 8) SIGFPE	 9) SIGKILL	10) SIGUSR1
	11) SIGSEGV	12) SIGUSR2	13) SIGPIPE	14) SIGALRM	15) SIGTERM
	16) SIGSTKFLT	17) SIGCHLD	18) SIGCONT	19) SIGSTOP	20) SIGTSTP
	21) SIGTTIN	22) SIGTTOU	23) SIGURG	24) SIGXCPU	25) SIGXFSZ
	26) SIGVTALRM	27) SIGPROF	28) SIGWINCH	29) SIGIO	30) SIGPWR
	31) SIGSYS	34) SIGRTMIN	35) SIGRTMIN+1	36) SIGRTMIN+2	37) SIGRTMIN+3
	38) SIGRTMIN+4	39) SIGRTMIN+5	40) SIGRTMIN+6	41) SIGRTMIN+7	42) SIGRTMIN+8
	43) SIGRTMIN+9	44) SIGRTMIN+10	45) SIGRTMIN+11	46) SIGRTMIN+12	47) SIGRTMIN+13
	48) SIGRTMIN+14	49) SIGRTMIN+15	50) SIGRTMAX-14	51) SIGRTMAX-13	52) SIGRTMAX-12
	53) SIGRTMAX-11	54) SIGRTMAX-10	55) SIGRTMAX-9	56) SIGRTMAX-8	57) SIGRTMAX-7
	58) SIGRTMAX-6	59) SIGRTMAX-5	60) SIGRTMAX-4	61) SIGRTMAX-3	62) SIGRTMAX-2
	63) SIGRTMAX-1	64) SIGRTMAX

     main signal:
     
    14 SIGALRM  alarm func over time use this signal 
     2  SIGINT  ctrl+C
     9  SIGKILL  cannot pass & catch 
     19 SIGSTOP  cannot pass & catch
     13 SIGPIPE  write pipe & process terminate 
     15 SIGTERM kill comand default signal
     16 SIGCHLD when process stop send this to father process 
     6  SIGABRT  abort func send 
     11 SIGSEGV  fail memory use 
     12 SIGUSR2  customized signal use for IPC 
     10 SIGUSR2  customized signal use for IPC 


    send signal : kill rasie   linux command : kill 
    catch signal:  alarm pause
    
    dealwith signal: signal sigaction



   linux commad kill

   kill -s signal [pid]   send signal to pid 

   kill -l   list all signal

   kill -l 11  coner 11 signal to string

   kill -s9 -1  kill all process 
 == kill -9 -1   kill init thread 

	
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

#include "signal.h"

#define CHECK_RET(X)  \
    {   \
        if( X < 0 )  \
        {   \
            DBG_ERR("INVALID RETURN VALUE \n");  \
            fprintf(stderr," error msg is :%s\n",strerror(errno));\
            exit(-1);\
        }   \
    }   \

typedef struct sigaction sact_s;


void signal_handle(int sig)
{
	DBG_ERR("PID %d: get the signal %d \n",getpid(),sig);
}

int main(int argc,char * argv[])
{
    MI_PRINT("This is my first demo! %s builddate:%s %s\n",__FUNCTION__,__DATE__,__TIME__);

    sact_s stsigact;
    stsigact.sa_handler = signal_handle;
	sigemptyset(&stsigact.sa_mask); 
    stsigact.sa_flags = SA_RESETHAND;

	sigaction(SIGINT,&stsigact,NULL);

    pause();

    return 0;
}
