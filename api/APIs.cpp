//Dino Music
#include"APIs.h"

std::string studentapi::getDep(unsigned int key)//Emina
{
  auto it=departmentAPI->find(key);//pronadjemo department sa adekvatnim ID-em
  return (*it).getName();//vracamo ime departmenta
}

//Emina
void departmentapi::addSubject(unsigned int depID,unsigned int subID,const std::string& name,unsigned int ects,
    const std::string& abb,const std::string& year,const std::string& semester){
  if(is_present(depID)){
    auto it=find(depID);
    if(!subjectAPI->is_present(subID))
    {
      Subject temp(subID,name,ects,abb);
      temp.setYear(year);
      temp.setSemester(semester);
      temp.setDepartment(depID);
      subjectAPI->push(subID,temp);
      (*it).addSubject(subID);
    }else
      std::cout<<"Postoji predmet sa id: "<<subID<<std::endl;
  }else 
    std::cout<<"Nije pronadjen department sa kljucem: "<<depID<<std::endl;
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

void studentapi::getById(unsigned int key)
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

void teacherapi::getById(unsigned int key)
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

    std::string temp="ID, Ime, Prezime, Datum rodjenja, E-mail, Spol, JMBG, Odsjek";
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

void subjectapi::getTeachers(unsigned int key)
{
  auto it=find(key);
  if(it==end())
  {
    std::cout<<"Nije pronadjen predmet sa kljucem "<<key<<std::endl;
    return;
  }

  std::string temp="ID, Ime, Prezime, Datum rodjenja, E-mail, Spol, JMBG, Titula, Odsjek";
  std::cout<<temp<<std::endl;
  std::cout<<std::string(temp.size(),'-')<<std::endl;
  for(auto const &i:(*it).getTeachers())
  {
    auto it=teacherAPI->find(i);
    (*it).print();
    std::cout<<teacherAPI->getDep((*it).getDepId())<<std::endl;
  }
  std::cout<<std::endl;
}

//Emina Mahmutbegovic
void departmentapi::saveDep(unsigned int id, const std::string& name){
  if(is_present(id))
    std::cout<<"Department sa kljucem "<<id<<" vec postoji."<<std::endl;
  else
  push(id,Department(id,name));

}

//Harun Muderizovic
void departmentapi::getSubjects(unsigned int id, subjectapi& subj)
{
  auto it = find(id); //ispitivanje da li odsjek postoji
  if(it == end())
  {
    std::cout << "Nije pronadjen odsjek sa id-om " << id << std::endl;
    return;
  }
  
  std::cout << "Odsjek: " << (*it).getName() << std::endl << "Predmeti na odsjeku: ";
  std::list<unsigned int> lista = (*it).getSubjectList(); //dohvata listu id-a predmeta sa odsjeka
  int zarez = 0;
  for(auto s : lista) // za svaki clan liste (id) ispisuje ime predmeta
  {
    auto sIT = subj.find(s);
    if(sIT != subj.end())
      std::cout << (*sIT).getName();
    else
      std::cout << "Predmet obrisan";
    if(++zarez != lista.size()) //izbjegavanje zareza poslije zadnjeg clana
      std::cout << ", ";
  }

  std::cout << '.' << std::endl << std::endl;
}



