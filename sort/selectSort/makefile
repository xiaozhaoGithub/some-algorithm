src=$(wildcard *.cpp)
targets=$(patsubst %.cpp,%,$(src))

all:$(targets)

CC=g++
CFLAGS=-g -Wall
$(targets):%:%.cpp
	$(CC) $< -o $@ $(CFLAGS) 

.PHONY:clean all
clean:
	-rm -rf $(targets) 
