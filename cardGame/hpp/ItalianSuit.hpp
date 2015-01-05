#ifndef H_ITALIAN_SUIT
#define H_ITALIAN_SUIT

enum ItalianSuit {
  Spade,
  Bastoni,
  Denari,
  Coppe
};

std::ostream& operator<<(std::ostream&, const ItalianSuit&);

extern ItalianSuit italianSuits[];
extern int nbrItalianSuits;

#endif
