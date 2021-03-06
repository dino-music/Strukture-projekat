//Dino Music
#pragma once
#include"linkedlist.h"
#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>

template<typename T>
class API
{
  protected:
    unsigned int capacity_;
    linkedlist<T> *api_;
    std::string file_;

  public:
    API(unsigned int c):capacity_{c},api_{new linkedlist<T>[capacity_]}{}
    API():API(113u){};
    ~API();
    void open(std::string);
    void push(unsigned int,const T&);
    typename linkedlist<T>::iterator find(unsigned int);
    bool is_present(unsigned int);
    //void remove(const T&);
    bool remove(unsigned int);
    template<typename F>
    void for_each(F);
    typename linkedlist<T>::iterator end(){return api_[0].end();}
    void printone(unsigned int,std::string);
    void printall(std::string);
    void Update(std::string);
};

//Harun Muderizovic
template<typename T>
void API<T>::open(std::string fileName)
{
    std::fstream file(fileName);
    try
    {
        if(!file)
            throw std::domain_error("\nFile not available!\n\n");
    }
    catch(std::exception& x)
    {
        std::cout << x.what();
    }
    file_=fileName;
    std::string line;
    std::getline(file,line);

    while(std::getline(file,line))
    {
      try
      {
        T temp(line);
        push(temp.getId(),temp);
      }
      catch(std::exception& x)
      {
        std::cout << x.what();
      }
    }
  
    file.close();
}


template<typename T>
void API<T>::push(unsigned int key, const T& item)
{
  api_[key%capacity_].push_back(item);
}

//Gr8 utility metod
template<typename T>
typename linkedlist<T>::iterator API<T>::find(unsigned int key)
{
  //lambda funkcija za find metod linkane liste koji omogucava da se clanovi pretrazuju samo
  //po ID-u bez potrebe za kreiranje kompletnih objekata tipa student, ili profesor koji bi se 
  //koristili za poredjenje
  auto lambda=[](const T& a, unsigned int b)->bool{return a.getId()==b;};
  return api_[key%capacity_].template find<unsigned int>(key,lambda);
}

//Metod za provjeru da li je neki objekta u tablici ili ne, koji mogu koristit eksterne strukture za brzi lookup
template<typename T>
bool API<T>::is_present(unsigned int key)
{
  auto it=find(key);
  if(it==api_[0].end())
    return false;
  else 
    return true;
}

//Otklanja element iz tablice koji se podudara sa proslijedjenim ID-em
template<typename T>
bool API<T>::remove(unsigned int key)
{
  auto lambda=[](const T& a, unsigned int b)->bool{return a.getId()==b;};
  return api_[key%capacity_].template remove<unsigned int>(key,lambda);
}

template<typename T>
API<T>::~API()
{
  //poziva se destruktor za svaku listu unutar niza, pa se dealocira niz
  for(auto i=0u;i<capacity_;++i)
    api_[i].~linkedlist<T>();
  delete[] api_;
}

//Za izvodjenje neke promjene ili primjene nekog metoda nad svim objektima u tablici
//Za individualne objekte postoji find metod
template<typename T>
template<typename F>
void API<T>::for_each(F lambda)
{
  for(auto i=0u;i<capacity_;++i)
  {
    auto e=api_[i].end();
    for(auto it=api_[i].begin();it!=e;++it)
      lambda(*it);
  }
}

template<typename T>
void API<T>::printone(unsigned int key,std::string obj)
{
  auto it=find(key);
  if(it==end())
    std::cout<<"Nije pronadjen "<<obj<<" sa kljucem "<<key<<std::endl;
  else
    (*it).print_fancy();
}

template<typename T>
void API<T>::printall(std::string header)
{
  std::cout<<header<<std::endl;
  std::cout<<std::string(header.size(),'-')<<std::endl;
  for_each([](const T& a){a.print();});
  std::cout<<std::endl;
}

//Vedad Mešić
template <typename T>
void API<T>::Update(std::string header){
  std::ofstream file;
 file.open(file_);
 file<<header<<std::endl;
  auto lambda=[&](T& b){b.file_output(file);};
  for_each(lambda);
}

