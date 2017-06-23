#include"objekti.h"
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
    case 5: email=info; break;
    case 6: gender=info[0]; break;
    case 7: jmbg=info; break;
    case 8: depId=stoi(info); break; 

  }
  }
}

void Student::print()const{
  std::cout<<id<<" "<<firstName<<" "<<lastName<<" "<<birthDate<<" "<<email<<" "<<gender<<" "<<
    jmbg<<" "<<depId<<" "<<std::endl;

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
    case 5: email=info; break;
    case 6: gender=info[0]; break;
    case 7: jmbg=info; break;
    case 8: title=info; break;
    case 9: depId=stoi(info); break;
  }
  }  
}

void Teacher::print()const{
   std::cout<<id<<" "<<firstName<<" "<<lastName<<" "<<birthDate<<" "<<email<<" "<<gender<<" "<<
    jmbg<<" "<<title<<" "<<depId<<" "<<std::endl; 
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

void Subject::print()const{
  std::cout<<id<<" "<<name<<" "<<ects<<" "<<abberv<<" "<<year<<" "<<semester<<std::endl;
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

void Department::print()const{
  std::cout<<id<<""<<name<<std::endl;
}
