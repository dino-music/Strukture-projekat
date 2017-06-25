//Dino Music
#pragma once
#include "API.h"
#include "objekti.h"

class studentapi;
class teacherapi;
class subjectapi;
class departmentapi;


class studentapi:public API<Student>
{
  private:
    subjectapi* subjectAPI;
    departmentapi* departmentAPI;

  public:
    studentapi(std::string s):API(s){}
    void setSubjectAPI(subjectapi *reff){subjectAPI=reff;}
    void setDepartmentAPI(departmentapi *reff){departmentAPI=reff;}
    std::string getDep(unsigned int);
    void getAll();
    void getOne(unsigned int key);
};

class teacherapi:public API<Teacher>
{
  private:
    subjectapi* subjectAPI;
    departmentapi* departmentAPI;

  public:
    teacherapi(std::string s):API(s){}
    void setSubjectAPI(subjectapi* reff){subjectAPI=reff;}
    void setDepartmentAPI(departmentapi* reff){departmentAPI=reff;}
    std::string getDep(unsigned int);
    void getAll();
    void getOne(unsigned int key);
};

class subjectapi:public API<Subject>
{
  private:
    departmentapi* departmentAPI;
    studentapi* studentAPI;
    teacherapi* teacherAPI;
  
  public:
    subjectapi(std::string s):API(s){}
    void setDepartmentAPI(departmentapi* reff){departmentAPI=reff;}
    void setStudentAPI(studentapi* reff){studentAPI=reff;}
    void setTeacherAPI(teacherapi* reff){teacherAPI=reff;}
    void getAll(){printall("ID, Ime, ECTS krediti, Skracenica");}
    void getOne(unsigned int key){printone(key,"predmet");}
    void getStudents(unsigned int);
};


class departmentapi:public API<Department>
{
  private:
    subjectapi* subjectAPI;

  public:
    departmentapi(std::string s):API(s){}
    void setSubjectAPI(subjectapi* reff){subjectAPI=reff;}
    void getAll(){printall("ID, Ime");}
    void getOne(unsigned int key){printone(key,"odsjek");}
};
