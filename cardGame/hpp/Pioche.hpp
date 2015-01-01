#ifndef H_PIOCHE
#define H_PIOCHE
#include <stack>
#include "Card.hpp"
#include "CardContainer.hpp"
using namespace std;


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


  T* toPioche(){
    T* tmp=  &(myPioche.top());
    myPioche.pop();
    return tmp;
  }
    
};

#endif
