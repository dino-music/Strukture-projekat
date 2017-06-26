//Dino Music
#pragma once
#include "API.h"
#include "Student.h"
#include "Teacher.h"
#include "Subject.h"
#include "Department.h"

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
    studentapi():API(){}
    void setSubjectAPI(subjectapi *reff){subjectAPI=reff;}
    void setDepartmentAPI(departmentapi *reff){departmentAPI=reff;}
    std::string getDep(unsigned int);
    void getAll();
    void getById(unsigned int key);
    void update(){Update("ID | firstName | lastName | birthdate | email | gender | jmbg | departmentId");}
    void changeLastName(unsigned int,const std::string&);//Emina M
    void saveStudent(unsigned int,const std::string&,const std::string&,const std::string&,const std::string&,
        char,const std::string&,unsigned int);//Emina M
};

class teacherapi:public API<Teacher>
{
  private:
    subjectapi* subjectAPI;
    departmentapi* departmentAPI;

  public:
    teacherapi():API(){}
    void setSubjectAPI(subjectapi* reff){subjectAPI=reff;}
    void setDepartmentAPI(departmentapi* reff){departmentAPI=reff;}
    std::string getDep(unsigned int);
    void getAll();
    void getById(unsigned int key);
    void update(){Update("ID | firstName | lastName | birthdate | email | gender | jmbg | title| departmentId");}
    void changeLastName(unsigned int,const std::string&);//Emina M
    void changeTitle(unsigned int,const std::string&);//Emina M
};

class subjectapi:public API<Subject>
{
  private:
    departmentapi* departmentAPI;
    studentapi* studentAPI;
    teacherapi* teacherAPI;
  
  public:
    subjectapi():API(){}
    void setDepartmentAPI(departmentapi* reff){departmentAPI=reff;}
    void setStudentAPI(studentapi* reff){studentAPI=reff;}
    void setTeacherAPI(teacherapi* reff){teacherAPI=reff;}
    void getAll(){printall("ID, Ime, ECTS krediti, Skracenica, Godina, Semestar");}
    void getById(unsigned int key){printone(key,"predmet");}
    void getStudents(unsigned int);
    void getTeachers(unsigned int);
    void update(){Update("id | name | ects | abbreviation");}
    //Harun Muderizovic
    void saveSubject(unsigned int, const std::string&, unsigned int, const std::string&);
    void connectSubjDep(unsigned int, unsigned int);
};


class departmentapi:public API<Department>
{
  private:
    subjectapi* subjectAPI;

  public:
    departmentapi():API(){}
    void setSubjectAPI(subjectapi* reff){subjectAPI=reff;}
    void getAll(){printall("ID, Ime");}
    void getById(unsigned int key){printone(key,"odsjek");}
    void update(){Update("id | name");}
    void addSubject(unsigned int,unsigned int,const std::string&,unsigned int,const std::string&,const std::string&,
    const std::string&); //Emina Mahmutbegovic
    void saveDep(unsigned int,const std::string&);//Emina Mahmutbegovic
    void addTeacher(unsigned int,unsigned int,const std::string&,const std::string&,const std::string&,
        const std::string&,char,const std::string&,unsigned int,const std::string&);//Emina Mahmutbegovic
    //Harun Muderizovic
    void getSubjects(unsigned int);
};
