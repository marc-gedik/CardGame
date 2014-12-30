#ifndef H_HAND
#define H_HAND

#include <list>

#include "Card.hpp"

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

  void add(T *xs, int size){
    for(int i = 0; i < size; i++)
      myHand.push_front (xs[i]);
  }

  void remove(int position){
    typename list<T>::iterator it = myHand.begin();
    if(position< myHand.size()){
      advance (it,position);
      myHand.erase(it);
    }
  }

  void printHand(){
    cout<<"taille : " << myHand.size()<<endl;
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
