/*******************************************************************************
  * Copyright(C),2017,Mstar semi.co.,Ltd
  * @file Name Block.cpp
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date    2017-12-24 
  * @brief 
  * @History
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>

#define ysten_fd    "/dev/block/platform/mstar_mci.0/by-name/ysteninfo"

int main(int argc,char*argv[])
{
	int fd_blk = 0;
	int i = 0;
	int ret = 0;
	unsigned char data[200] = {0};
	
	if( ( fd_blk = open(ysten_fd,O_RDWR) ) == -1)
    {
		printf("Fail to open ysten_fd, please check\n");
		return -1;
	}
    
	while(1)
	{
        // set tht pointer to front
		lseek(fd_blk,0,SEEK_SET);
		
		if( (ret = read(fd_blk,data,sizeof(unsigned char)*200)) == -1)
		{
			printf("Fail to read data from fd_blk\n");	
		}
		
		printf("The read data is :\n");
		for(i=0;i<200;i++)
		{
			printf("%2.2x",data[i]);
			
			if( i%50 == 0 && i!= 0 )
				printf("\n");
				
		}
		
		printf("\n");
		usleep(3000000);	
	}
	
	return 1;
}