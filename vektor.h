//Dino Music
#pragma once
#include<algorithm>
#include<iterator>
#include<initializer_list>
#include<stdexcept>

template<typename T>
class vektor
{
  private:
    int size_, allocSize_;
    T* elements_;
    void realloc();

  public:
    vektor() : size_{0},allocSize_{10},elements_{new T[allocSize_]}{}
    vektor(int,const T&);
    vektor(const std::initializer_list<T>&);
    ~vektor();
    vektor& push_back(const T&);
    T& at(int);
    T& operator[](int i){return elements_[i];};
    const T& operator[](int i) const {return elements_[i];}
    int size() const {return size_;}
    class iterator;
    iterator begin() {return iterator(elements_);}
    iterator end() {return iterator(elements_+size_);}
    void operator=(vektor&&);
};

template<typename T>
void vektor<T>::realloc()
{
  allocSize_+=allocSize_/2;
  T* temp=new T[allocSize_];
  std::copy(elements_,elements_+size_,temp);
  delete[] elements_;
  elements_=temp;
}

template<typename T>
vektor<T>::vektor(int size,const T& element):size_{size},allocSize_{2*size},elements_{new T[allocSize_]}
{
  for(int i=0;i<size_;++i)
    elements_[i]=element;
}

template<typename T>
vektor<T>::vektor(const std::initializer_list<T> &lista):size_(lista.size()),allocSize_{2*size_},elements_{new T[allocSize_]}
{
  std::copy(lista.begin(),lista.end(),elements_);
}

template<typename T>
vektor<T>::~vektor()
{
  delete[] elements_;
}

template<typename T>
vektor<T>& vektor<T>::push_back(const T& element)
{
  elements_[size_++]=element;
  if(size_==allocSize_)
    realloc();
  return *this;
}

template<typename T>
T& vektor<T>::at(int i)
{
  if(i>size_-1)
    throw std::out_of_range("Indeks ne postoji u vektoru.");
  return elements_[i];
}

template<typename T>
class vektor<T>::iterator : public std::iterator<std::random_access_iterator_tag,T>
{
  private:
    T* elemp_;
  
  public:
    iterator(T* elemp):elemp_{elemp}{}
    T& operator*(){return *elemp_;}
    bool operator==(const iterator& other){return elemp_==other.elemp_;}
    bool operator!=(const iterator &other){return elemp_!=other.elemp_;}
    bool operator>(const iterator &other){return elemp_>other.elemp_;}
    bool operator>=(const iterator &other){return elemp_>=other.elemp_;}
    bool operator<(const iterator &other){return elemp_<other.elemp_;}
    bool operator<=(const iterator &other){return elemp_<=other.elemp_;}
    iterator& operator++() {++elemp_; return *this;}
    iterator operator++(int) {iterator temp=*this; ++elemp_; return temp;}
    iterator& operator--() {--elemp_; return *this;}
    iterator operator--(int) {iterator temp=*this; elemp_--; return temp;}
    iterator& operator+(int i){elemp_+=i; return *this;}
    iterator& operator-(int i){elemp_-=i; return *this;}
};

template<typename T>
void vektor<T>::operator=(vektor &&other)
{
  allocSize_=other.allocSize_;
  size_=other.size_;
  elements_=other.elements_;
  other.allocSize_=0;
  other.size_=0;
  other.element_=nullptr;
}

