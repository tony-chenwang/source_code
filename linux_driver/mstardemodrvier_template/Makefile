# Rules for making the show task driver.


EXTRA_CFLAGS +=-Wno-error=date-time
EXTRA_CFLAGS +=-Wno-date-time

KDIR = /home/tony.chen/pure_code_k6_tip/k6/misdk/linaro

mstar_fbdev_mi-objs +=	mdrv_hello_complex.o

obj-m += mdrv_hello_complex.o

all:
	make -C $(KDIR)/ SUBDIRS=$(PWD) modules
clean:
	make -C $(KDIR)/ SUBDIRS=$(PWD) clean
