TARGET = ncurses
FLAGS = -fmax-errors=1 -lncurses -pthread

$(TARGET):	$(TARGET).cc 
	@clear
	g++ $< $(FLAGS) -o $@
	@clang-format -i $<
	./$(TARGET)


