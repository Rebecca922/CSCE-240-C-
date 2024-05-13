// Copyright Jiarong Xu
// define the MonetaryUnit class
#ifndef _MONETARYUNIT_H_
#define _MONETARYUNIT_H_

#include<iostream>
#include<string>
using std::ostream;
using std::string;

class MonetaryUnit{
  friend bool operator == (const MonetaryUnit& one, const MonetaryUnit& two);
 public:
  explicit MonetaryUnit(string name = "US dollars",
                        string symbol = "$", double amount = 1.0);
  bool SetName(string);
  string GetName() const { return _unit_name; }
  bool SetSymbol(string);
  string GetSymbol() const { return _unit_symbol; }
  bool SetAmountEquivalentTo1Dollar(double);
  double GetAmountEquivalentTo1Dollar() const { return _unit_amount; }
 private:
  string _unit_name;
  string _unit_symbol;
  double _unit_amount;
  // static int _conversion_factor;
};
#endif
