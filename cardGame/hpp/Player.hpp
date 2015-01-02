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

  void ask(Action<T>& action){
    int n;
    cout << "Quelle(s) carte(s) jouer ?" << endl;
    hand.printHand();
    cin >> n;
    action.setFrom(&hand, hand.remove(n));
  }

  void add(T& card){
    hand.add(card);
  }
};

#endif
