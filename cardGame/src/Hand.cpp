#include <iostream>
#include "Hand.hpp"

using namespace std;

Hand::Hand(){
  cout << " -- Nouvelle liste vide " << endl;
                         
}


void Hand::addCard(int c){
  myHand.push_front (c);
}


void Hand::addCards(int c[], int size){
  for(int i =0; i<size; i++)
    myHand.push_front (c[i]);
}

void Hand::printHand(){
  cout<<"taille : " << myHand.size();
  list<int>::iterator itCurrent = myHand.begin();
  list<int>::iterator itEnd = myHand.end();
  while(itCurrent != itEnd){
    cout <<" carte :: "<< *itCurrent << endl;
    itCurrent++;
  }
}

void Hand::removeCard(int position){
  list<int>::iterator it1 = myHand.begin();
  if(position< myHand.size()){
    advance (it1,position);
    myHand.erase(it1);
  }
}
