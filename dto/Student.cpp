#include"Student.h"
#include <stdexcept>
#include"utility_functions.h"

//Emina Mahmutbegovic
Student::Student(const std::string& line){ 
  std::stringstream sline(line);
  int i=1;
  std::string info;
  getline(sline,info,',');
  id=stoi(info);
  while(std::getline(sline,info,' ')){ 
  getline(sline,info,',');
  ++i;
  switch(i){
    case 2: firstName=info; break;
    case 3: lastName=info; break;
    case 4: birthDate=info; break;
    case 5: if(!isValid_mail(info))
              throw std::invalid_argument("pogresan unos maila");
            email=info;
            break;
    case 6: gender=info[0]; break;
    case 7: if(!isValid_jmbg(info))
              throw std::invalid_argument("pogresan unos jmbg");
            jmbg=info; break;
    case 8: depId=stoi(info); break; 

  }
  }
}

//Ina Saltovic
Student::Student(unsigned int ID, const std::string& ime, const std::string& prezime, const std::string& datum, const std::string& mail, char spol, const std::string& JMBG, unsigned int depID) : id{ID}, firstName{ime}, lastName{prezime}, birthDate{datum}, email{mail}, gender{spol}, jmbg{JMBG}, depId{depID} {}

//Ina Saltovic
void Student::file_output(std::ofstream& fajl){
  const std::string c = ", ";
  fajl << id << c << firstName << c << lastName << c << birthDate << c << email << c << gender << c << jmbg << c << depId << std::endl;
}

void Student::print()const{
  std::cout<<id<<", "<<firstName<<", "<<lastName<<", "<<birthDate<<", "<<email<<", "<<gender<<", "<<jmbg<<", ";
}

void Student::print_fancy(std::string dep)const{
  std::cout<<"ID: "<<id<<std::endl;
  std::cout<<"Ime, prezime: "<<firstName<<", "<<lastName<<std::endl;
  std::cout<<"Datum rodjenja: "<<birthDate<<std::endl;
  std::cout<<"E-mail: "<<email<<std::endl;
  std::cout<<"Spol: "<<gender<<std::endl;
  std::cout<<"JMBG: "<<jmbg<<std::endl;
  std::cout<<"Odsjek: "<<dep<<std::endl;
  std::cout<<std::endl;
}
//Vedad Mešić
//debug print metode u svakom objekti za ispis svih elemenata
void Student::debug_print()const{
  std::cout<<id<<", "<<firstName<<", "<<lastName<<", "<<birthDate<<", "<<email<<", "<<gender<<", "<<
    jmbg<<", "<<depId<<", "<<std::endl;
  //Harun treba ubaciti exams
  std::cout<<" Exams:";
  for(auto el: exams)
    el.print();
  std::cout<<std::endl<<std::endl;
}
void Student::file_outputSST(std::ofstream& fajl){
  for(auto& el: exams){
    fajl<<id<<", "<<el.subjectId<<", "<<el.teacherId<<", "<<el.evaluation<<", "<<el.date<<std::endl;
  }
}
