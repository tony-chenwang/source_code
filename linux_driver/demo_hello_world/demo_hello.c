/*******************************************************************************
  * Copyright(C),2017,Mstar semi.co.,Ltd
  * @file Name
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
             V1.0.1
  * @date  2017/12/28   initialize
           2017/01/15   optimize
  * @brief
           Demo test my own driver
           
  * @History
               
*******************************************************************************/
// we usually use this head file 
#include <sys/types.h> 
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

//C standard head file 
#include <stdio.h>
#include <string.h>

#define dev_node "/dev/hello"


#define read_buffer_length 100
#define write_buffer_length 100

char read_buffer[read_buffer_length] = {0};
char write_buffer[write_buffer_length] = {0};  
    
int main(int argc,char * argv[])
{
    int fd = -1;
    int ret_size = -1;
 
    fd = open(dev_node,O_RDWR,0x700);
    if (fd < 0 ) 
        goto Fail;
    
    printf("Success The crate fd is %d\n",fd);
 
    read(fd,read_buffer,read_buffer_length);
    
    
    memset(write_buffer,0xFF,sizeof(char)*write_buffer_length);
    ret_size = write(fd,write_buffer,sizeof(char)*write_buffer_length);
    printf("The write ret size is %d\n",ret_size);
    
    while(1);
    return 1;
    
Fail:
	// create File fd fail please check!!: Too many open files
    perror("create File fd fail please check!!");
    return 0;
}
