/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date   2018-01-18  
  * @brief  test access function
  * @History

     #include<unistd.h>  
	 int access(const char* pathname, int mode)

     mode:
       F_OK file exsit
       W_OK file can be write
       R_OK file can be read
       X_OK file can be excute 
        

  
*******************************************************************************/
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// MI must define before mi_common.h
// We can also use makefile -D para 
#define  MI_ENABLE_DBG  true
#define  DBG_LEVEL  MI_DBG_ALL

#include "mi_common.h"
#include "mi_internal.h"

void help_access(char *progname)
{
  fprintf(stderr, "-----------------------------------------------------------------------\n");
  fprintf(stderr, "Usage: %s file path | demo test the file R & W & X & EXSIT \n" \
                  " \n", progname);
  exit(1);
}


int main(int argc,char * argv[])
{
    MI_PRINT("This is my access demo! \n");
	
    MI_U8* pGetFilename = NULL;

    if(argc < 2)
    {
       help_access(argv[0]);
    }

    pGetFilename = strdup((MI_U8 *)argv[1]);
    MI_PRINT("Now the file path is %s \n",pGetFilename);

    MI_PRINT("euid = %d,egid = %d,uid = %d, gid = %d\n",geteuid(), getegid(), getuid(), getgid());
    if( access((const char *)pGetFilename,R_OK) == 0 )
    {
	MI_PRINT("%s is Read OK \n",pGetFilename);
    }

    if( access((const char *)pGetFilename,W_OK) == 0 )
    {
	 MI_PRINT("%s is write OK \n",pGetFilename);
    }

    if( access((const char *)pGetFilename,X_OK) == 0 )
    {
         MI_PRINT("%s is excute OK \n",pGetFilename);
    }
   
   if( access((const char *)pGetFilename,F_OK) == 0 )
   {
	MI_PRINT("%s is exsit OK \n",pGetFilename);
   }
   else
   {
	perror("The file donot exsit \n");
   }

	 
   pause();
   return 0;
}
