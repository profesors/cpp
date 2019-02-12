CC = g++
INC = -Iinclude

main: main.cc CampoElectrico.o
	$(CC) main.cc CampoElectrico.o $(INC) -o main

CampoElectrico.o:	CampoElectrico.cc
	$(CC) CampoElectrico.cc -c $(INC) -o CampoElectrico.o

clean:
	$(shell find . -name *.o -exec rm {} \;)
	@rm main

.PHONY: clean
