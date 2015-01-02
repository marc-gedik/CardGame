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

  T* removeAll(){
    int size=myDiscardPile.size();
    T* tabCard = new T[size];

    for(int i=0; i<size; i++){
      tabCard[i]=myDiscardPile.top();
      myDiscardPile.pop();
    }
    return tabCard;
  }

  void print(){
    if(myDiscardPile.size()==0)
      cout<<"Pile vide"<<endl;
    stack<T> tmp = myDiscardPile;

    while(!tmp.empty()){
      cout << tmp.top() << " ";
      tmp.pop();
    }
    cout<<endl;
  }
};

#endif
