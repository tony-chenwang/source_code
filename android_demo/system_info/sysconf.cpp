#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>

#define ONE_MB (1024 * 1024)

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


void Get_sys_conf(MI_SYSCONF_s* para_sysconf)
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

int main(int argc,char*argv[])
{
    MI_SYSCONF_s*  AN_SYS_CONF = NULL;
    AN_SYS_CONF = (MI_SYSCONF_s*)malloc(sizeof(MI_SYSCONF_s));
    memset(AN_SYS_CONF,0,sizeof(MI_SYSCONF_s));
   while(1)
   {
        Get_sys_conf(AN_SYS_CONF);
        
        printf("The cpu total is %d\n",AN_SYS_CONF->cpu_max);
        printf("The cpu in use is %d\n",AN_SYS_CONF->cpu_online); 
        printf("The page size is %d\n",AN_SYS_CONF->page_size); 
        printf("The max page is %d\n",AN_SYS_CONF->mempage_max);   
        printf("The available page is %d\n",AN_SYS_CONF->mempage_available);         
        printf("The fd max is %d\n",AN_SYS_CONF->fd_max);         
        printf("The ticks_persecondsis %d\n",AN_SYS_CONF->ticks_perseconds); 
        printf("------------------------------\n");        
        
        usleep(1000*1000);
   }
    
	return 1;
}