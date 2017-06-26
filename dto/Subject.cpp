#include"Subject.h"
#include"utility_functions.h"

Subject::Subject(const std::string& line){
  std::stringstream sline(line);
  std::string info;
  std::getline(sline,info,',');
  id=std::stoi(info);
  std::getline(sline,info,' ');
  std::getline(sline,info,',');
  name=info;
  std::getline(sline,info,' ');
  std::getline(sline,info,',');
  ects=std::stoi(info); 
  std::getline(sline,info,' ');
  std::getline(sline,abberv,'\r');
}

//Ina Saltovic
Subject::Subject(unsigned int ID, const std::string& ime, unsigned int ECTS, const std::string& ABBERV) : id{ID}, name{ime}, ects{ECTS}, abberv{ABBERV} {}

//Ina Saltovic 
void Subject::file_output(std::ofstream& fajl){
  const std::string c = ", ";
  fajl << id << c << name << c << ects << c << abberv << std::endl;
}


void Subject::print()const{
  std::cout<<id<<", "<<name<<", "<<ects<<", "<<abberv<<", "<<year<<" "<<semester<<std::endl;
}

void Subject::print_fancy()const{
  std::cout<<"ID: "<<id<<std::endl;
  std::cout<<"Ime: "<<name<<std::endl;
  std::cout<<"ECTS krediti: "<<ects<<std::endl;
  std::cout<<"Skracenica: "<<abberv<<std::endl;
  std::cout<<"Godina: "<<year<<std::endl;
  std::cout<<"Semestar: "<<semester<<std::endl;
  std::cout<<std::endl;
}

//Vedad Mešić
void Subject::debug_print()const{
  std::cout<<id<<" "<<name<<" "<<ects<<" "<<abberv<<" "<<year<<" "<<semester<<" "<<department<<std::endl<<" Teachers: ";
  for(auto el : teachers)
    std::cout<<el<<" ";
  std::cout<<std::endl<<" Students: ";
  for(auto el : students)
    std::cout<<el<<" ";
  std::cout<<std::endl<<std::endl;
}
//Vedad Mešić
void Subject::file_outputST(std::ofstream& fajl){
  for(auto& el: teachers)
    fajl<<id<<", "<<el<<std::endl;
}
void Subject::file_outputDS(std::ofstream& fajl){
    fajl<<department<<", "<<id<<", "<<year<<", "<<semester<<std::endl;
}
