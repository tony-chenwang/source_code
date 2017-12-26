#
#
# makefile 的基本形式


# linux kernel 中使用的 make file debug 方法
# MAKE C=1/2/3

ifeq ("$(origin C)", "command line")
  KBUILD_CHECKSRC = $(C)
endif
ifndef KBUILD_CHECKSRC      
  KBUILD_CHECKSRC = 0
endif

ifeq ("$(origin D)", "command line")
  DEBUG = $(D)
endif
ifndef KBUILD_CHECKSRC
  DEBUG = 0
endif



# 包含其他的 makefile 注意前面的 -的 可以防止报错
# -include 啊 a.mk  b.mk c.mk
-include a.mk b.mk

#strip 的函数的用法 用于去除 字符串的 空格
OBJECT := $(strip $(wildcard *.cpp))


# 连接符后面不能有空格
OBJ := file1.o file2.o file3.o \
file4.o file5.o

# 变量可以组合起来使用
subdir = $(currentdir)/include

currentdir_t := $(currentdir)_t

ifdef DEBUG
# 变量类似于字符串的操作 可以任意添加字符
$(warning currentdir_t is $(currentdir_t))
#OBJ 自己定义的 变量
$(warning OBJ is $(OBJ))
$(warning currentdir is $(currentdir))
#用于传递 makefile  类似于 make
$(warning MAKE is $(MAKE))  #the GNU MAKEFILE variable
$(warning subdir is $(subdir)) # get the subdir value
#origin 函数用于判断 OBJECT 的来源
$(warning origin func is $(origin OBJECT)) # get the subdir value
$(warning origin func is $(origin PATH)) # get the subdir value

#用于打印出 make 的参数 比如 make -s make -n
$(warning MAKEFLAGS func is $(MAKEFLAGS)) # get the subdir value
endif

# 多行变量 
define  MSTAR_LOGO
@echo "# __  __     _             ";
@echo "#|  \/  |___| |_ __ _ _ __ ";
@echo "#| |\/| / __| __/ _\` | '__|";
@echo "#| |  | \__ \ || (_| | |   ";
@echo "#|_|  |_|___/\__\__,_|_|   ";
@echo "                           ";
endef

.PHONY : ALL
ALL:
	 @echo "we now in ALL command"
	cd $(subdir)&&$(MAKE)

.PHONY : clean
clean:
	@pwd
	@cd ~;pwd   #注意变量的生效域
	@pwd
	$(MSTAR_LOGO)  # we use multi line var here
	@echo "See the environment variable $(PATH)"
	@echo "We now in clean command"
