CC=g++
CFLAGS=
LDFLAGS=
EXEC=main
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

main: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)
	
BoolContainer.o: BoolContainer.cpp BoolContainer.h errorCode.h
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf *.o
