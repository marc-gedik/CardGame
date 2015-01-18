#include "Players.hpp"

#include "Human.hpp"

Players::Players(int n, bool humans, int ord)
  : nbPlayers(n), actual(0), order(ord){
  players = new Player *[n];

  players[0] = new Human();
  for(int i = 1; i < n; i++)
    if(humans)
      players[i] = new Human();
  // else
}

Player& Players::next(){
  actual = (actual + order) % nbPlayers;
  return *players[actual];
}

Player& Players::getActualPlayer(){
  return *players[actual];
}

void Players::reverseOrder(){
  order = -order;
}

int Players::getNbPlayers(){
  return nbPlayers;
}

int Players::getActualPlayerId(){
  return actual;
}

void Players::setActualPlayer(int i){
  if(i>=0 && i < nbPlayers)
    actual = i;
}

void Players::eliminer(int player){
  for(int i = player; i < nbPlayers-1; i ++)
    players[i] = players[i+1];
  nbPlayers--;
}

void Players::ask(Action& action, int what){
  cout << "Player " << actual << " : ";
  players[actual]->ask(action, what);
}

void Players::addTo(int i, Card& card){
  players[i]->add(card);
}

void Players::add(Card& card){
  players[actual]->add(card);
}


void Players::addTo(int i, const CardContainer& cards){
  players[i]->add(cards);
}

void Players::discardTo(int i, CardContainer& cards){
  players[i]->discard(cards);
}

void Players::discardTo(CardContainer cards){
  players[actual]->discard(cards);
}

bool Players::emptyHand(int i){
  return players[i]->emptyHand();
}
