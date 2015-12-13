CC=g++
CFLAGS=-std=c++11
LDFLAGS=
EXEC=analog
SRC=main.cpp DataManager.cpp LogOtherInfos.cpp GraphGenerator.cpp
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

analog: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

DataManager.cpp: DataManager.h

LogOtherInfos.cpp: LogOtherInfos.h

GraphGenerator.cpp: GraphGenerator.h

.PHONY:clean

clean:
	rm -rf $(OBJ) $(EXEC)
