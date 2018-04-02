# Rules for making the show task driver.

platform = ubuntu

EXTRA_CFLAGS += -I drivers/mstar2/hal/k7u/cpu/arm/include/mstar/
#EXTRA_CFLAGS += -I drivers/mstar2/drv/ir_mirc/ir_dynamic_config/

#EXTRA_CFLAGS += -I /home/johnny.wang/git_workspace/mi_osd_3.0/MI_3_0/DDI_MI/cus_mstar/mi/include/32bit/

EXTRA_CFLAGS += -I /home/tony.chen/Graphic/mi/misdk/mi/build/mi_include

ifeq "$(platform)" "ubuntu"
   KDIR = /lib/modules/$(shell uname -r)/build
else
   KDIR = /home/tony.chen/Graphic/mi/misdk/linaro
endif


mstar_fbdev_mi-objs +=	mdrv_hello_complex.o

obj-m += mdrv_hello_complex.o

all:
	make -C $(KDIR)/ SUBDIRS=$(PWD) modules
clean:
	make -C $(KDIR)/ SUBDIRS=$(PWD) clean
