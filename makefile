CC=clang++
CFLAGS=-std=c++11

projekat: main.o objekti.o utility_functions.o APIs.o
	$(CC) $(CFLAGS) -o projekat main.o objekti.o utility_functions.o APIs.o

main.o: main.cpp objekti.cpp utility_functions.cpp APIs.cpp APIs.h utility_functions.h objekti.h
	$(CC) $(CFLAGS) -c main.cpp

objekti.o: objekti.cpp objekti.h utility_functions.cpp utility_functions.h 
	$(CC) $(CFLAGS) -c objekti.cpp

utility_functions.o: utility_functions.cpp utility_functions.h
	$(CC) $(CFLAGS) -c utility_functions.cpp

APIs.o: APIs.cpp APIs.h
	$(CC) $(CFLAGS) -c APIs.cpp

clean:
	rm *.o
