#  _______________________________________________________________
# /                                                               \
#||  Course: CSCI-480      Assignment #: 5   Semester: Spring2020 ||
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
CCFLAGS = -Wall -std=c++11 -pthread

# Rule to link object code files to create executable file
Assign5: Assignment5.o
	g++ $(CCFLAGS) -o Assign5 Assignment5.o

# Rules to compile source code file to object code
Assignment5.o: Assignment5.cpp
	g++ $(CCFLAGS) -c Assignment5.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o Assign5
