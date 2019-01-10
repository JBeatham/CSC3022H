CC = g++
FLAGS = -std=c++11

all:
	$(CC) -c -o databases.o databases.cpp  $(FLAGS)
	$(CC) -c -o driver.o driver.cpp  $(FLAGS)	
	$(CC) -o driver driver.o databases.o  $(FLAGS)
run:
	./driver
clean:
	@rm -f *.o
	@rm -f driver
