#include"APIs.h"
#include"utility_functions.h"
using namespace std;

int main(void)
{
  studentapi studentAPI;
  teacherapi teacherAPI;
  subjectapi subjectAPI;
  departmentapi departmentAPI;
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
  update(studentAPI,teacherAPI,subjectAPI,departmentAPI);

  return 0;
}
