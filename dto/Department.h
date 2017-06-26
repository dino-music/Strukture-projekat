#pragma once
#include<string>
#include<sstream>
#include <iostream>
#include"API.h"
#include<list>

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
  //Harun Muderizovic
	std::list<unsigned int>& getSubjectList() {return subjects;};
};

