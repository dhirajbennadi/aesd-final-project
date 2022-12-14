#SRCS = $(wildcard *.c)
SRCS2 = subscribeApp.c
SRCS1 = publishApp.c
OBJS = $(SRCS:.c=.o)

ifeq ($(CC),)
	CC = $(CROSS_COMPILE)gcc
endif

ifeq ($(CFLAGS),)
	CFLAGS = -g -Wall -Werror
endif 

ifeq ($(LDFLAGS),)
	LDFLAGS = -lpaho-mqtt3cs
endif 

TARGET_BUILD?=0
ifeq ($(TARGET_BUILD),1)
	CUSTOMFLAGS = -DTARGET_BUILD
endif

TARGET1 = publish
TARGET2 = subscribe 
all: $(TARGET1) $(TARGET2)
default: $(TARGET1) $(TARGET2)

$(TARGET1): $(SRCS1) 
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDES) $(LDFLAGS) $(CUSTOMFLAGS)

$(TARGET2): $(SRCS2) 
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDES) $(LDFLAGS) $(CUSTOMFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET1) $(TARGET2)
	rm -f valgrind*
