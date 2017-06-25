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
  //studentAPI.for_each([](const Student& a){a.print_fancy();});
  studentAPI.getAll();
  //teacherAPI.for_each([](const Teacher& a){a.print_fancy();});
  teacherAPI.getAll();
  //subjectAPI.for_each([](const Subject& a){a.print_fancy();});
  subjectAPI.getAll();
  //departmentAPI.for_each([](const Department& a){a.print_fancy();});
  departmentAPI.getAll();
  studentAPI.getOne(1);
  studentAPI.getOne(4);
  subjectAPI.getOne(2);
  subjectAPI.getOne(5);
  subjectAPI.getStudents(1);
  return 0;
}
