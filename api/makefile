CC=clang++
CFLAGS=-std=c++11
FILEPATH=../dto

OBJECTSH_= Student.h Teacher.h Subject.h Department.h
OBJECTSH=$(patsubst %,$(FILEPATH)/%,$(OBJECTSH_))

OBJECTSCPP_=Student.cpp Teacher.cpp Subject.cpp Department.cpp
OBJECTSCPP=$(patsubst %,$(FILEPATH)/%,$(OBJECTSCPP_))

OBJECTSO=Student.o Teacher.o Subject.o Department.o

HEADERPATH=-I../dto -I../api

projekat: main.o $(OBJECTSO) utility_functions.o APIs.o
	$(CC) $(CFLAGS) -o projekat main.o $(OBJECTSO) utility_functions.o APIs.o $(HEADERPATH)

main.o: main.cpp $(OBJECTSCPP) utility_functions.cpp APIs.cpp APIs.h utility_functions.h $(OBJECTSH)
	$(CC) $(CFLAGS) -c main.cpp $(HEADERPATH)

objekti.o: $(OBJEKTICPP) $(OBJEKTIH) utility_functions.cpp utility_functions.h 
	$(CC) $(CFLAGS) -c $(OBJEKTICPP) $(HEADERPATH)

utility_functions.o: utility_functions.cpp utility_functions.h
	$(CC) $(CFLAGS) -c utility_functions.cpp $(HEADERPATH)

APIs.o: APIs.cpp APIs.h
	$(CC) $(CFLAGS) -c APIs.cpp -I../dto -I../api

Student.o : $(FILEPATH)/Student.cpp $(FILEPATH)/Student.h
	$(CC) $(CFLAGS) -c $(FILEPATH)/Student.cpp $(HEADERPATH)

Teacher.o : $(FILEPATH)/Teacher.cpp $(FILEPATH)/Teacher.h $(FILEPATH)/Student.h
	$(CC) $(CFLAGS) -c $(FILEPATH)/Teacher.cpp $(HEADERPATH)

Subject.o : $(FILEPATH)/Subject.cpp $(FILEPATH)/Subject.h
	$(CC) $(CFLAGS) -c $(FILEPATH)/Subject.cpp $(HEADERPATH)

Department.o : $(FILEPATH)/Department.cpp $(FILEPATH)/Department.h
	$(CC) $(CFLAGS) -c $(FILEPATH)/Department.cpp $(HEADERPATH)

clean:
	rm *.o
