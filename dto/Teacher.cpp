#include"Teacher.h"
#include"utility_functions.h"

//Emina Mahmutbegovic
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
Teacher::Teacher(unsigned int ID, const std::string& ime, const std::string& prezime, const std::string& datum, const std::string& mail, char spol, const std::string& JMBG, unsigned int depID, const std::string& titula) : Student{ID, ime, prezime, datum, mail, spol, JMBG, depID}, title{titula} {}

//Ina Saltovic
void Teacher::file_output(std::ofstream& fajl){
  const std::string c = ", ";
  fajl << id << c << firstName << c << lastName << c << birthDate << c << email << c << gender << c << jmbg << c << title << c << depId << std::endl;
}

void Teacher::print()const{
   std::cout<<id<<", "<<firstName<<", "<<lastName<<", "<<birthDate<<", "<<email<<", "<<gender<<", "<<
    jmbg<<", "<<title<<", "; 
}

void Teacher::print_fancy(std::string dep)const{
  std::cout<<"ID: "<<id<<std::endl;
  std::cout<<"Ime, prezime: "<<firstName<<", "<<lastName<<std::endl;
  std::cout<<"Datum rodjenja: "<<birthDate<<std::endl;
  std::cout<<"E-mail: "<<email<<std::endl;
  std::cout<<"Spol: "<<gender<<std::endl;
  std::cout<<"JMBG: "<<jmbg<<std::endl;
  std::cout<<"Titula: "<<title<<std::endl;
  std::cout<<"Odsjek: "<<dep<<std::endl;
  std::cout<<std::endl;
}
//Vedad Mešić
void Teacher::debug_print()const{
   std::cout<<id<<" "<<firstName<<" "<<lastName<<" "<<birthDate<<" "<<email<<" "<<gender<<" "<<
    jmbg<<" "<<title<<" "<<depId<<" "<<std::endl<<" Subjects: ";
   for(auto el: subjects)
     std::cout<<el<<" ";
   std::cout<<std::endl<<std::endl;
}
