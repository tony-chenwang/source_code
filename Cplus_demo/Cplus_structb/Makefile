OBJECT_CPP := $(wildcard *.cpp)
target := $(patsubst %.cpp,% ,$(OBJECT_CPP))
OBJECT = $(OBJECT_CPP:.c=.o) 
#DEBUG := true

CC := g++
#CFLAGS = -Wall -O0  $(INCLUDE_DIR) -g -D MI_ENABLE_DBG DBG_LEVEL = MI_DBG_ALL
CFLAGS = -Wall -O0  $(INCLUDE_DIR) -g  -I ../../include


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
	$(CC) $(CFLAGS) -o $@ $(OBJECT)
 
 
.PHONY :clean
clean:
	rm -f $(target)
