#include <iostream>
#include "Hand.hpp"
#include "Card.hpp"

using namespace std;

Hand::Hand(){
  cout << " -- Nouvelle liste vide --" << endl;
                         
}


void Hand::addCard(Card &c){
  myHand.push_front(&c);
}

void Hand::addCards(Card *c[], int size){
  //for(int i =0; i<size; i++)
    // myHand.push_front (&c[i]);
}

void Hand::printHand(){
  cout<<"taille : " << myHand.size()<<endl;
  list<Card*>::iterator itCurrent = myHand.begin();
  list<Card*>::iterator itEnd = myHand.end();
  while(itCurrent != itEnd){
    cout <<" carte :: ";
    (*itCurrent)->printCard();
    itCurrent++;
  }
}

void Hand::removeCard(int position){
  list<Card*>::iterator it1 = myHand.begin();
  if(position< myHand.size()){
    advance (it1,position);
    myHand.erase(it1);
  }
}
