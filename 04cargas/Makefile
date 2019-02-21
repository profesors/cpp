CC = g++
INC = -Iinclude
FLAGS = -std=c++17
TARGET = cargas
SRCDIR = src
BINDIR = bin
OBJ = $(subst $(SRCDIR)/,,$(patsubst %.cc, %.o, $(wildcard $(SRCDIR)/*.cc)))

$(TARGET): src/main.cc bin/CampoElectrico.o
	$(CC) src/main.cc bin/CampoElectrico.o $(FLAGS) $(INC) -o $(TARGET)

# Compila todos los .cc
bin/%.o	:	src/%.cc
	$(CC) $< $(FLAGS) $(INC) -c -o $@

clean:
	$(shell find . -name *.o -exec rm {} \;)
	@rm $(TARGET)

.PHONY: clean
