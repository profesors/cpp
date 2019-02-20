CC = g++
INC = -Iinclude
FLAGS = -std=c++17
TARGET = perceptron

$(TARGET): main.cc
	$(CC) main.cc $(FLAGS) $(INC) -o $(TARGET)

clean:
	$(shell find . -name *.o -exec rm {} \;)
	@rm $(TARGET)

.PHONY: clean
