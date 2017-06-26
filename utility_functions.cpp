//Ina Saltovic
#include "utility_functions.h"

bool isValid_mail(std::string mail){
  int position1 = mail.find("."); //pronalazenje pozicije prve tacke u mail-u
  int position2 = mail.find("@"); //pronalazenje pozicije znaka @ u mailu
  int position3 = mail.find(".", position1+1); //pronalazenje pozicije druge tacke u mail-u
  //ako su pronadjene 2 tacke i znak @ i ako je prva tacka prije znaka @ a druga tacka nakon znaka @, to znači da je 
  //mail dobar ukoliko nemamo još jednu tacku u mailu
  if(position1!=-1 && position2!=-1 && position3!=-1 && position2 > position1 && position2 < position3){
    int positionX = mail.find(".", position3+1);
    if(positionX==-1) //provjeravanje postoji li jos jedna tacka u mail-u, ukoliko ne postoji mail je validan
      return true;
  }
  return false; //u suprotnom nije validan
}

bool isValid_jmbg(std::string jmbg){
  if(jmbg.size()!=13) return false; //ukoliko jbmg sadrzi vise od 13 elemenata, nije validan
  std::vector<int> JMBG;
  for(int i = 0; i < jmbg.size(); i++)
    JMBG.push_back(jmbg[i]-'0'); //pretvaranje char-ova u int-ove i stavljanje u vektor

  //formula za racunanje kontrolnog(zadnjeg) broja jbmg-a
  int m = ((7*(JMBG[0]+JMBG[6]) + 6*(JMBG[1]+JMBG[7]) + 5*(JMBG[2]+JMBG[8]) + 4*(JMBG[3]+JMBG[9]) + 3*(JMBG[4]+JMBG[10]) + 2*(JMBG[5]+JMBG[11])) % 11);
  //uslijed postojanja dva nacina za racunanje kontrolnog broja, moraju se provjeriti obje mogucnosti
  int n=m;
  if(n>1)
    n=11-n;
  if(m>9)
    m=0;
  return m==JMBG[12] || n==JMBG[12];
}


//Harun Muderizovic
void SubjTeach(subjectapi& subj, teacherapi& teach,std::string fileName)
{
  std::fstream file(fileName);
  std::string line; 
  unsigned int sID, tID;
  char zarez;
  std::getline(file,line); // učitavanje prve linije, sa rasporedom kolona

  while(getline(file,line)) // obrada ostalih linija
  {
    std::stringstream ss(line);

    ss >> sID >> zarez >> tID;
    auto itSUB = subj.find(sID);
    auto itTEA = teach.find(tID);
    // ako objekti postoje
    if(itSUB != subj.end() && itTEA != teach.end())
    {  
      (*itSUB).addTeacher(tID);
      (*itTEA).addSubject(sID);
    }

  }
  
  file.close();
}

void StudExams(studentapi& stud, subjectapi& subj, std::string fileName)
{
  std::fstream file(fileName);
  std::string line;
  unsigned int studID, subjID, tID;
  int eval;
  char zarez;
  std::string date;
  std::getline(file,line); // učitavanje prve linije, sa rasporedom kolona
  
  while(getline(file,line)) // obrada ostalih linija
  {
    std::stringstream ss(line);
    
    ss>>studID>>zarez>>subjID>>zarez>>tID>>zarez>>eval>>zarez;
    std::getline(ss,line,' ');
    std::getline(ss,date,'\r');

    auto itSTUD = stud.find(studID);
    auto itSUBJ = subj.find(subjID); 
    // ako objekti postoje
    if(itSTUD != stud.end() && itSUBJ != subj.end())
    {
      (*itSTUD).addExam(exam(subjID,tID,eval,date));
      (*itSUBJ).addStudent(studID);
    }  
  }

  file.close();
}

//Vedad Mešić
void depSubRead(subjectapi& a, departmentapi& b, std::string c)
{
  std::string x;
  std::fstream file(c);
  while(!file.is_open()){
    std::cout<<"Pogrešan unos. Unesite ponovo:"<<std::endl;
    std::cin>>c;
  }
  getline(file,x);
  while(getline(file,x)){
    std::stringstream in(x);
    std::string dep,sub,year,sem;
    in>>dep;
    in>>sub;
    in>>year;
    getline(in,sem,'\r');
    unsigned int var=std::stoi(sub);
    year=year.substr(0,year.size()-1);
    auto it=a.find(var);
   (*it).setDepartment(stoi(dep));
    (*it).setYear(year);
    (*it).setSemester(sem);
    auto it2=b.find(stoi(dep));
    (*it2).addSubject(stoi(sub));
  }
  file.close();
}

//Dino Music
//Funkcija uspostavlja poveznice glavnih hash tabela. Ujedno povezuje hash tabele koje ce trebati izravan pristup
//jedna drugoj
void connect(studentapi& stud,teacherapi& teac,subjectapi& sub,departmentapi& dep)
{
  SubjTeach(sub,teac,"subjects-teachers.txt");
  StudExams(stud,sub,"students-subjects-teachers.txt");
  depSubRead(sub,dep,"departments-subjects.txt");

  stud.setSubjectAPI(&sub);
  stud.setDepartmentAPI(&dep);

  teac.setSubjectAPI(&sub);
  teac.setDepartmentAPI(&dep);

  sub.setDepartmentAPI(&dep);
  sub.setStudentAPI(&stud);
  sub.setTeacherAPI(&teac);

  dep.setSubjectAPI(&sub);
}
//Vedad Mešić
void updateStudSubjTeach(studentapi& a)
{
  std::ofstream file;
  file.open("students-subjects-teachers.txt");
  file<<"studentId | subjectId | teacherId | evaluation | date"<<std::endl;
  auto lambda=[&](Student& b){b.file_outputSST(file);};
  a.for_each(lambda);
}
void updateSubjTeach(subjectapi& a){
  std::ofstream file;
  file.open("subjects-teachers.txt");
  file<<"subjectId | teacherId"<<std::endl;
  auto lambda=[&](Subject& b){b.file_outputST(file);};
  a.for_each(lambda);
}
void updateDepSub(subjectapi& a){
  std::ofstream file;
  file.open("deparments-subjects.txt");
  file<<"deparmentId | subjectId | studyYear , studySemester"<<std::endl;
  auto lambda=[&](Subject& b){b.file_outputDS(file);};
  a.for_each(lambda);
}
