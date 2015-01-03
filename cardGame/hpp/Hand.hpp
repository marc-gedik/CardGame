#ifndef H_HAND
#define H_HAND

#include <list>
#include <iostream>

#include "CanAddRemovePile.hpp"
#include "CardContainer.hpp"

using namespace std;

template <typename T>
class Hand : public CanAddRemovePile<T> {

private:
  list<T> myHand ;

public:

  Hand(){}

  virtual void add(CardContainer<T> c){
    for(int i = 0; i < c.getSize(); i++)
      myHand.push_front (c.getElement(i));
  }

  // T'es sur de ça ?
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
