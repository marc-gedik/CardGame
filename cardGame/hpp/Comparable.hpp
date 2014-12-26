#ifndef H_COMPARABLE
#define H_COMPARABLE

class Comparable {
public:
  virtual bool operator< (const Comparable&) = 0;
  virtual bool operator<=(const Comparable&) = 0;
  virtual bool operator==(const Comparable&) = 0;
  virtual bool operator> (const Comparable&) = 0;
  virtual bool operator>=(const Comparable&) = 0;
};

#endif
