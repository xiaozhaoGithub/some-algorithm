src = $(wildcard *.cpp)
targets=$(patsubst %.cpp,%,$(src))

all:$(targets)

CC=g++
CFLAGS=-Wall -g
$(targets):%:%.cpp
	$(CC) $< -o $@ $(CFLAGS)
.POHNY:clean all
clean:
	rm -rf $(targets)
