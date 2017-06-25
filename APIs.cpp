//Dino Music
#include"APIs.h"

std::string studentapi::getDep(unsigned int key)
{
  auto it=departmentAPI->find(key);//pronadjemo department sa adekvatnim ID-em
  return (*it).getName();//vracamo ime departmenta
}

void studentapi::getAll()
{
  std::string header="ID, Ime, Prezime, Datum rodjenja, E-mail, Spol, JMBG, Odsjek";
  std::cout<<header<<std::endl;
  std::cout<<std::string(header.size(),'-')<<std::endl;
  auto lambda=[=](const Student &a){
    a.print();
    std::cout<<getDep(a.getDepId())<<std::endl;
  };
  for_each(lambda);
  std::cout<<std::endl;
}

void studentapi::getOne(unsigned int key)
{
  auto it=find(key);
  if(it==end())
    std::cout<<"Nije pronadjen student sa kljucem "<<key<<"."<<std::endl;
  else
  {
    std::string dep=getDep((*it).getDepId());
    (*it).print_fancy(dep);
  }
}






std::string teacherapi::getDep(unsigned int key)
{
  auto it=departmentAPI->find(key);//pronadjemo department sa adekvatnim ID-em
  return (*it).getName();//vracamo ime departmenta
}

void teacherapi::getAll()
{
  std::string header="ID, Ime, Prezime, Datum rodjenja, E-mail, Spol, JMBG, Titula, Odsjek";
  std::cout<<header<<std::endl;
  std::cout<<std::string(header.size(),'-')<<std::endl;
  auto lambda=[=](const Teacher &a){
    a.print();
    std::cout<<getDep(a.getDepId())<<std::endl;
  };
  for_each(lambda);
  std::cout<<std::endl;
}

void teacherapi::getOne(unsigned int key)
{
  auto it=find(key);
  if(it==end())
    std::cout<<"Nije pronadjen profesor sa kljucem "<<key<<"."<<std::endl;
  else
  {
    std::string dep=getDep((*it).getDepId());
    (*it).print_fancy(dep);
  }
}


void subjectapi::getStudents(unsigned int key)
{
  auto it=find(key);
  if(it==end())
  {
    std::cout<<"Nije pronadjen predmet sa kljucem "<<key<<std::endl;
    return;
  }

    std::string temp="ID, Ime, Prezime, Datum rodjenja, E-mail, Spol, JMBG, Titula, ID odsjeka";
    std::cout<<temp<<std::endl;
    std::cout<<std::string(temp.size(),'-')<<std::endl;
    for(auto const& i:(*it).getStudents())//prolazimo kroz listu studenata koji slusaju predmet, i ispisujemo
    {
      auto it=studentAPI->find(i);
      (*it).print();
      std::cout<<studentAPI->getDep((*it).getDepId())<<std::endl;
    }
  std::cout<<std::endl;
}




