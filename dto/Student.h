#pragma once
#include<string>
#include<sstream>
#include <iostream>
#include<list>

//Harun Muderizovic
struct exam
{
  unsigned int subjectId;
  unsigned int teacherId;
  int evaluation;
  std::string date;

  exam(unsigned int sID, unsigned int tID, int e, const std::string& d) : subjectId(sID),teacherId(tID),evaluation(e),date(d) {}
  void print() const{std::cout<<subjectId<<" "<<teacherId<<" "<<evaluation<<" "<<date<<" ";}
  bool operator==(const exam& drugi) { return ((subjectId==drugi.subjectId) && (teacherId==drugi.teacherId) && (evaluation==drugi.evaluation) && (date == drugi.date));}
  void operator=(const exam& drugi)	
  {
  	subjectId = drugi.subjectId; 
	teacherId = drugi.teacherId; 
	evaluation = drugi.evaluation; 
	date = drugi.date;
  }
};

//Emina Mahmutbegovic
class Student{
  protected:
    unsigned int id;
    std::string firstName;
    std::string lastName;
    std::string birthDate;
    std::string email;
    char gender;
    std::string jmbg;
    unsigned int depId;
    std::list<exam> exams;
  public:
  Student()=default;
  Student(const std::string&);
  //Ina Saltovic
  Student(unsigned int, const std::string&, const std::string&, const std::string&, const std::string&, char, const std::string&, unsigned int);
  unsigned int getId()const{return id;}
  const std::string& getFirstName()const {return firstName;}
  const std::string& getLastName()const{return lastName;}
  const std::string& getBirthDate()const{return birthDate;}
  const std::string& getEmail()const{return email;} 
  const std::string& getJmbg()const{return jmbg;}
  char getGender()const{return gender;}
  unsigned int getDepId()const{return depId;}
  void setLastName(const std::string& n){lastName=n;}
  void print()const;//za printanje u jednoj liniji
  void print_fancy(std::string)const;//za uredjenije printanje
  //Harun Muderizovic
  void addExam(const exam& e){exams.push_back(e);}
  //Ina Saltovic
  void file_output(std::ofstream&);
  //Vedad Mešić
  void debug_print()const;
  void file_outputSST(std::ofstream&);
};

