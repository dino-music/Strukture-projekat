//Dino Music
#pragma once
#include<iterator>

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
    //linkedlist& operator=(linkedlist&&);
    linkedlist& push_back(const T&);
    class iterator;
    iterator find(const T&);
    bool remove(const T&);
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

template<typename T>
typename linkedlist<T>::iterator linkedlist<T>::find(const T& val)
{
  linkedlist<T>::iterator b=begin(), e=end();
  while(b!=e)
  {
    if(*b==val)
      break;
    ++b;
  }
  return b;
}

template<typename T>
bool linkedlist<T>::remove(const T& val)
{

  if(size_==0)
    return false;

  node<T> *previous=first_, *current=first_;
  while(current!=nullptr)
  {
    if(current->val==val)
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
