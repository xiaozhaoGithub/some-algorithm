src=$(wildcard ./*.cpp)                                                                                                             
obj=$(patsubst ./%.cpp,./%.o ,$(src))
 
CC=g++
CFLAGS=-Wall

all:$(obj) 

$obj:%.o 
	$(CC) $< -o $@ $(CFLAGS)


.PHONY:clean all
clean:
	rm -rf  $(obj)

