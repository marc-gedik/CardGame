#ifndef H_CARDCONTAINER
#define H_CARDCONTAINER

#include "Card.hpp"
using namespace std;

template <typename T>
class CardContainer {


private:
  T tabCards[512]; // on suppose la taille suffisante
  int indice;

public:

  CardContainer(){}
  
  CardContainer(T* xs, int nbCard){
    indice=nbCard;
    for (int i=0; i<nbCard; i++){
      tabCards[i]=xs[i];
    }
  }

  int getIndice(){
    return indice;
  }

  T* getTabCards(){
    return tabCards;
  }

  T getElement(int i){
    return tabCards[i];
  }
  
};
#endif
