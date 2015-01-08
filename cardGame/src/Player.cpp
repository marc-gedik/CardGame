#include "Player.hpp"

#include <iostream>
using namespace std;


void Player::add(Card& card){
  hand.add(card);
}

void Player::add(const CardContainer& card){
  hand.add(card);
}

bool Player::emptyHand(){
  return hand.isEmpty();
}
