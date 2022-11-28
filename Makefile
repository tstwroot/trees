OBJ 				= $(PWD)/obj
LIB 				= $(PWD)/lib
INCLUDES 		= $(PWD)/includes
SRC 				= $(PWD)/src
BIN					= $(PWD)/bin
CC					= gcc
FLAGS				= -g -c -Wall

all: tree.o
	$(CC) -g main.c $(OBJ)/tree.o -o $(BIN)/main
	$(BIN)/main

tree.o:
	$(CC) $(FLAGS) $(SRC)/tree.c -I$(INCLUDES) -o $(OBJ)/tree.o

clean:
	rm -rf $(OBJ)/*
	rm -rf $(BIN)/*
