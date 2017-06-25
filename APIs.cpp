//Dino Music
#include"APIs.h"

void studentapi::getAll()
{
  std::string header="ID, Ime, Prezime, Rodjendan, E-mail, spol, JMBG, Odsjek";
  std::cout<<header<<std::endl<<std::string(header.size(),'-')<<std::endl;

  auto lambda=[=](const Student&a){
    auto it=departmentAPI->find(a.getDepId());//pronadjemo Department sa adekvatnim ID-em
    std::string dep=(*it).getName();//Dohvatimo naziv departmenta koji smo maloprije pronasli
    a.Print(dep);//pozovemo Print metod sa dohvacenim nazivom
  };

  for_each(lambda);
  std::cout<<std::endl;
}

void teacherapi::getAll()
{
  {
  std::string header="ID, Ime, Prezime, Rodjendan, E-mail, spol, JMBG, Titula, Odsjek";
  std::cout<<header<<std::endl<<std::string(header.size(),'-')<<std::endl;

  auto lambda=[=](const Teacher&a){
    auto it=departmentAPI->find(a.getDepId());
    std::string dep=(*it).getName();
    a.Print(dep);
  };

  for_each(lambda);
  std::cout<<std::endl;
}
