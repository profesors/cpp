CC = g++
INC = -Iinclude

all: src/Persona.o
	$(CC) src/Persona.o src/main.cc $(INC) -o main 

src/Persona.o: src/Persona.cc
	$(CC) -c src/Persona.cc $(INC) -o src/Persona.o
	
clean:
	$(shell find . -name *.o -exec rm {} \;)
	rm main
