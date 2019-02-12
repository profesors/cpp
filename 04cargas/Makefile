CC = g++
INC = -Iinclude
TARGET = cargas
SRCDIR = src
BINDIR = bin
OBJ = $(subst $(SRCDIR)/,,$(patsubst %.cc, %.o, $(wildcard $(SRCDIR)/*.cc)))

$(TARGET): src/main.cc bin/CampoElectrico.o	
	$(CC) src/main.cc bin/CampoElectrico.o $(INC) -o $(TARGET)

# Compila todos los .cc
bin/%.o	:	src/%.cc
	$(CC) $< $(INC) -c -o $@

clean:
	$(shell find . -name *.o -exec rm {} \;)
	@rm main

.PHONY: clean
