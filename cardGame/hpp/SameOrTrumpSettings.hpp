#ifndef H_SAME_OR_TRUMP_SETTINGS
#define H_SAME_OR_TRUMP_SETTINGS

#include "TrumpSettings.hpp"

class SameOrTrumpSettings : public TrumpSettings {
public:
  virtual int compare(const Card&, const Card&) const;

};

#endif
