/*******************************************************************************
  * Copyright(C),2018 Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date     2018-01-12
  * @brief
      C programm:
      	 when define a value think of its value in case of overflow

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

#define SECONDS_A_YEAR 3600*24*365*3600

#define SECONDSOFYEAR  3600*24*365*3600UL

int main(int argc,char * argv[])
{
    MI_U64 RetValue = SECONDSOFYEAR;
    MI_PRINT("The value of macro SECONDSOFYEAR is %ld \n",RetValue);
	MI_PRINT("The size of  macro SECONDSOFYEAR is %ld \n",sizeof(SECONDSOFYEAR));
	
    
    RetValue = SECONDS_A_YEAR;
    MI_PRINT("The valueof macro SECONDS_A_YEAR is %ld\n",RetValue);
	MI_PRINT("The size  macro SECONDS_A_YEAR is %ld\n",sizeof(SECONDS_A_YEAR));

    
    return 0;
}
