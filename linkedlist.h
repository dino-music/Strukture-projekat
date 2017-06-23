//Dino Music
#pragma once
#include<iterator>
#include<functional>

template<typename T>
struct node
{
  T val;
  node *next_;
  node(const T &v):val{v},next_{nullptr}{}
};

template<typename T>
class linkedlist
{
  private:
    node<T> *first_;
    node<T> *last_;
    unsigned int size_;

  public:
    linkedlist():first_{nullptr},last_{nullptr},size_{0u}{}
    linkedlist(const linkedlist&);
    linkedlist(linkedlist&&);
    ~linkedlist();
    //linkedlist& operator=(const linkedlist&);
    linkedlist& operator=(linkedlist&&);
    linkedlist& push_back(const T&);
    class iterator;
    template<typename V>
      iterator find(const V&,std::function<bool (const T&,const V&)>);
    template<typename V>
      bool remove(const V&,std::function<bool (const T&,const V&)> f);
    iterator find(const T& v){return find<T>(v,[](const T &a,const T&b)->bool{return a==b;});}
    //compiler uspjesno implicitno zakljuci tip za prvi parametar metoda, ali ne prepoznaje taj tip unutar parametara 
    //function objekta pa se mora pozivati sa eksplicitno zadanim tipom. 
    bool remove(const T& v){return remove<T>(v,[](const T &a,const T& b)->bool{return a==b;});}
    unsigned int size(){return size_;}
    iterator begin(){return iterator(first_);}
    iterator end(){return iterator(nullptr);}
};

template<typename T>
linkedlist<T>::~linkedlist()
{
    node<T>* temp;
    while(first_!=nullptr)
    {
      temp=first_;
      first_=first_->next_;
      delete temp;
    }
}

template<typename T>
linkedlist<T>& linkedlist<T>::push_back(const T& element)
{
  if(size_==0)
  {
    first_=new node<T>(element);
    last_=first_;
  }
  else
  {
    last_->next_=new node<T>(element);
    last_=last_->next_;
  }
  ++size_;
  return *this;
}

//Genericki find metod, omogucava da u API klasi preko lambde vrsimo pretrazivanje po kljucu 
template<typename T>
template<typename V>
typename linkedlist<T>::iterator linkedlist<T>::find(const V& val,std::function<bool (const T&,const V&)> f)
{
  linkedlist<T>::iterator b=begin(), e=end();
  while(b!=e)
  {
    if(f(*b,val))
      break;
    ++b;
  }
  return b;
}

//Vrijedi isto kao i za find metod, vraca bool cisto radi komocije, da se moze utvrditi je li uopste bilo objekta koji
//se zelio brisati
template<typename T>
template<typename V>
bool linkedlist<T>::remove(const V& val,std::function<bool (const T&,const V&)> f)
{

  if(size_==0)
    return false;

  node<T> *previous=first_, *current=first_;
  while(current!=nullptr)
  {
    if(f(current->val,val))
      break;
    previous=current;
    current=current->next_;
  }


  node<T>* temp;
  if(current==first_)
  {
    temp=first_;
    first_=first_->next_;
    delete temp;
  }
  else if(current==last_)
  {
    temp=last_;
    last_=previous;
    last_->next_=nullptr;
    delete temp;
  }
  else
  {
    temp=current;
    previous->next_=current->next_;
    delete temp;
  }
  --size_;
  return true;
}

//vanilla iterator, nista posebno
template<typename T>
class linkedlist<T>::iterator:public std::iterator<std::forward_iterator_tag,T>
{
  private:
    node<T>* elemp;
  public:
    iterator(node<T>* p):elemp{p}{}
    T& operator*(){return elemp->val;}
    iterator& operator++(){elemp=elemp->next_;return *this;}
    iterator operator++(int)
    {
      iterator temp=*this;
      elemp=elemp->next_;
      return temp;
    }
    bool operator!=(const iterator &a){return elemp!=a.elemp;}
    bool operator==(const iterator &a){return elemp==a.elemp;}
};

template<typename T>
linkedlist<T>::linkedlist(const linkedlist &lista):size_{lista.size_}
{
  first_=new node<T>(lista.first_->val);
  last_=first_;
  node<T>* temp=lista.first_->next_;
  while(temp!=nullptr)
  {
    last_->next_=new node<T>(temp->val);
    last_=last_->next_;
    temp=temp->next_;
  }
}

template<typename T>
linkedlist<T>::linkedlist(linkedlist &&lista):size_{lista.size_},first_{lista.first_},last_{lista.last_}
{
  lista.first_=nullptr;
  lista.last_=nullptr;
}

template<typename T>
linkedlist<T>& linkedlist<T>::operator=(linkedlist &&other)
{
  first_=other.first_;
  last_=other.last_;
  size_=other.size_;
  other.size_=0;
  other.first_=nullptr;
  other.last_=nullptr;
}
