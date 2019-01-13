/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date     
  * @brief
  		getchar
  		putchar
  		puts
  			
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

#define demo_module 2

int main(int argc,char * argv[])
{
    MI_PRINT("This is my basic in out demo! %s builddate:%s %s\n",__FUNCTION__,__DATE__,__TIME__);
    char ch = 0;
    char ch_t = 1;

#if (demo_module == 1)
    do
    {
	ch = getchar();  // only get \n the function will return;
	//ch = getch();
	//putchar('A'); 
	putchar(ch);
    }while( ch != '\n');

    putchar('A');
    putchar('\n');  // putchar print a char one time
    puts("this is my demo"); // puuts will add \n automatically
	
#elif (demo_module == 2)

	MI_PRINT("char demo  %c %c \n",'A',48); // both char & int is compatible
	MI_PRINT("int demo %d,%ld \n",2018,20182018ul);
	
	// TODO:  only print previous numb	
	MI_PRINT("int demo %-3d,%3ld \n",2018,20182018ul);

	MI_PRINT("\t speical char demo \n");
	MI_PRINT("float demo %f  %3.3f  %3.9f\n",1/3.0,1/3.0,1/3.0); // .3 means only save 3 ponit number

        MI_PRINT("Hex : %x %#x,DEC: %d,eight : %o %#o\n",100,100,100,100,100); 

	MI_PRINT("pointer demo %p %p\n",&ch,&ch_t);

	MI_PRINT("float demo demo %e %E \n",1/3.0,1/3.0); // git config --global core.whitespace cr-at-eol
#endif

     return 0;
}
