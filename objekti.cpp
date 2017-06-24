#include"objekti.h"
//Emina Mahmutbegovic

#include <stdexcept>
#include"utility_functions.h"
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
Student::Student(unsigned int ID, std::string& ime, std::string& prezime, std::string& datum, std::string& mail, char spol, std::string& JMBG, unsigned int depID) : id{ID}, firstName{ime}, lastName{prezime}, birthDate{datum}, email{mail}, gender{spol}, jmbg{JMBG}, depId{depID} {}

void Student::print()const{
  std::cout<<id<<" "<<firstName<<" "<<lastName<<" "<<birthDate<<" "<<email<<" "<<gender<<" "<<
    jmbg<<" "<<depId<<" "<<std::endl;

}
//Vedad Mešić
//debug print metode u svakom objekti za ispis svih elemanata
void Student::debug_print()const{
  std::cout<<id<<" "<<firstName<<" "<<lastName<<" "<<birthDate<<" "<<email<<" "<<gender<<" "<<
    jmbg<<" "<<depId<<" "<<"Subjects: ";
  for(auto el: subjects )
    std::cout<<el<<" ";
  //Harun treba ubaciti exams
  std::cout<<" Exams:";
  for(auto el: exams)
    std::cout<<el<<" ";
  std::cout<<std::endl;
}


Teacher::Teacher(const std::string& line): Student(){
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
    case 8: title=info; break;
    case 9: depId=stoi(info); break;
  }
  }  
}

//Ina Saltovic
Teacher::Teacher(unsigned int ID, std::string& ime, std::string& prezime, std::string& datum, std::string& mail, char spol, std::string& JMBG, unsigned int depID, std::string& titula) : Student{ID, ime, prezime, datum, mail, spol, JMBG, depID}, title{titula} {}

void Teacher::print()const{
   std::cout<<id<<" "<<firstName<<" "<<lastName<<" "<<birthDate<<" "<<email<<" "<<gender<<" "<<
    jmbg<<" "<<title<<" "<<depId<<" "<<std::endl; 
}
//Vedad Mešić
void Teacher::debug_print()const{
   std::cout<<id<<" "<<firstName<<" "<<lastName<<" "<<birthDate<<" "<<email<<" "<<gender<<" "<<
    jmbg<<" "<<title<<" "<<depId<<" "<<"Subjects: ";
   for(auto el: subjects)
     std::cout<<el<<" ";
   std::cout<<std::endl;
}



Subject::Subject(const std::string& line){
  std::stringstream sline(line);
  std::string info;
  std::getline(sline,info,',');
  id=std::stoi(info);
  int i=1;
  while(std::getline(sline,info,' ')){
  std::getline(sline,info,',');
    ++i;
    switch(i){
      case 2: name=info; break;
      case 3: ects=std::stoi(info); break;
      case 4: abberv=info; break;
    }
}
}

//Ina Saltovic
Subject::Subject(unsigned int ID, std::string& ime, unsigned int ECTS, std::string& ABBERV) : id{ID}, name{ime}, ects{ECTS}, abberv{ABBERV} {}

void Subject::print()const{
  std::cout<<id<<" "<<name<<" "<<ects<<" "<<abberv<<" "<<year<<" "<<semester<<" "<<std::endl;
}
//Vedad Mešić
void Subject::debug_print()const{
  std::cout<<id<<" "<<name<<" "<<ects<<" "<<abberv<<" "<<year<<" "<<semester<<" "<<department<<" Teachers: ";
  for(auto el : teachers)
    std::cout<<el<<" ";
  std::cout<<std::endl;
}
Department::Department(const std::string& line){
  std::stringstream sline(line);
  std::string info; 
  std::getline(sline,info,',');
  id=std::stoi(info);
  std::getline(sline,info,' ');
  std::getline(sline,info,',');
  name=info;
}

//Ina Saltovic
Department::Department(unsigned int ID, std::string& ime) : id{ID}, name{ime} {}

void Department::print()const{
  std::cout<<id<<" "<<name<<std::endl;
}
//Vedad Mešić
void Department::debug_print()const{
  std::cout<<id<<""<<name<<" Subjects:";
  for(auto el : subjects)
    std::cout<<el<<" ";
  std::cout<<std::endl;
}
