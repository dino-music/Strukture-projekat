#include"APIs.h"
#include"utility_functions.h"
using namespace std;


int main(void)
{
  studentapi studentAPI("students.txt");
  teacherapi teacherAPI("teachers.txt");
  subjectapi subjectAPI("subjects.txt");
  departmentapi departmentAPI("departments.txt");
  connect(studentAPI,teacherAPI,subjectAPI,departmentAPI);
  
 //studentAPI.for_each([](const Student& a){a.debug_print();});
  studentAPI.getAll();
  //teacherAPI.for_each([](const Teacher& a){a.debug_print();});
  teacherAPI.getAll();
  //subjectAPI.for_each([](const Subject& a){a.debug_print();});
  subjectAPI.getAll();
 // departmentAPI.for_each([](const Department& a){a.debug_print();});
  departmentAPI.getAll();
  studentAPI.getById(1);
  studentAPI.getById(4);
  subjectAPI.getById(2);
  subjectAPI.getById(5);
  subjectAPI.getStudents(1);
  subjectAPI.getTeachers(1);
  subjectAPI.getTeachers(2);
  studentAPI.update();
  teacherAPI.update();
  subjectAPI.update();
  departmentAPI.update();
  updateDepSub(subjectAPI);
  updateSubjTeach(subjectAPI);
  updateStudSubjTeach(studentAPI);

  return 0;
}
