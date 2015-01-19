#ifndef H_SETTINGS
#define H_SETTINGS


class Card;

class Settings {
public:
  virtual int compare(const Card&, const Card&) const = 0;
};

#endif
