#pragma once
#include<string>
#include<sstream>
#include <iostream>
#include"API.h"
#include<list>

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
  void file_outputST(std::ofstream&);
  void file_outputDS(std::ofstream&);
  std::list<unsigned int>& getStudents(){return students;}
  std::list<unsigned int>& getTeachers(){return teachers;}
  std::string getYear()const{return year;}
  std::string getSemester()const{return semester;}
};
