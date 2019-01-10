CC = g++
FLAGS = -std=c++11

all:
	$(CC) -c -o image.o image.cpp  $(FLAGS)
	$(CC) -c -o driver.o driver.cpp  $(FLAGS)	
	$(CC) -o imageops driver.o image.o  $(FLAGS)
clean:
	@rm -f *.o
	@rm -f imageops
