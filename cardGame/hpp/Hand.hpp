#ifndef H_HAND
#define H_HAND

#include <list>
#include <iostream>

#include "CanAddPile.hpp"
#include "CardContainer.hpp"

using namespace std;

template <typename T>
class Hand : public CanAddPile<T> {

private:
  list<T> myHand ;

public:

  Hand(){}

  virtual void add(T &x){
    myHand.push_front(x);
  }


  virtual void add(CardContainer<T> c){
    for(int i = 0; i < c.getSize(); i++)
      myHand.push_front (c.getElement(i));
  }

  CardContainer<T> remove(int position){
    if(position< myHand.size()){
      typename list<T>::iterator it1 = myHand.begin();
      typename list<T>::iterator it2;

      advance (it1,position);
      it2=it1;
      myHand.erase(it1);
      return CardContainer<T>(*it2);
    }
    throw 4;
  }

  void putInOrder(int tab[], int size){
    int tmp=0;
    for(int i = 1; i < size; i++) {
      for(int j=0; j < size - 1; j++)  {
	if(tab[j]<tab[i]){
	  tmp = tab[i];
	  tab[i] = tab[j];
	  tab[j] = tmp;
	}
      }
    }
  }

  CardContainer<T> remove(int *position, int size){
    int j=0;
    bool flag= true;
    T* tabCard;
    typename list<T>::iterator it1 ;
    putInOrder(position, size);
    for(int i =0; i<size; i++){
      it1= myHand.begin();
      if(position[i]< myHand.size()){
	if(flag){
	  tabCard = new T[size-i];
	  flag=false;
	}
	advance (it1,position[i]);
	tabCard[j]=*it1;
	j++;
	myHand.erase(it1);
      }
    }
    return CardContainer<T>(tabCard, j);
  }

  CardContainer<T> remove(T &x){
    typename list<T>::iterator itCurrent = myHand.begin();
    typename list<T>::iterator itEnd = myHand.end();

    while(itCurrent != itEnd){
      if( x==*itCurrent){
	myHand.erase(itCurrent);
	return CardContainer<T>(x);
      }
      else
	itCurrent++;
    }
    cout << x << " not found" << endl;
    throw ;
  }

  CardContainer<T> remove(T*x, int size){
    T* tabCard = new T[size];
    for(int i=0; i<size; i++){

      tabCard[i]= (remove(x[i]));
    }
    return CardContainer<T>(tabCard, size);
  }

  void printHand(){
    typename list<T>::iterator itCurrent = myHand.begin();
    typename list<T>::iterator itEnd = myHand.end();
    while(itCurrent != itEnd){
      cout << (*itCurrent) << " ";
      itCurrent++;
    }
    cout << endl;
  }

  void isEmpty(){
    myHand.empty();
  }
};

#endif
