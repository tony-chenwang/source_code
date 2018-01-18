/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.1
  * @date     
  * @brief
  * @History add 
		主要测试了 adjtimex 这个接口  mode 普通用户只能设置为 0 就是获取信息
	//	struct timex {
	//		int modes;           /* mode selector */
	//		long offset;         /* time offset (usec) */
	//		long freq;           /* frequency offset (scaled ppm) */
	//		long maxerror;       /* maximum error (usec) */
	//		long esterror;       /* estimated error (usec) */
	//		int status;          /* clock command/status */
	//		long constant;       /* pll time constant */
	//		long precision;      /* clock precision (usec) (read only) */
	//		long tolerance;      /* clock frequency tolerance (ppm)
	//		                        (read only) */
	//		struct timeval time; /* current time (read only) */
	//		long tick;           /* usecs between clock ticks */
	//		};
//  	
//*******************************************************************************/
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


#define ONE_MB (1024 * 1024)


#ifdef MI_OS_LINUX
#include <sys/utsname.h>
#include <sys/time.h>
#include <sys/timex.h>
#endif



typedef struct 
{
   int cpu_max;
   int cpu_online;
   int page_size;
   int mempage_max;
   int mempage_available;
   int fd_max;
   int ticks_perseconds;
}MI_SYSCONF_s;


void get_sys_conf(MI_SYSCONF_s* para_sysconf)
{
    memset(para_sysconf,0,sizeof(MI_SYSCONF_s));
    
    para_sysconf->cpu_max = sysconf(_SC_NPROCESSORS_CONF);
    para_sysconf->cpu_online = sysconf(_SC_NPROCESSORS_ONLN);
    para_sysconf->page_size = sysconf(_SC_PAGESIZE);
    para_sysconf->mempage_max = sysconf(_SC_PHYS_PAGES);
    para_sysconf->mempage_available = sysconf(_SC_AVPHYS_PAGES);
    para_sysconf->fd_max = sysconf(_SC_OPEN_MAX);
    para_sysconf->ticks_perseconds = sysconf(_SC_CLK_TCK);
    
}



int get_current_freq(void)
{
	/* OS dependent routine to get the current value of clock frequency.
	 */
#ifdef MI_OS_LINUX
	struct timex txc;
	txc.modes=0;
	txc.freq=0;
	if (adjtimex(&txc) < 0) {
		perror("\tadjtimex"); exit(1);
	}
	return txc.freq;
#else
	return 0;
#endif
}

int set_freq(int new_freq)
{
	/* OS dependent routine to set a new value of clock frequency.
	 */
#ifdef MI_OS_LINUX
	struct timex txc;
	txc.modes = ADJ_FREQUENCY;
	txc.freq = new_freq;
	if (adjtimex(&txc) < 0) {
		perror("adjtimex"); exit(1);
	}
	return txc.freq;
#else
	return 0;
#endif
}


int main(int argc,char*argv[])
{
    MI_SYSCONF_s*  stSysOSConf = NULL;
    stSysOSConf = (MI_SYSCONF_s*)malloc(sizeof(MI_SYSCONF_s));
    memset(stSysOSConf,0,sizeof(MI_SYSCONF_s));
	
   while(1)
   {
        system("clear");
        get_sys_conf(stSysOSConf);
        
        printf(" \tThe cpu total is %d\n",stSysOSConf->cpu_max);
        printf("\tThe cpu in use is %d\n",stSysOSConf->cpu_online); 
        printf("\tThe page size is %d\n",stSysOSConf->page_size); 
        printf("\tThe max page is %d\n",stSysOSConf->mempage_max);   
        printf("\tThe available page is %d\n",stSysOSConf->mempage_available);         
        printf("\tThe fd max is %d\n",stSysOSConf->fd_max);         
        printf("\tThe ticks_persecondsis %d\n",stSysOSConf->ticks_perseconds); 
		DBG_WRN("\tThe current cpu freq is %d \n",get_current_freq());
		set_freq(1000000);
        printf("\t------------------------------\n");        
        
        usleep(1000*1000);
   }

	free(stSysOSConf);
	return 1;
}
