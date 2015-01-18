#ifndef H_SETTINGS
#define H_SETTINGS

#include "Card.hpp"

class Settings {
  friend class Card;
public:
  virtual int compare(const Card&, const Card&) = 0;
};

#endif
