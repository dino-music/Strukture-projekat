//Ina Saltovic
#include "utility_functions.h"

bool isValid_mail(std::string mail){
  int position1 = mail.find("."); //pronalazenje pozicije prve tacke u mail-u
  int position2 = mail.find("@"); //pronalazenje pozicije znaka @ u mailu
  int position3 = mail.find(".", position1+1); //pronalazenje pozicije druge tacke u mail-u
  //ako su pronadjene 2 tacke i znak @ i ako je prva tacka prije znaka @ a druga tacka nakon znaka @, to znači da je 
  //mail dobar ukoliko nemamo još jednu tacku u mailu
  if(position1!=-1 && position2!=-1 && position3!=-1 && position2 > position1 && position2 < position3){
    int positionX = mail.find(".", position3+1);
    if(positionX==-1) //provjeravanje postoji li jos jedna tacka u mail-u, ukoliko ne postoji mail je validan
      return true;
  }
  return false; //u suprotnom nije validan
}

bool isValid_jmbg(std::string jmbg){
  if(jmbg.size()!=13) return false; //ukoliko jbmg sadrzi vise od 13 elemenata, nije validan
  std::vector<int> JMBG;
  for(int i = 0; i < jmbg.size(); i++)
    JMBG.push_back(jmbg[i]-'0'); //pretvaranje char-ova u int-ove i stavljanje u vektor

  //formula za racunanje kontrolnog(zadnjeg) broja jbmg-a
  int m = ((7*(JMBG[0]+JMBG[6]) + 6*(JMBG[1]+JMBG[7]) + 5*(JMBG[2]+JMBG[8]) + 4*(JMBG[3]+JMBG[9]) + 3*(JMBG[4]+JMBG[10]) + 2*(JMBG[5]+JMBG[11])) % 11);
  //uslijed postojanja dva nacina za racunanje kontrolnog broja, moraju se provjeriti obje mogucnosti
  int n=m;
  if(n>1)
    n=11-n;
  if(m>9)
    m=0;
  return m==JMBG[12] || n==JMBG[12];
}


//Harun Muderizovic
void SubjTeach(subjectapi& subj, teacherapi& teach, const std::string& fileName)
{
  std::fstream file(fileName);
  std::string line; 
  unsigned int sID, tID;
  char zarez;
  std::stringstream ss;
  std::getline(file,line); // prva linija u fajlu

  while(getline(file,line)) // za ostale linije
  {
    ss << line;

    ss >> sID >> zarez >> tID;
    
    auto itSUB = subj.find(sID);
    auto itTEA = teach.find(tID);
    // ako objekti postoje
    if(itSUB != subj.end() && itTEA != teach.end())
    {  
      (*itSUB).addTeacher(tID);
      (*itTEA).addSubject(sID);
    }

  }
  
  file.close();
}
