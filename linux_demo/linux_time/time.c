/*******************************************************************************
  * Copyright(C),2017,Mstar semi.co.,Ltd
  * @file Name
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date 2017-12-18
  * @brief
  * @History
*******************************************************************************/
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/utsname.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <time.h>
#include <sys/time.h>
#include <sys/timeb.h>

// MI must define before mi_common.h 
#define  MI_ENABLE_DBG  true
#define  DBG_LEVEL  MI_DBG_ALL

#include "mi_common.h"

struct  timeval    tv = {0};
struct  timezone   tz = {0};

struct timeb  tp = {0};  

struct tm *tm_p = NULL;
char *wday[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};  


int main(int argc,char * argv[])
{
    
    MI_PRINT("value of argc = %d\n",argc);
    MI_U8 Ret = -1 ;

  
    while(1)
    {
        MI_PRINT("*****************************\n");
        // return the seconds from 1970 - now
        unsigned int seconds = time((time_t*)NULL); 
		if ( seconds < 0 ) goto FAIL;
		MI_PRINT("time function second value is 0x%x \n",seconds);
        MI_PRINT("the ctime real time is %s \n",ctime(&seconds));   


        time_t timep;
		time(&timep);
        tm_p = localtime(&timep);
        printf("Year: %d Month:%d,Day:%d \n", (1900+tm_p->tm_year),(1+tm_p->tm_mon), tm_p->tm_mday);   
        printf("%s %d:%d:%d \n", wday[tm_p->tm_wday],tm_p->tm_hour, tm_p->tm_min, tm_p->tm_sec);



		Ret = gettimeofday(&tv,&tz);
		if ( Ret < 0 ) goto FAIL;

		// return the seconds from 1970 ~ now
		MI_PRINT("tv_sec is %d\n",tv.tv_sec);
		// return the useconds  except tv.tv_sec
        MI_PRINT("tv_usec is %d\n",tv.tv_usec);

		
		// print the  value = time - greenwich 
        MI_PRINT("tz.tz_minuteswest is %d\n",tz.tz_minuteswest);
		//  print the time zone
        MI_PRINT("tz.tz_dsttime is %d\n",tz.tz_dsttime);


        // the result is same as time
		ftime(&tp);  
		MI_PRINT("ftime get time %d\n", tp.time);  


        usleep(1000*1000);
    }

FAIL:
	perror("operation Failed!\n");
	return 0;
   
}
