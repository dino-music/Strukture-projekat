#pragma once
#include"Student.h"

class Teacher: public Student{
  protected:
  std::string title;
  std::list<unsigned int> subjects;
  public:
  Teacher(const std::string&);   
  void setTitle(const std::string& t){title=t;}
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
  //Harun Muderizovic
	std::list<unsigned int>& getSubjects() {return subjects;}
};
