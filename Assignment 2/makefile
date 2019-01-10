CC = g++
FLAGS = -std=c++11

all:
	$(CC) -c -o VolImage.o VolImage.cpp  $(FLAGS)
	$(CC) -c -o driver.o driver.cpp  $(FLAGS)	
	$(CC) -o volimage driver.o VolImage.o  $(FLAGS)
run:
	./driver
clean:
	@rm -f *.o
	@rm -f volimage
