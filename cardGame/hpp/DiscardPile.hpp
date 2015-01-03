#ifndef H_DISCARDPILE
#define H_DISCARDPILE

#include <stack>

#include "Card.hpp"
#include "CardContainer.hpp"
#include "CanAddPile.hpp"

using namespace std;

template <typename T>
class DiscardPile : public CanAddPile<T>{

private:
  stack<T> myDiscardPile ;

public:

  DiscardPile(){}

  virtual void add(T &x){
    myDiscardPile.push(x);
  }

  virtual void add(CardContainer<T> c){
    for(int i = 0; i < c.getSize(); i++)
      myDiscardPile.push(c.getElement(i));
  }


  T& removeTop(){
    T& tmp = myDiscardPile.top();
    myDiscardPile.pop();
    return tmp;
  }

  CardContainer<T> removeAll(){
    int size=myDiscardPile.size();
    T* tabCard = new T[size];

    for(int i=0; i<size; i++){
      tabCard[i]=myDiscardPile.top();
      myDiscardPile.pop();
    }
    return CardContainer<T>(tabCard, size);
  }

  T& look(){
    return myDiscardPile.top();
  }

  ostream& print(ostream&os){
    if(myDiscardPile.size()==0)
      return os << "Pile vide";
    else
      return os << myDiscardPile.top();
    // stack<T> tmp = myDiscardPile;

    // while(!tmp.empty()){
    //   os << tmp.top() << " ";
    //   tmp.pop();
    // }
    return os;
  }

  friend ostream& operator<<(ostream& os, DiscardPile<T> x){
    return x.print(os);
  }
};

#endif
