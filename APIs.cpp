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
    }
  std::cout<<std::endl;
}



