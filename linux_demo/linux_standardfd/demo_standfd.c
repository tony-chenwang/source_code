/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date     
  * @brief
  		fopen    --      int fopen(const char* filename,const char *mode)
  		
  		fclose   --      int fclose(FILE * stream)
  		
  		ftell    --      ftell(FILE* stream) 获取文件位置的指针


  		feof     --      feof(FILE*stream) 到了文件末尾 返回 非 0 的值  否则 返回 0 
  		
  		rewind   --      void rewind(FILE *stream)  函数rewind 的作用是
  		                  文件指针移动到文件的开头位置 
  		
  		remove   --      remove(const char *filename)
  		
  		rename   --      rename(const char*oldname,const char *newname)
  		
  		fflush           int fflush(FILE*stream);
  		
  		fgets            char* fgets(char *str,int num , FILE*stream)
  		
  		fputs            int fputs(const char *str,FILE *stream);
  		
  		fread            int fread(void*buffer,int size,int count,FILE *stream)
  		
  		fwrite           int fwrite(void *buffer,int size,int count,FILE *stream)

  		fseek            int fseek(FILE*stream,long int offset,int origin)

  		
	
  * @History
*******************************************************************************/
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//MI must define before mi_common.h 
#define  MI_ENABLE_DBG  true
#define  DBG_LEVEL  MI_DBG_ALL

#include "mi_common.h"
#include "mi_internal.h"


#define CHECK_RET(X)  \
    {   \
        if( X == NULL )  \
        {   \
            DBG_ERR("INVALID RETURN VALUE \n");  \
            fprintf(stderr," error msg is :%s\n",strerror(errno));\
            exit(-1);\
        }   \
    }   \


#define buffer_size 100
MI_U8 read_buffer[buffer_size] = {0};	

MI_U8 write_buffer[buffer_size] = {0};

int main(int argc,char * argv[])
{
    MI_PRINT("This is my standard C demo! %s build date:%s %s\n",__FUNCTION__,__DATE__,__TIME__);
    
    MI_PRINT("argv[1] is %s \n",argv[1]); // argv[0] is programme name


    FILE *fp = fopen(argv[1],"rw+");
    CHECK_RET(fp);

    MI_S32 count = 0;
	while( !feof(fp))
	{
		count = fread(read_buffer,sizeof(MI_U8),buffer_size,fp);


        // ftell(FILE* stream) 获取文件位置的指针
		DBG_ERR("the read buffer length is %d content is %s \n",count,read_buffer);
		MI_PRINT("The Current file location is %d \n",ftell(fp));
	}

    rewind(fp);  
    MI_PRINT("The Current file location is %d \n",ftell(fp));

    strcpy(write_buffer,"this is tonychen add  hahaha !!\n");
	
    count = fwrite(write_buffer,sizeof(MI_U8),strlen(write_buffer),fp);

    MI_PRINT("The write count is %d \n",count);

    
    fflush(fp);

    //MI_PRINT("The Current file location is %d \n",ftell(fp));

	rewind(fp);  
    fgets(read_buffer,20,fp);
	MI_PRINT("The readbuffer is %s \n",read_buffer);


    fgets(read_buffer,100,fp);
    MI_PRINT("The readbuffer is %s \n",read_buffer);

    MI_S8 ret = -1;
	
    if( (ret = remove("my.txt")) == 0)
	{
		MI_PRINT("remove file success !! \n");
	}
	else
	{
		MI_PRINT("remove file fail \n");
	}

    ret = rename("my1.txt","my2.txt");
	MI_PRINT("The ret value of my.txt is %d \n",ret);

    rewind(fp);
	fgets(read_buffer,100,stdin);
    MI_PRINT("The readbuffer is %s \n",read_buffer);



    fseek(fp,0,SEEK_SET);
	fputs(read_buffer,fp);
	
    fseek(fp,0,SEEK_SET);
    MI_PRINT("The Current file location is %d \n",ftell(fp));

	fseek(fp,0,SEEK_END);
    MI_PRINT("The Current file location is %d \n",ftell(fp));

	fseek(fp,-20,SEEK_END);
    MI_PRINT("The Current file location is %d \n",ftell(fp));

	rewind(fp);
	fseek(fp,100,SEEK_CUR);
    MI_PRINT("The Current file location is %d \n",ftell(fp));
	
	fclose(fp);

    return 0;
}
