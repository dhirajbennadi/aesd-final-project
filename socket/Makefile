#generic makefile to build for various compilers
ifeq ($(CC),)
        CC = $(CROSS_COMPILE)gcc
endif
ifeq ($(CFLAGS),)
        CFLAGS = -g
endif
ifeq ($(LDFLAGS),)
        LDFLAGS = -pthread -lrt
endif

#all: client server
#default: all

all: socket
default: all

socket: client.c
	$(CC) $(CFLAGS) -o socket client.c $(LDFLAGS)

client: client.c
	$(CC) $(CFLAGS) -o client client.c $(LDFLAGS)

server: server.c
	$(CC) $(CFLAGS) -o server server.c $(LDFLAGS)


.PHONY: all

clean:
	rm client server socket
	$(RM) $(TARGET)