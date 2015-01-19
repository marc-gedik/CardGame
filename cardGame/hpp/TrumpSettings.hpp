#ifndef H_TRUMP_SETTINGS
#define H_TRUMP_SETTINGS

#include <iostream>
#include <map>

#include "Settings.hpp"
#include "Card.hpp"

class TrumpSettings : public Settings {
protected:
  int trump;
  std::map<int, int> values;

  int get(const Card&) const;
public:
  void setTrump(int);
  void setValue(int, int);

  virtual int compare(const Card&, const Card&) const;

};

#endif
