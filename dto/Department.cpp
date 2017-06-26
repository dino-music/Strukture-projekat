#include"Department.h"
#include"utility_functions.h"

Department::Department(const std::string& line){
  std::stringstream sline(line);
  std::string info; 
  std::getline(sline,info,',');
  id=std::stoi(info);
  std::getline(sline,info,' ');
  std::getline(sline,info,'\r');
  name=info;
}

//Ina Saltovic
Department::Department(unsigned int ID, const std::string& ime) : id{ID}, name{ime} {}

//Ina Saltovic
void Department::file_output(std::ofstream& fajl){
  const std::string c = ", ";
  fajl << id << c << name << std::endl;
}

void Department::print()const{
  std::cout<<id<<", "<<name<<std::endl;
}

void Department::print_fancy()const{
  std::cout<<"ID: "<<id<<std::endl;
  std::cout<<"Ime: "<<name<<std::endl;
  std::cout<<std::endl;
}
//Vedad Mešić
void Department::debug_print()const{
  std::cout<<id<<" "<<name<<std::endl<<" Subjects:";
  for(auto el : subjects)
    std::cout<<el<<" ";
  std::cout<<std::endl<<std::endl;
}
