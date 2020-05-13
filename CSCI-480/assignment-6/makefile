#  _______________________________________________________________
# /                                                               \
#||  Course: CSCI-480      Assignment #: 6   Semester: Spring2020 ||
#||                                                               ||
#||  Name: Ryan Rickgauer  Z-ID: z1729300    Section: 2           ||
#||                                                               ||
#||  TA's Name:		Jingwan Li                                      ||
#||                                                               ||
#||  Due: 				4-6-2020                                        ||
#||                                                               ||
#||  Description:	This compiles and runs the assignment.          ||
#||                                                               ||
# \________________________________________________________________/

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
Assign6: Assignment6.o
	g++ $(CCFLAGS) -o Assign6 Assignment6.o

# Rules to compile source code file to object code
Assignment6.o: Assignment6.cpp
	g++ $(CCFLAGS) -c Assignment6.cpp


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o Assign6
