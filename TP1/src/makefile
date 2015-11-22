CC=g++
CFLAGS=
LDFLAGS=
EXEC=main
SRC=BoolContainer.cpp main.cpp
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
	
BoolContainer.o: BoolContainer.cpp BoolContainer.h errorCode.h
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY:clean

clean:
	rm -rf $(OBJ) $(EXEC)
