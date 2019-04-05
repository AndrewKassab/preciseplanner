# Directory List
TEST=test
SRC=src
BUILD=build
OBJ=$(BUILD)/obj
DATA=data

HEADERS		= $(SRC)/Show.hpp $(SRC)/Planner.hpp $(SRC)/Schedule.hpp
OBJS		= $(OBJ)/$(SRC)/Show.o $(OBJ)/$(SRC)/Schedule.o \
			  $(OBJ)/$(SRC)/addShows.o $(OBJ)/$(SRC)/readWrite.o \
			  $(OBJ)/$(SRC)/main.o $(OBJ)/$(SRC)/Planner.o \
				$(OBJ)/$(SRC)/removeShows.o
SRCS 		= $(SRC)/Show.cpp $(SRC)/Planner.cpp $(SRC)/Schedule.cpp \
			  $(SRC)/addShows.cpp $(SRC)/readWrite.cpp $(SRC)/main.cpp \
			  $(SRC)/Planner.cpp $(SRC)/removeShows.cpp
EXE 		= planner 

OBJS_TEST	= $(OBJ)/$(SRC)/Show.o $(OBJ)/$(SRC)/Schedule.o \
			  $(OBJ)/$(SRC)/addShows.o $(OBJ)/$(SRC)/readWrite.o \
				$(OBJ)/$(SRC)/Planner.o $(OBJ)/$(SRC)/removeShows.o

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
	@$(CC) -o $(EXE) $(OBJS) 
	@echo "Done, Generated executable: $(EXE)"
	@mv $(EXE) $(BUILD)

# compiles object files from their corresponding source files
$(OBJ)/$(SRC)/%.o:$(SRC)/%.cpp
	@echo "Compiling each C++ source file separately ..."
	$(CC) -c -g $<
	@mv *.o $(OBJ)/$(SRC)

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

wipedata:
	@rm -rf ~/.preciseplanner/*

install: $(EXE)
	@sudo chmod 555 ./build/planner 
	@echo "Moving executable to /usr/local/bin"
	@sudo mv ./build/planner /usr/local/bin 
	@echo "Creating ~/.preciseplanner directory and necessary files"
	@mkdir -p ~/.preciseplanner 
	@touch ~/.preciseplanner/schedule.txt
	@touch ~/.preciseplanner/archive.txt
	@chmod 777 ~/.preciseplanner/schedule.txt
	@chmod 777 ~/.preciseplanner/archive.txt
	@echo "Installation complete, run "planner" to get started."

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
