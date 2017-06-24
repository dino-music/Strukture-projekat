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
};


class departmentapi:public API<Department>
{
  private:
    subjectapi* subjectAPI;

  public:
    departmentapi(std::string s):API(s){}
    void setSubjectAPI(subjectapi* reff){subjectAPI=reff;}
};
