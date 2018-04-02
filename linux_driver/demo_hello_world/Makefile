platfrom = ubuntu 

ifeq "$(platform)" "k7u"
CC      = arm-linux-gnueabihf-gcc
CXX     = arm-linux-gnueabihf-g++
LINK    = arm-linux-gnueabihf-gcc
else
CC  = gcc
CXX = g++
LINK = gcc
endif



CFLAGS  = -g -Wall -O2
TARGET  = demo_hello
SRCS    = $(wildcard *.cpp)
SRCS    += $(wildcard *.c)
FBDEV_INC :=
FBDEV_INC += ../../mstarFbdev_MI/uapi
FBDEV_INC += ../../MI_3_0/DDI_MI/cus_mstar/mi/include/32bit

CFLAGS += $(addprefix -I, $(FBDEV_INC))


CXX_OBJS    = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
C_OBJS  = $(patsubst %.c, %.o, $(wildcard *.c))

all:$(TARGET)

$(TARGET):$(CXX_OBJS) $(C_OBJS)
	$(LINK) $(CFLAGS) -o $@ $^
%.o:%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<
.PHONY:clean
clean:
	rm -rf *.o $(TARGET) $(CXX_OBJS) $(C_OBJS)
