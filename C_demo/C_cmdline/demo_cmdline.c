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


MI_U8 read_buffer[100] = {0};

#define MAX_ARGC	6






static void cmd_exit(int argc, char **argv)
{
	MI_PRINT("\n\rthis is in %s ",__FUNCTION__);
}



static void cmd_help(int argc, char **argv)
{
	MI_PRINT("\n\rthis is in %s ",__FUNCTION__);
}

typedef struct _cmd_entry {
	char *command;
	void (*function)(int, char **);
} cmd_entry;

static const cmd_entry cmd_table[] = {
	{"exit", cmd_exit},
	{"help", cmd_help}
};

static int parse_cmd(char *buf, char **argv)
{
	int argc = 0;

	memset(argv, 0, sizeof(argv)*MAX_ARGC);
	while((argc < MAX_ARGC) && (*buf != '\0')) 
    {
		argv[argc] = buf;
		argc ++;
		buf ++;

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
    MI_PRINT("This is my first demo! %s builddate:%s %s\n",__FUNCTION__,__DATE__,__TIME__);

    int margc;
    int i = 0;
    char *margv[MAX_ARGC];
   
    while(1)
    {
      printf("\r\n\n# ");
      fgets(read_buffer,100,stdin);

      memset(margv,0x00,sizeof(char*));
      if((margc = parse_cmd(read_buffer, margv)) > 0)
      {
      #if 0
        MI_PRINT("the margc is %d \n",margc);
        MI_PRINT("the margv[0] is %d \n",margv[0]);
        MI_PRINT("the margv[1] is %s \n",margv[1]);
        MI_PRINT("the margv[2] is %s \n",margv[2]);
     #endif
     
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
            printf("unknown command '%d' \n", margv[0]);
        
      }

	   memset(read_buffer,0x00,sizeof(read_buffer));

    } 
    
    return 0;
}
