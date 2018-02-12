/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Name : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date 2018-02-12
  
  * @brief: test string conver function
            atof  
            atoi
            atol
            strtod
            strtol

            tolower
            toupper
  
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


#define CHECK_RET(X)  \
    {   \
        if( X < 0 )  \
        {   \
            DBG_ERR("INVALID RETURN VALUE \n");  \
            fprintf(stderr," error msg is :%s\n",strerror(errno));\
            exit(-1);\
        }   \
    }   \


int main(int argc,char * argv[])
{
    MI_PRINT("This is my stringconver  demo! %s builddate:%s %s\n",__FUNCTION__,__DATE__,__TIME__);

    const char * sfval = "3.141592653";
	MI_PRINT("The atof result is %f \n",atof(sfval));  // ascii to float 

    const char * sfval2 = "3.14e5";
    MI_PRINT("The atof result is %f \n",atof(sfval2)); // ascii to float 

	 const char * sfval3 = "3.14e-5";
	 MI_PRINT("The atof result is %f \n",atof(sfval3));



	 const char * sival = "256";
     MI_PRINT("The atoi result is %d \n",atoi(sival)); // ascii to int 

	 const char * sival2 = "1234567";
     MI_PRINT("The atoi result is %d \n",atoi(sival2));

	 const char * slval = "12345678910";
     MI_PRINT("The atol result is %ld \n",atol(slval)); // ascii to long 


     const char *s1 = "1234.234";
	 MI_PRINT("The strtod result is %f \n",strtod(s1,NULL)); // ascii to long 


     char *endptr;
	 //const char *s2 = "3456.789";
     //const char *s2 = "3456.789tony";
     const char *s2 = "-1234.234";
	 MI_PRINT("The strtod result is %f \n",strtod(s2,&endptr)); // ascii to long 
	 MI_PRINT("The endptr is %s \n",endptr);  // return error value


  
     const char *s3 = "0x65535mmmmmmm";
	 char *stop;
     MI_PRINT("The result is %x \n",strtol(s3,&stop,16));  // return error value
     MI_PRINT("The stop is %s \n",stop);  // return error value
 
  
     const char *s4 = "0777xxxxx";
     MI_PRINT("The result is %o \n",strtol(s4,&stop,8));  // return error value
     MI_PRINT("The stop is %s \n",stop);  // return error value  


	 const char *s5 = "888888888888888888vvvvvvvvvv";
	 MI_PRINT("The result is %ld \n",strtoul(s5,&stop,10));  // return error value
     MI_PRINT("The stop is %s \n",stop);  // return error value	

 
     return 0;
}
