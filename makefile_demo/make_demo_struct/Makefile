#
# makefile 的基本形式

if_changed := 1

# linux kernel 中使用的 make file debug 方法
# MAKE C=1/2/3

DEBUG := 0
ifeq ("$(origin D)", "command line")
  DEBUG := $(D)
endif


PHONY += ALL
PHONY += dist
PHONY += tar
PHONY += install
PHONY += uninstall
PHONY += clean
PHONY += vmlinux
PHONY += packet

.PHONY = $(PHONY)

## make file 将书写的第一个目标作为默认目标 所以 默认目标为 make tar
.PHONY : tar
tar:
	 @echo "we now in tar command"
     
## 注意 执行的顺序是  vmlinux  packet  command
.PHONY : ALL
ALL:  vmlinux  packet
	@echo "we now in ALL command"   #不太明白具体的用法

.PHONY : dist
dist:
	 @echo "we now in dist command"

.PHONY : install
install:
	 @echo "we now in install command"

.PHONY : uninstall
uninstall:
	 @echo "we now in uninstall command"

.PHONY : clean
clean:
	@echo "We now in clean command"
    
.PHONY : vmlinux
vmlinux:
	@cd scripts;./vmlinux.sh
	@echo "We now in vmlinux command"
    
.PHONY : packet
packet:
	@echo "We now in packet command"
    
