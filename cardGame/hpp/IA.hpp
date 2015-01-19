#ifndef H_IA
#define H_IA

#include "Player.hpp"

class IA : public Player {
private:
  int cpt;
public:
  virtual void ask(CardAction&, int, int request=0);
  virtual void ask(Question&, int, int request=0);
};

#endif
