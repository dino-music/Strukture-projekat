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
  
  cout << endl;
  studentAPI.getAll();
  cout << endl;
  studentAPI.save(3, "Josip", "Broz", "1892-5-7", "josip.broz@fet.ba", 'M', "2307996185082", 2);
  studentAPI.getAll();
  cout << endl;
  studentAPI.getById(1);
  cout << "Polozeni predmeti:" << endl;
  studentAPI.passedExams(1);
  cout << endl << endl << endl;

  departmentAPI.getSubjects(1);
  subjectAPI.Remove(2);
  departmentAPI.getSubjects(1);
  departmentAPI.getById(2);
  departmentAPI.save(3,"Telekomunikacije");
  departmentAPI.getById(3);

  studentAPI.changeLastName(3,"Broz-TITO");
  studentAPI.getById(3);

  studentAPI.save(4, "Jaska", "Nekic", "1999-9-9", "jaska.nek@fet.ba", 'F', "1007967122155", 3);
  cout << endl;
  studentAPI.getAll();

  teacherAPI.getById(10);
  
  cout << endl;

  teacherAPI.changeTitle(2,"docent");
  teacherAPI.getById(2);
  
  cout << endl;
  
  teacherAPI.changeDep(1,3);
  teacherAPI.getById(1);

  subjectAPI.save(3,"Uvod u Racunarske Algoritme", 6, "URA");
  subjectAPI.getAll();
  

  update(studentAPI,teacherAPI,subjectAPI,departmentAPI);
}
