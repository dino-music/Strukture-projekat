#pragma once
#include<string>
#include<sstream>
#include <iostream>

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
  public:
  Student()=default;
  Student(const std::string&);
  unsigned int getId()const{return id;}
  const std::string& getFirstName()const {return firstName;}
  const std::string& getLastName()const{return lastName;}
  const std::string& getBirthDate()const{return birthDate;}
  const std::string& getEmail()const{return email;} 
  const std::string& getJmbg()const{return jmbg;}
  char getGender()const{return gender;}
  unsigned int getDepId()const{return depId;}
  void print()const;
};

class Teacher: public Student{
  protected:
  std::string title;
  public:
  Teacher(const std::string&);
  void print()const;
  const std::string& getTitle()const {return title;}
};

class Subject{
  private:
    unsigned int id;
    std::string name;
    unsigned int ects;
    std::string abberv;
    std::string year;
    std::string semester;
  public:
  Subject(const std::string&);
  unsigned int getId()const{return id;}
  void print()const;
};


class Department{
  private:
    unsigned int id;
    std::string name;
  public:
    Department(const std::string&);
    unsigned int getId()const{return id;}
    void print()const;

};

