BIN = demo
CC = g++

all: $(BIN)

demo: main.o gradient-descent.o
	$(CC) -o $(BIN) $^

%.o: %.cpp %.h
	$(CC) -c $<

clean:
	rm *.o
