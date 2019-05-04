TARGET = test1

$(TARGET):	$(TARGET).cc datos.txt load_tool.cc
	@clear
	g++ $< -o $@
	@cp $< bak/$<.bak
	@clang-format -i $<
	@echo "-----------------------------"
	./$(TARGET)


