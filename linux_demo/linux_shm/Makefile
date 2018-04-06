OBJECT_CPP := $(wildcard *.c)
target_SEND := demo_shm_send
target_RECV := demo_shm_recv
OBJECT_SEND = demo_shm_send.o
OBJECT_RECV = demo_shm_recv.o

CC := gcc
CFLAGS = -Wall -O0  $(INCLUDE_DIR) -g  -I ../../include


.PHONY :ALL
ALL: $(target_SEND) $(target_RECV)

ALL: 
$(target_SEND):$(OBJECT_SEND) 
	$(CC) $(CFLAGS) -o $@ $(OBJECT_SEND) -lrt
	
$(target_RECV):$(OBJECT_RECV) 
	$(CC) $(CFLAGS) -o $@ $(OBJECT_RECV) -lrt
 
.PHONY :clean
clean:
	rm -f $(target_SEND) $(target_RECV) $(OBJECT_SEND) $(OBJECT_RECV)
