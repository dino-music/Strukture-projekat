#pragma once
#include<string>
#include<sstream>
#include <iostream>
#include "linkedlist.h"
#include "API.h"
#include<list>
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
  void print()const;//za printanje u jednoj liniji
  void print_fancy(std::string)const;//za uredjenije printanje
  //Harun Muderizovic
  void addExam(const exam& e){exams.push_back(e);}
  //Ina Saltovic
  void file_output(std::ofstream&);
  //Vedad Mešić
  void debug_print()const;

};

class Teacher: public Student{
  protected:
  std::string title;
  std::list<unsigned int> subjects;
  public:
  Teacher(const std::string&);    
  //Harun Muderizovic
  void addSubject(unsigned int id){subjects.push_back(id);}
  //Ina Saltovic
  Teacher(unsigned int, const std::string&, const std::string&, const std::string&, const std::string&, char, const std::string&, unsigned int, const std::string&);
  void print()const;
  void print_fancy(std::string)const;
  const std::string& getTitle()const {return title;}
  //Ina Saltovic
  void file_output(std::ofstream&);
   //Vedad Mešić
  void debug_print()const;

};

class Subject{
  private:
    unsigned int id;
    std::string name;
    unsigned int ects;
    std::string abberv;
    std::string year;
    std::string semester;
    unsigned int department;
    std::list<unsigned int> teachers;
    std::list<unsigned int> students;
  
  public:
  Subject(const std::string&);
  //Ina Saltovic
  Subject(unsigned int, const std::string&, unsigned int, const std::string&);
  unsigned int getId()const{return id;}
  void print()const;
  void print_fancy()const;
  void setYear(const std::string& y){year=y;}
  void setSemester(const std::string& s){semester=s;}
  void setDepartment(unsigned int dep){department=dep;}
  void addTeacher(unsigned int id){teachers.push_back(id);}
  //Harun Muderizovic
  void addStudent(unsigned int id){students.push_back(id);}
  //Ina Saltovic
  void file_output(std::ofstream&);
   //Vedad Mešić
  void debug_print()const;
  std::list<unsigned int>& getStudents(){return students;}
  std::list<unsigned int>& getTeachers(){return teachers;}

};


class Department{
  private:
    unsigned int id;
    std::string name;
    std::list<unsigned int> subjects;
  public:
    Department(const std::string&);
    //Ina Saltovic
    Department(unsigned int, const std::string&);
    unsigned int getId()const{return id;}
    std::string getName()const{return name;}
    void print()const;
    void print_fancy()const;
    void addSubject(unsigned int id){subjects.push_back(id);}
    //Ina Saltovic
    void file_output(std::ofstream&);
   //Vedad Mešić
  void debug_print()const;

};



