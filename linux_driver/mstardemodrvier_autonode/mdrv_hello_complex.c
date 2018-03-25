/*******************************************************************************
  * Copyright(C),2017,Mstar semi.co.,Ltd
  * @file Name
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date   2018 01 03
            2018 03 22
            2018 03 25
            
  * @brief   linux driver hello world
  * @History
*******************************************************************************/
#include <linux/mm.h>
#include <linux/miscdevice.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <linux/mman.h>
#include <linux/random.h>
#include <linux/init.h>
#include <linux/raw.h>
#include <linux/tty.h>
#include <linux/capability.h>
#include <linux/ptrace.h>
#include <linux/device.h>
#include <linux/highmem.h>
#include <linux/crash_dump.h>
#include <linux/backing-dev.h>
#include <linux/bootmem.h>
#include <linux/splice.h>
#include <linux/pfn.h>
#include <linux/export.h>
#include <linux/io.h>
#include <linux/aio.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include <asm/uaccess.h>

#include <linux/device.h>
#define Module_Major  0  
#define Module_DeviceName "helloworld"

#define PRINTKDEBUG  1

static char banner[] __initdata = KERN_INFO "Hello world drv for demo, (c) 2017 MStar co.Ltd\n";

static dev_t    demo_devt; 
static struct cdev*  demo_cdev; 
static struct class* demo_class;


#define CHRDEV_NAME      "Helloworlddriver"                //出现在  /proc/devices 中 
#define CLASS_NAME       "class_hello"                     //表示在/sys/class目录下创建的设备类别目录  
#define DEVICE_NAME      "hello"                           //创建的设备节点名

static int HelloWorld_drv_open(struct inode *inode, struct file *file)
{
    printk("%s:IN driver open case\n", __FUNCTION__);	

    //current is current task macro  get name pid & state -1 unrunnable, 0 runnable, >0 stopped
    printk("%s:The current process is %s pid is %d current state is %d \n", __FUNCTION__, \
                               current->comm,current->pid,current->state);

    //get major number & minor number
    printk("The major number is %d \n",imajor(inode));
    printk("The minor number is %d \n",iminor(inode));
    return 0;
}

static ssize_t HelloWorld_drv_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
    printk("%s:IN driver read case\n", __FUNCTION__);	

    return 0;
}


static ssize_t HelloWorld_drv_write(struct file *file, const char __user *buf, size_t size, loff_t *ppos)
{
	 printk("%s:IN driver write case\n", __FUNCTION__);	

	 return 0;
}


/*  The core struct in Linux driver including open close wrire*/

static struct file_operations Mstar_demo_driver = {
	.owner  	= THIS_MODULE,    
	.open   	= HelloWorld_drv_open,     
	.read	= HelloWorld_drv_read,	   
	.write	= HelloWorld_drv_write,	   
};


static int __init demo_helloworld_init(void)
    {
        int ret = -1;
        printk(banner);

       // demo_devt 是传出参数 也可以使用 MKDEV 来创建 
       // CHRDEV_NAME 出现在 /proc/devices 和 sysfs中
       // /*1、申请设备号*/  
       ret = alloc_chrdev_region(&demo_devt,0,1,CHRDEV_NAME);  
       if(ret) 
       {  
             printk("alloc char driver error!\n");  
             return ret;  
       }  

        /*2、注册字符设备*/  
        demo_cdev = cdev_alloc();  
        cdev_init(demo_cdev,&Mstar_demo_driver);  
        demo_cdev->owner = THIS_MODULE;  
        
         ret = cdev_add(demo_cdev,demo_devt,1);  
         if(ret) 
         {  
              printk("cdev create error!\n");  
              unregister_chrdev_region(demo_devt,1);  
              return ret;  
          } 

          /*3、创建设备节点*/  
          demo_class = class_create(THIS_MODULE,CLASS_NAME);  
          device_create(demo_class,NULL,demo_devt,NULL,DEVICE_NAME);  

    
        printk(Module_DeviceName"module has been initialized!! \n");


        return 0;
        
    }


static void __exit
    demo_helloworld_exit(void)
    {
        device_destroy(demo_class,demo_devt);  
	    class_destroy(demo_class);  
	      
	    /*2、取消字符设备注册*/  
	    cdev_del(demo_cdev);  
	      
	    /*3、释放设备号*/  
	    unregister_chrdev_region(demo_devt,1);  
        printk(Module_DeviceName"module has been exited \n");
    }

module_init(demo_helloworld_init);
module_exit(demo_helloworld_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mstar");
MODULE_DESCRIPTION("A module used for show task of each thread!");

