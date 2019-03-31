# Directory List
TEST=test
SRC=src
BUILD=build
OBJ=$(BUILD)/obj

HEADERS		= $(SRC)/Show.hpp $(SRC)/Planner.hpp $(SRC)/Schedule.hpp
OBJS		= $(OBJ)/$(SRC)/Show.o $(OBJ)/$(SRC)/Schedule.o \
			  $(OBJ)/$(SRC)/addShows.o $(OBJ)/$(SRC)/readSchedule.o \
			  $(OBJ)/$(SRC)/main.o $(OBJ)/$(SRC)/Planner.o
SRCS 		= $(SRC)/Show.cpp $(SRC)/Planner.cpp $(SRC)/Schedule.cpp \
			  $(SRC)/addShows.cpp $(SRC)/readSchedule.cpp $(SRC)/main.cpp \
			  $(SRC)/Planner.cpp
EXE 		= preciseplanner

OBJS_TEST	= $(OBJ)/$(SRC)/Show.o $(OBJ)/$(SRC)/Schedule.o \
			  $(OBJ)/$(SRC)/addShows.o $(OBJ)/$(SRC)/readSchedule.o \
				$(OBJ)/$(SRC)/Planner.o

# our c++ compiler
CC=g++

# MMD: automatically resolve included files
# g: include debugging symbols
# Wall: enable all warnings
# std: language standard to compile for 
CXXFLAGS=-MMD -g -Wall -std=c++11

# default target, compiles executable, depends on object files
$(EXE): init $(OBJS) $(MAIN_OBJ)
	@echo "Linking all object modules..."
	$(CC) -o $(EXE) $(OBJS) 
	@echo ""
	@echo "Done, Generated executable: $(EXE)"
	@mv $(EXE) $(BUILD)

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
	@mkdir -p data

# clean directory and re-compile
new:
	make clean
	make

#
# Unit tests
# 
testCompare: init $(OBJS)
	@echo "Compiling testCompare.cpp"
	$(CC) -c -g $(TEST)/testCompare.cpp
	$(CC) -Wall -o testCompare testCompare.o $(OBJS_TEST)
	@mv testCompare.o $(OBJ)/$(TEST)
	@mv testCompare $(BUILD)/$(TEST)
	@echo "Compilation Successful!"
	@echo ""
	@echo "Running testCompare..."
	@echo ""
	@./$(BUILD)/$(TEST)/testCompare

testAdd: init $(OBJS)
	@echo "Compiling testAdd.cpp"
	$(CC) -c -g $(TEST)/testAdd.cpp
	$(CC) -Wall -o testAdd testAdd.o $(OBJS_TEST)
	@mv testAdd.o $(OBJ)/$(TEST)
	@mv testAdd $(BUILD)/$(TEST)
	@echo "Compilation Successful!"
	@echo ""
	@echo "Running testAdd..."
	@echo ""
	@./$(BUILD)/$(TEST)/testAdd 

testPrint: init $(OBJS)
	@echo "Compiling testPrint.cpp"
	$(CC) -c -g $(TEST)/testPrint.cpp
	$(CC) -Wall -o testPrint testPrint.o $(OBJS_TEST)
	@mv testPrint.o $(OBJ)/$(TEST)
	@mv testPrint $(BUILD)/$(TEST)
	@echo "Compilation Successful!"
	@echo ""
	@echo "Running testPrint..."
	@echo ""
	@./$(BUILD)/$(TEST)/testPrint 

testRead: init $(OBJS)
	@echo "Compiling testRead.cpp"
	$(CC) -c -g $(TEST)/testRead.cpp
	$(CC) -Wall -o testRead testRead.o $(OBJS_TEST)
	@mv testRead.o $(OBJ)/$(TEST)
	@mv testRead $(BUILD)/$(TEST)
	@echo "Compilation Successful!"
	@echo ""
	@echo "Running testRead..."
	@echo ""
	@./$(BUILD)/$(TEST)/testRead 