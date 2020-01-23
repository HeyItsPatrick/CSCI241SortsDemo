#
# PROGRAM:    Assign8
# PROGRAMMER: Patrick Schlapp
# LOGIN ID:   z1806407
# DATE DUE:   11/17/16
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign8: assign8.o
	g++ $(CCFLAGS) -o assign8 assign8.o

# Rules to compile source code files to object code
assign8.o: assign8.cpp sorts.h quicksort.h mergesort.h
	g++ $(CCFLAGS) -c assign8.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign8
