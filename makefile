CC=clang++
CFLAGS=-std=c++11

projekat: main.cpp objekti.cpp APIs.cpp utility_functions.cpp
	$(CC) -o projekat -std=c++11 main.cpp objekti.cpp APIs.cpp utility_functions.cpp
