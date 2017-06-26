//Dino Music
#include"APIs.h"

std::string studentapi::getDep(unsigned int key)//Emina
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

//emina mahmutbegovic
void studentapi::changeLastName(unsigned int id,const std::string& newName){
  if(is_present(id)){
    auto it=find(id);
    (*it).setLastName(newName);
  }else
    std::cout<<"Nije pronadjen student sa id: "<<id<<std::endl;
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

//Emina Mahmutbegovic
void teacherapi::changeLastName(unsigned int id,const std::string& newName){
  if(is_present(id)){
    auto it=find(id);
    (*it).setLastName(newName);
  }else
    std::cout<<"Nije pronadjen teacher sa id: "<<id<<std::endl;
}

//Emina Mahmutbegovic
void teacherapi::changeTitle(unsigned int id,const std::string& newName){
  if(is_present(id)){
    auto it=find(id);
    (*it).setTitle(newName);
  }else
    std::cout<<"Nije pronadjen teacher sa id: "<<id<<std::endl;
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

//Harun Muderizovic
void subjectapi::saveSubject(unsigned int id, const std::string& name, unsigned int ects, const std::string& abbre)
{
  if(is_present(id))
    std::cout << "Predmet sa id-om " << id <<" vec postoji." << std::endl;
  else
    push(id,Subject(id,name,ects,abbre));
}

void subjectapi::connectSubjDep(unsigned int subjID, unsigned int depID)
{
  //ispitivanje da li predmet i odsjek postoje
  auto sIT = find(subjID);
  auto dIT = (*departmentAPI).find(depID);
  if(sIT == end())
  {
    std::cout << "Predmet sa id-om " << subjID << " ne postoji u bazi" << std::endl;
    return;
  }
  if(dIT == (*departmentAPI).end())
  {
    std::cout << "Odsjek sa id-om " << depID << " ne postoji u bazi" << std::endl;
    return;
  }
  //provjeravanje da li je predmet na drugom odsjeku
  unsigned int depa = (*sIT).getDep();
  if(depa != 0)
    std::cout << "Predmet je vec povezan sa departmentom " << depa << std::endl;
  else //ako nije
  {
    (*sIT).setDepartment(depID);
    (*dIT).addSubject(subjID);
    std::cout << "Uspjesno povezano!" << std::endl << std::endl;
  }
}

void subjectapi::removeSubject(unsigned int id)
{
  //prvo ispitujemo da li predmet uopste postoji
  auto ITsubj = find(id);
  if(ITsubj == end())
  {
    std::cout << "Predmet sa id-om " << id << " ne postoji u bazi" << std::endl;
    return;
  }

  //uklanjamo ga sa odsjeka
  unsigned int depID = (*ITsubj).getDep();
  if(depID != 0) // ako je povezan sa odsjekom
  {
    auto ITdep = (*departmentAPI).find(depID);
    (*ITdep).getSubjectList().remove(id);
  }

  //uklanjamo ga kod profesora
  for(auto t : (*ITsubj).getTeachers())
  {
    auto ITteach = (*teacherAPI).find(t);
    (*ITteach).getSubjects().remove(id);
  }

  //uklanjamo ga kod studenata
  for(auto s : (*ITsubj).getStudents())
  {
    auto ITstud = (*studentAPI).find(s);

    for(auto e : (*ITstud).getExams())
    {
      if(e.subjectId == id && e.evaluation < 6)
      {
        (*ITstud).getExams().remove(e);
        break;
      }
    }
  }

  //na kraju uklanjamo predmet iz liste predmeta
  remove(id); 
}


//Emina Mahmutbegovic
//dodaje novog profesora na predmet subID
void subjectapi::addTeacher(unsigned int subID,unsigned int tID,const std::string& name,const std::string& last,
    const std::string& bdate, const std::string& mail,char gender,const std::string& jmbg,unsigned int depID,const std::string& title){
  if(is_present(subID)){
    if(!teacherAPI->is_present(tID)){
      Teacher temp(tID,name,last,bdate,mail,gender,jmbg,depID,title);
      temp.addSubject(subID);
      teacherAPI->push(tID,temp);
      auto it=find(subID);
      (*it).addTeacher(tID);
    }else
      std::cout<<"Vec postoji teacher sa id: "<<tID<<std::endl;
  }else
    std::cout<<"Ne postoji predmet sa id: "<<subID<<std::endl;
}



//Emina Mahmutbegovic
//dodavanje novog departmenta
void departmentapi::saveDep(unsigned int id, const std::string& name){
  if(is_present(id))
    std::cout<<"Department sa kljucem "<<id<<" vec postoji."<<std::endl;
  else
  push(id,Department(id,name));

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



//Harun Muderizovic
void departmentapi::getSubjects(unsigned int id)
{
  auto it = find(id); // ispitivanje da li odsjek postoji
  if(it == end())
  {
    std::cout << "Nije pronadjen odsjek sa id-om " << id << std::endl;
    return;
  }
  
  std::cout << "Odsjek: " << (*it).getName() << std::endl << "Predmeti na odsjeku: ";
  std::list<unsigned int> lista = (*it).getSubjectList(); // dohvatanje liste id-eva
  int zarez = 0;
  for(auto s : lista) // prolazak kroz listu i ispisivanje predmeta pomocu njihovog id-a
  {
    auto sIT = (*subjectAPI).find(s);
    if(sIT != (*subjectAPI).end())
      std::cout << (*sIT).getName();
    else
      std::cout << "Predmet obrisan";
    if(++zarez != lista.size())
      std::cout << ", ";
  }

  std::cout << '.' << std::endl << std::endl;
}

//Vedad Mešić
//metod za brisanje departmenta, gdje prolazi kroz subjecte i trazi profesore i studente koji su na tom departmentu da ih izbrise
void departmentapi::removeDep(unsigned int ID){
  auto it=find(ID);
  if(it==end())
    std::cout<<"Nema tog ID-a"<<std::endl;
  else{
    for(auto& el : (*it).getSubjects()){
      auto it2=subjectAPI->find(el);
      if(it2!=subjectAPI->end()){
        for(auto& item : (*it2).getTeachers()){
          auto it3=subjectAPI->teacherAPI->find(item);
          if( it3!=subjectAPI->teacherAPI->end() && (*it3).getDepId()==ID){
            subjectAPI->teacherAPI->remove((*it3).getId());
          }
        } 
        for(auto& item : (*it2).getStudents()){
          auto it3=subjectAPI->studentAPI->find(item);
          if( it3!=subjectAPI->studentAPI->end() && (*it3).getDepId()==ID){
            subjectAPI->studentAPI->remove((*it3).getId());
          }
        }
      subjectAPI->remove(el);
      }
    }
  remove(ID);
  }

}

