OBJECT_CPP := $(wildcard *.c)
target := $(patsubst %.c,% ,$(OBJECT_CPP))
OBJECT = $(OBJECT_CPP:.c=.o) 
#DEBUG := true

CC := gcc
#CFLAGS = -Wall -O0  $(INCLUDE_DIR) -g -D MI_ENABLE_DBG DBG_LEVEL = MI_DBG_ALL
CFLAGS =  -Wall -O0  -I./include  -lpthread


.PHONY :ALL
ALL: $(target)

ifdef DEBUG
$(warning "The value of target is $(target)")
$(warning "The value of OBJECT is $(OBJECT)")
$(warning "The value of OBJECT_CPP is $(OBJECT_CPP)")
endif


ALL: 
$(target):$(OBJECT) 
ifdef DEBUG
	@echo  "In the command the target is $@ "
	@echo  "In the command the preq is $< "
endif
	$(CC)   -o $@ $(OBJECT) $(CFLAGS)
 
 
.PHONY :clean
clean:
	rm -f $(target) $(OBJECT)
