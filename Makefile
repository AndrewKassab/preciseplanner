# Directory List
TEST=test
SRC=src
BUILD=build
OBJ=$(BUILD)/obj

HEADERS		= $(SRC)/Show.hpp $(SRC)/Planner.hpp $(SRC)/Schedule.hpp
OBJS		= $(OBJ)/$(SRC)/Show.o $(OBJ)/$(SRC)/Planner.o $(OBJ)/$(SRC)/Schedule.o
SRCS 		= $(SRC)/Show.cpp $(SRC)/Planner.cpp $(SRC)/Schedule.cpp
EXE 		= preciseplanner

# our c++ compiler
CC=g++

# MMD: automatically resolve included files
# g: include debugging symbols
# Wall: enable all warnings
# std: language standard to compile for 
CXXFLAGS=-MMD -g -Wall -std=c++11

# default target, compiles executable, depends on object files
$(EXE): $(OBJS)
	@echo "Linking all object modules..."
	$(CC) -o $(EXE) $(OBJS)  
	@echo ""
	@echo "Done, Generated executable: $(EXE)"

# compiles object files from their corresponding source files
$(OBJ)/$(SRC)/%.o:$(SRC)/%.cpp
	@echo "Compiling each C++ source file separately ..."
	$(CC) -c -g $<
	mv *.o $(OBJ)/$(SRC)
	@echo ""

# object files depend on header files being up to date
$(OBJS): $(HEADERS)

# run program
run:
	./$(BUILD)/$(EXE)

# clean directory
clean:
	@echo "cleaning"
	@rm -rf $(BUILD)
	@echo "clean"

init: 
	@mkdir -p $(BUILD)/$(TEST)
	@mkdir -p $(OBJ)/$(SRC)
	@mkdir -p $(OBJ)/$(TEST)

# clean directory and re-compile
new:
	make clean
	make

#
# Unit tests
# 
testTime: init $(OBJS)
	@echo "Compiling testTime.cpp"
	$(CC) -c -g $(TEST)/testTime.cpp
	$(CC) -Wall -o testTime testTime.o $(OBJS)
	@mv testTime.o $(OBJ)/$(TEST)
	@mv testTime $(BUILD)/$(TEST)
	@echo "Compilation Successful!"
	@echo ""
	@echo "Running testAdd..."
	@echo ""
	@./$(BUILD)/$(TEST)/testTime

testAdd: init $(OBJS)
	@echo "Compiling testAdd.cpp"
	$(CC) -c -g $(TEST)/testAdd.cpp
	$(CC) -Wall -o testAdd testAdd.o $(OBJS)
	@mv testAdd.o $(OBJ)/$(TEST)
	@mv testAdd $(BUILD)/$(TEST)
	@echo "Compilation Successful!"
	@echo ""
	@echo "Running testAdd..."
	@echo ""
	@./$(BUILD)/$(TEST)/testAdd 