/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date   2018-01-13
  * @brief

    struct dirent
	{
	   long d_ino;  inode number 索引节点号 
	   off_t d_off;  offset to this dirent 在目录文件中的偏移 
	   unsigned short d_reclen;  length of this d_name 文件名长 
	   unsigned char d_type;  the type of d_name 文件类型 
	   char d_name [NAME_MAX+1];  file name (null-terminated) 文件名，最长255字符 
	}

     readdir return struct dirent* ptr

  
  * @History
*******************************************************************************/
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// use readir must use including this 
#include <dirent.h>


// MI must define before mi_common.h 
#define  MI_ENABLE_DBG  true
#define  DBG_LEVEL  MI_DBG_ALL

#include "mi_common.h"
#include "mi_internal.h"

int ReadFileTree(MI_S8* main_dir_path)
{
	 DIR *dir = NULL;
	 struct dirent *ptr;

#ifdef DIRRECUR
     char sub_dir_path[600];
#endif	 
     dir=opendir(main_dir_path);
     if( dir == NULL )
		goto FAIL;


     while ((ptr=readdir(dir)) != NULL)
	 {
		if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)
		{
			MI_PRINT("Now in upper or down dir \n");
			continue;
		}
		else if(ptr->d_type == 8) // common file
		{
			MI_PRINT("the commonfile is %s \n",ptr->d_name);
		}
        else if(ptr->d_type == 10) // link file
		{
			MI_PRINT("the linkfile name is :%s/%s\n",main_dir_path,ptr->d_name);
		}
		else if(ptr->d_type == 4)    ///dir
		{
		     MI_PRINT("the dir name is %s \n",ptr->d_name);
#ifdef DIRRECUR

			 memset(sub_dir_path,0x00,sizeof(sub_dir_path));
			 strcpy(sub_dir_path,main_dir_path);
			 strcat(sub_dir_path,"/");
			 strcat(sub_dir_path,ptr->d_name);
			 ReadFileTree(sub_dir_path);
#endif	
		}
	 }

     closedir(dir);

     return 1;

FAIL:
	perror("Open dir error...");
	return -1;
}


int main(int argc,char * argv[])
{
    MI_PRINT(" This is my readdir demo! \n");
	ReadFileTree("/home/tony.chen/open_source/source_code/linux_demo/linux_readdir");
    return 0;
}
