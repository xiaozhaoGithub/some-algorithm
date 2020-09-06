src=$(wildcard *.cpp)
targets=$(patsubst %.cpp,%,$(src))

all:$(targets)

CC=g++
CFLAGS=-Wall -g
$(targets):%:%.cpp
	$(CC) $< -o $@ $(CFLAGS)

.PHONY:all clean

clean:
	rm -rf $(targets)
