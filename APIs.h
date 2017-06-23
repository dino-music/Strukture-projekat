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
    void setSubjectAPI(subjectapi *reff){subjectAPI=reff;}
    void setDepartmentAPI(departmentapi *reff){departmentAPI=reff;}
};

class teacherapi:public API<Teacher>
{
  private:
    subjectapi* subjectAPI;
    departmentapi* departmentAPI;

  public:
    void setSubjectAPI(subjectapi* reff){subjectAPI=reff;}
    void setDepartmentAPI(departmentapi* reff){departmentAPI=reff;}
};

class subjectapi:public API<Subject>
{
  private:
    departmentapi* departmentAPI;
    studentapi* studentAPI;
  
  public:
    void setDepartmentAPI(departmentapi* reff){departmentAPI=reff;}
    void setStudentAPI(studentapi* reff){studentAPI=reff;}
};


class departmentapi:public API<Department>
{
  private:
    subjectapi* subjectAPI;

  public:
    void setSubjectAPI(subjectapi* reff){subjectAPI=reff;}
};
