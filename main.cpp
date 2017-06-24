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
  studentAPI.for_each([](const Student& a){a.debug_print();});
  teacherAPI.for_each([](const Teacher& a){a.debug_print();});
  subjectAPI.for_each([](const Subject& a){a.debug_print();});
  departmentAPI.for_each([](const Department& a){a.debug_print();});
  return 0;
}
