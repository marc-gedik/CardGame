#ifndef H_ITALIAN_RANK
#define H_ITALIAN_RANK

enum ItalianRank {
  Ace = 1,
  Deuce,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Fante,
  Cavallo,
  Re
};

std::ostream& operator<<(std::ostream&, const ItalianRank&);

extern ItalianRank italianRanks[];
extern int nbrItalianRank;

#endif
