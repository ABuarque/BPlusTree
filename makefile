CC = g++ 
CXXFLAGS=-g -Wall -std=c++0x -I. -W -Wall 
LIBS = -lm -std=c++0x
DEPS = $(wildcard *.h)
SRC = $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

app: $(OBJ)
	g++ -o app $(SRC) -I. $(LIBS) 
	