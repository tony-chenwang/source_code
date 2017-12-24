OBJECT_CPP := $(wildcard *.cpp)
target := $(patsubst %.cpp,% ,$(OBJECT_CPP))
OBJECT = $(OBJECT_CPP:.cpp=.o) 
#DEBUG := true
CC := g++

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
	$(CC) -o  $@ $(OBJECT)
    

.PHONY :clean

clean:
	rm -f $(target) $(OBJECT)
