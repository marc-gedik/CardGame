#ifndef H_PLAYER
#define H_PLAYER

#include "Hand.hpp"
#include "Action.hpp"

#include <iostream>
using namespace std;

template <typename T>
class Player {
private:
  Hand<T> hand;
public:
  Player(){}

  // Todo Demander plusieurs cartes
  void ask(Action<T>& action){
    int size;
    int n;
    cout << "Quelle(s) carte(s) jouer ?" << endl;
    hand.printHand();
    cin >> n;

    size = 1;
    int* pos = new int[size];
    pos[0] = n;
    action.setFrom(&hand, pos, size);
  }

  void add(T& card){
    hand.add(card);
  }

  void add(CardContainer<T> card){
    hand.add(card);
  }

  void emptyHand(){
    return hand.isEmpty();
  }
};

#endif
