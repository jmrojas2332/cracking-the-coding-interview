CC = g++
SRCS = ./*.cpp
INC = ../algorithms/
OPTS = -std=c++17 -Wall -Werror

EXEC = program

all: clean compile

compile:
		$(CC) $(SRCS) $(OPTS) -I$(INC) -o $(EXEC)
clean:
		rm -f $(EXEC)
