/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date   2018 -2-10 
  * @brief
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

// must include this file 
#include <stdarg.h>

#define debug 1




#define CHECK_RET(X)  \
    {   \
        if( X < 0 )  \
        {   \
            DBG_ERR("INVALID RETURN VALUE \n");  \
            fprintf(stderr," error msg is :%s\n",strerror(errno));\
            exit(-1);\
        }   \
    }   \


// use  change para to implment this function 
// use  vprintf to  implment  char* format,... 
void _demo_va_func(char* format,...)
{
     char * parg;
	 va_list arg_ptr; 
	 va_start(arg_ptr, format); 
#if (debug == 1)
     printf("content %s \n",format);
#endif
     vprintf(format,arg_ptr);
	 va_end(arg_ptr);
}


void _demo_va_test(char* format,...)
{
	 va_list arg_ptr; 
	 va_start(arg_ptr, format); 
     vprintf(format,arg_ptr);
	 va_end(arg_ptr);
}



// 基于这个函数 可以实现将 可变参数打印在 文件之中 的功能
void _demo_va_file(FILE *stream,char* format,...)
{
	 va_list arg_ptr; 
	 va_start(arg_ptr, format); 
     vfprintf(stream,format,arg_ptr);
	 va_end(arg_ptr);
}

int main(int argc,char * argv[])
{
    FILE* fp = NULL;
    MI_PRINT("This is my Va args demo! %s builddate:%s %s\n",__FUNCTION__,__DATE__,__TIME__);

   
    _demo_va_func("This is sat I am working %s %s \n",__DATE__,__TIME__);
   
     fp  = fopen("demo.log","w+");
     _demo_va_file(fp ,"build time %s %s \n",__DATE__,__TIME__);
	 _demo_va_file(fp ,"hello world \n");

	
     return 0;
}
