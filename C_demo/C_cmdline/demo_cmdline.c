/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date     
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


#define CHECK_RET(X)  \
    {   \
        if( X < 0 )  \
        {   \
            DBG_ERR("INVALID RETURN VALUE \n");  \
            fprintf(stderr," error msg is :%s\n",strerror(errno));\
            exit(-1);\
        }   \
    }   \


char read_buffer[100] = {0};

// max arg number 6
#define MAX_ARGC	6


static void cmd_exit(int argc, char **argv)
{
	MI_PRINT("\n\rthis is in %s ",__FUNCTION__);
    return;
}


static void cmd_help(int argc, char **argv)
{
	MI_PRINT("\n\rthis is in %s ",__FUNCTION__);
}


static void cmd_demo(int argc, char **argv)
{
	MI_PRINT("\n\rthis is in %s ",__FUNCTION__);
    MI_PRINT("Hello world!!! \r\n");
}



typedef struct _cmd_entry {
	char *command;
	void (*function)(int, char **);
} cmd_entry;

static const cmd_entry cmd_table[] = {
	{"exit", cmd_exit},
	{"help", cmd_help},
	{"demo", cmd_demo}
};

static int parse_cmd(char *buf, char **argv)
{
	int argc = 0;
	memset(argv, 0, sizeof(argv)*MAX_ARGC);
    
	while((argc < MAX_ARGC) && (*buf != '\0')&&(*buf != '\n')) 
    {
		argv[argc] = buf;
		argc ++;
		//buf ++;

		while((*buf != ' ') && (*buf != '\0'))
			buf ++;

		while(*buf == ' ') 
        {
			*buf = '\0';
			 buf ++;
		}
    }

	  return argc;
}



int main(int argc,char * argv[])
{
    MI_PRINT("This is cmdline first demo! %s builddate:%s %s\n",__FUNCTION__,__DATE__,__TIME__);

    int margc = 0;
    int i = 0;
    char *margv[MAX_ARGC];
   
    while(1)
    {
    
      printf("\n# ");
      memset(read_buffer,0x00,sizeof(read_buffer));
      
      fgets(read_buffer,100,stdin);

      memset(margv,0x00,sizeof(char*)*MAX_ARGC);
      if((margc = parse_cmd(read_buffer, margv)) > 0)
      {
		int found = 0;

		for(i = 0; i < sizeof(cmd_table) / sizeof(cmd_table[0]); i++) 
        {
		   if(strncmp((const char *)margv[0], (const char *)(cmd_table[i].command),strlen(cmd_table[i].command)) == 0) 
           {
		        cmd_table[i].function(margc, margv);
		        found = 1;
		        break;
		   }
		}

        if(!found)
            printf("unknown command '%s' \n", margv[0]);
        
      }
    } 
    
    return 0;
}
