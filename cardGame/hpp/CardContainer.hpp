#ifndef H_CARD_CONTAINER
#define H_CARD_CONTAINER

template <typename T>
class CardContainer {
private:
  T* tabCards;
  int size;

public:

  CardContainer(){}

  CardContainer(T* xs, int nbCard){
    size = nbCard;
    tabCards = new T[size];
    for (int i=0; i<nbCard; i++)
      tabCards[i]=xs[i];
  }

  CardContainer(T& x){
    size = 1;
    tabCards = new T[size];
    tabCards[0] = x;
  }

  int getSize(){
    return size;
  }

  T* getTabCards(){
    return tabCards;
  }

  T& getElement(int i){
    return tabCards[i];
  }
};
#endif
