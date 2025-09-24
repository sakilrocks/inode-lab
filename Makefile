
# compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# source files
SRC = src/main.cpp src/filesystem.cpp

# output executable
EXEC = inode-lab

# default target
all: $(EXEC)

# build executable
$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC)

# clean object files and executable
clean:
	rm -f $(EXEC) *.o

# run the program
run: $(EXEC)
	./$(EXEC)