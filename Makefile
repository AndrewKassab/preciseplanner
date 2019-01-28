# Directory List
TEST=test
SRC=src
BUILD=build
OBJ=$(BUILD)/obj

HEADERS		= $(SRC)/Show.hpp $(SRC)/Planner.hpp
OBJS		= $(OBJ)/Show.o $(OBJ)/Planner.o $(OBJ)/$(TEST)/testAdd.o \
			  $(OBJ)/$(TEST)/testTime.o
SRCS 		= $(SRC)/Show.cpp $(SRC)/Planner.cpp
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
$(OBJ)/%.o:$(SRC)/%.cpp
	@echo "Compiling each C++ source file separately ..."
	$(CC) -c -g $<
	@echo ""

$(OBJ)/$(TEST)/%.o:$(TEST)/%.cpp

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

moveobj:
	@mv testAdd.o $(OBJ)/$(TEST)
	@mv Show.o Planner.o $(OBJ)/$(SRC)
	@mv testAdd $(BUILD)/$(TEST)

#
# Unit tests
# 
testTime: init
	@echo "Compiling testTime.cpp"
	$(CC) -Wall -o testTime testTime.o Show.o
	@mv testTime.o $(OBJ)/$(TEST)
	@mv Show.o $(OBJ)/$(SRC)
	@mv testTime $(BUILD)/$(TEST)
	@echo "Compilation Successful!"
	@echo "Running testTime..."
	@./$(BUILD)/$(TEST)/testTime

testAdd: init $(OBJS)
	@echo "Compiling testAdd.cpp"
	$(CC) -Wall -o testAdd testAdd.o Show.o Planner.o
	moveobj
	@echo "Compilation Successful!"
	@echo "Running testAdd..."
	@./$(BUILD)/$(TEST)/testAdd

