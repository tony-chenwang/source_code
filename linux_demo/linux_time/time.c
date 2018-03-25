/*******************************************************************************
  * Copyright(C),2017,Mstar semi.co.,Ltd
  * @file Name
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date 2017-12-18
  * @brief
  * @History
		获取时间:
		time  返回值为 到1970 年之间的秒数
     
		time(&timep); 传入为 time_t 结构
		locatime(&timep) 返回为 struct tm 结构
		asctime() 将 struct tm 结构 转换为字符串
		ctime    直接将 time_t 结构转换为字符串

        gettimeofday   struct  timeval  struct  timezone 结构

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
 
        // 使用这个函数可以将 struct tm *tm_p  转换为 字符串的格式
        printf("curent time string %s \n",asctime(tm_p));

        // local time 的 逆运算，将时间格式转换为 秒为单位
        printf("curent time in seconds is %x \n",mktime(tm_p));

        //直接将 time_t 结构转化为字符串
        printf("curent time in string in ctime is %s \n",ctime(&timep));
  
        
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
