#  _______________________________________________________________
# /                                                               /
#||  Course: CSCI-480      Assignment #: 7   Semester: Spring2020 ||
#||                                                               ||
#||  Name: Ryan Rickgauer  Z-ID: z1729300    Section: 2           ||
#||                                                               ||
#||  TA's Name:		Jingwan Li                                   ||
#||                                                               ||
#||  Due: 				4-24-2020                                    ||
#||                                                               ||
#||  Description:	This compiles and runs the assignment.          ||
#||                                                               ||
# \________________________________________________________________/

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
Assign7: Assignment7.o
	g++ $(CCFLAGS) -o Assign7 Assignment7.o

# Rules to compile source code file to object code
Assignment7.o: Assignment7.cpp
	g++ $(CCFLAGS) -c Assignment7.cpp


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o Assign7
