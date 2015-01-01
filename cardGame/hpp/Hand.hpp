#ifndef H_HAND
#define H_HAND
#include <list>
#include "Card.hpp"
#include "CardContainer.hpp"
using namespace std;


template <typename T>
class Hand {

private:
  list<T> myHand ;

public:

  Hand(){}

  void add(T &x){
    myHand.push_front(x);
  }


  void add(CardContainer<T> c, int nbCard){
    for(int i = 0; i < nbCard; i++)
      myHand.push_front (c.getElement(i));
  }

  
  T* remove(int position){
    typename list<T>::iterator it1 = myHand.begin();
    typename list<T>::iterator it2;
    if(position< myHand.size()){
      advance (it1,position);
      it2=it1;
      myHand.erase(it1);
      return &(*it2);
    }
    else{
      return NULL;
    }
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

 
  T* remove(int *position, int size){
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
    return tabCard;
  }
  

 
   


   T* remove(T &x){
    typename list<T>::iterator itCurrent = myHand.begin();
    typename list<T>::iterator itEnd = myHand.end();
        

    while(itCurrent != itEnd){
      if( x==*itCurrent){
	myHand.erase(itCurrent);
	return &x;
      }
      else
	itCurrent++;
    }
    return NULL;
  }
   

  T* remove(T*x, int size){
    T* tabCard = new T[size];
    for(int i=0; i<size; i++){
      tabCard[i]= *(remove(x[i]));
      cout<<"coucou"<<endl;
      //tabCard[i]print);
      }
    return tabCard;
    
  }
  
  void printHand(){
    //  cout<<"taille : " << myHand.size()<<endl;
    typename list<T>::iterator itCurrent = myHand.begin();
    typename list<T>::iterator itEnd = myHand.end();
    while(itCurrent != itEnd){
      cout << (*itCurrent) << " ";
      itCurrent++;
    }
    cout << endl;
  }
    
};

#endif
