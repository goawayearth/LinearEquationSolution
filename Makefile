# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall

# The build target executable:
TARGET = LinearEquation

# Object files
OBJS = LinearEquation.o ColumnPivoting.o LUdecomposition.o

# Compile the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile object files from source files
LinearEquation.o: LinearEquation.c ColumnPivoting.h LUdecomposition.h
	$(CC) $(CFLAGS) -c LinearEquation.c

ColumnPivoting.o: ColumnPivoting.c ColumnPivoting.h
	$(CC) $(CFLAGS) -c ColumnPivoting.c

LUdecomposition.o: LUdecomposition.c LUdecomposition.h ColumnPivoting.h
	$(CC) $(CFLAGS) -c LUdecomposition.c

# Clean up
clean:
	rm -f $(TARGET) $(OBJS)
