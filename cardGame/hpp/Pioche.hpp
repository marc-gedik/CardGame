#ifndef H_PIOCHE
#define H_PIOCHE

#include <stack>

#include "CardContainer.hpp"

template <typename T>
class Pioche {

private:
  stack<T> myPioche ;

public:
  Pioche(){}

  void createPioche(CardContainer<T> c, int nbCard){
    for(int i = 0; i < nbCard; i++)
      myPioche.push(c.getElement(i));
  }

  T& draw(){
    T tmp =  myPioche.top();
    myPioche.pop();
    return tmp;
  }
};

#endif
