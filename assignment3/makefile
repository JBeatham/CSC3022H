CC = g++
FLAGS = -std=c++11

all:
	$(CC) -c -o HuffNode.o HuffNode.cpp  $(FLAGS)
	$(CC) -c -o HuffTree.o HuffTree.cpp  $(FLAGS)
	$(CC) -c -o driver.o driver.cpp  $(FLAGS)	
	$(CC) -o huffencode HuffTree.o driver.o HuffNode.o $(FLAGS)
clean:
	@rm -f *.o
	@rm -f huffencode
