TARGET = cargaDatos
FLAGS = -fmax-errors=1

$(TARGET):	$(TARGET).cc datos.txt load_tool.cc
	@clear
	g++ $< $(FLAGS) -o $@
	@cp $< bak/$<.bak
	@clang-format -i $<
	@echo "-----------------------------"
	./$(TARGET)


