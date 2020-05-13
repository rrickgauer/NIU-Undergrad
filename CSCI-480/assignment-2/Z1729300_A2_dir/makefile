# Ryan Rickgauer
# z1729300
# Assignment 2 Makefile

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
Assign2: Assign2.o
	g++ $(CCFLAGS) -o Assign2 Assign2.o

# Rules to compile source code file to object code
Assign2.o: Assign2.cc
	g++ $(CCFLAGS) -c Assign2.cc


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o Assign2
