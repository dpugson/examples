CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -std=c++11 -Wall -Wextra -Werror

SRCS=$(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRCS))
TARGET=example.tsk

all: build 

build: $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS) 

clean:
	$(RM) $(OBJS) $(TARGET)
