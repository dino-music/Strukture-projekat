//Dino Music
#include"APIs.h"

void studentapi::getOne(unsigned int key)
{
  auto it=find(key);
  if(it==end())
  {
    std::cout<<"Nije pronadjen student sa kljucem "<<key<<"."<<std::endl;
    return;
  }

    auto i=departmentAPI->find((*it).getDepId());//pronadjemo Department sa adekvatnim ID-em
    std::string dep=(*i).getName();//Dohvatimo naziv departmenta koji smo maloprije pronasli
    (*it).print_fancy(dep);

}

void teacherapi::getOne(unsigned int key)
{
  auto it=find(key);
  if(it==end())
  {
    std::cout<<"Nije pronadjen profesor sa kljucem "<<key<<"."<<std::endl;
    return;
  }

    auto i=departmentAPI->find((*it).getDepId());//pronadjemo Department sa adekvatnim ID-em
    std::string dep=(*i).getName();//Dohvatimo naziv departmenta koji smo maloprije pronasli
    (*it).print_fancy(dep);

}



