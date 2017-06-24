CC=clang++
CFLAGS=-std=c++11

projekat: objekti.cpp APIs.cpp utility_functions.cpp
	$(CC) -o projekat -std=c++11 objekti.cpp APIs.cpp utility_functions.cpp
