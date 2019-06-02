TARGET = functor
FLAGS = -fmax-errors=1 -pthread

$(TARGET):	$(TARGET).cc 
	@clear
	g++ $< $(FLAGS) -o $@
	@clang-format -i $<
	@echo "-----------------------------"
	./$(TARGET)


