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


#define Module_Major  0  
#define Module_DeviceName "helloworld"

#define PRINTKDEBUG  1

static char banner[] __initdata = KERN_INFO "Hello world drv for demo, (c) 2017 MStar co.Ltd\n";

static int HelloWorld_drv_open(struct inode *inode, struct file *file)
{
	printk("%s:IN driver open case\n", __FUNCTION__);	

	return 0;
}

static ssize_t HelloWorld_drv_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
	printk("%s:IN driver read case\n", __FUNCTION__);	

	return 0;
}

#if 0
static ssize_t HelloWorld_drv_write(struct file *file, const char __user *buf, size_t size, loff_t *ppos)
{
	printk("%s:IN driver write case\n", __FUNCTION__);	

#if (PRINTKDEBUG == 1)  
    printk(KERN_DEBUG"This is debug info \n");
    printk(KERN_INFO"this is info info \n");
    printk(KERN_NOTICE"this is notice info \n");
    printk(KERN_WARNING"this is warning info \n");
    printk(KERN_ERR"this is err info \n");
    printk(KERN_ALERT"this is alert info \n");
    printk(KERN_EMERG"this is emerg info \n");
#endif
    printk(KERN_DEBUG"build date %s %s \n",__DATE__,__TIME__);
    printk(KERN_DEBUG"Function & line %s %d \n",__FUNCTION__,__LINE__);
    printk(KERN_DEBUG"kernel debug info will not interrupt \n");

    printk("This is Test case for default log level!! \n");
 

     return -ENOTTY;

	//return 100;
}
#endif

static ssize_t HelloWorld_drv_write(struct file *file, const char __user *buf, size_t size, loff_t *ppos)
{
	printk("%s:IN driver write case\n", __FUNCTION__);	

    // We use this function for return error number
    //return -ENOTTY;
     return -ENOMEM;
}

/*  The core struct in Linux driver including open close wrire*/

static struct file_operations Mstar_demo_driver = {
	.owner  	= THIS_MODULE,    
	.open   	= HelloWorld_drv_open,     
	.read	= HelloWorld_drv_read,	   
	.write	= HelloWorld_drv_write,	   
};


static int __init 
    demo_helloworld_init(void)
    {
        int ret = -1;
        printk(banner);
    
        ret = register_chrdev(Module_Major, Module_DeviceName, &Mstar_demo_driver);
        if ( ret < 0 )
        {
            printk(Module_DeviceName "Fail can't register major number \n");
            return -1;
        }
    
        printk(Module_DeviceName"module has been initialized!! \n");
        return 0;
        
    }


static void __exit
    demo_helloworld_exit(void)
    {
        printk(Module_DeviceName"module has been exited \n");
    }

module_init(demo_helloworld_init);
module_exit(demo_helloworld_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mstar");
MODULE_DESCRIPTION("A module used for show task of each thread!");

