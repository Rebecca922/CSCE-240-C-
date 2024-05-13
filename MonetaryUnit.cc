// Copyright 2024 Jiarong Xu
// implement Monetary Unit Class functionality
#include"MonetaryUnit.h"
#include<iostream>
using std::ostream;
// constructor implementation
MonetaryUnit :: MonetaryUnit(string name, string symbol, double amount):
                             _unit_name("US dollars"), _unit_symbol("$"),
                             _unit_amount(1.0) {
  SetName(name);
  SetSymbol(symbol);
  SetAmountEquivalentTo1Dollar(amount);
                             }
bool MonetaryUnit::SetName(string name) {
  if ( name.length() >= 1 ) {
    _unit_name = name;
    return true;
  } else {
      return false;
  }
}
bool MonetaryUnit::SetSymbol(string symbol) {
  if ( symbol.length() >= 1 ) {
    _unit_symbol = symbol;
    return true;
  } else {
      return false;
  }
}
bool MonetaryUnit::SetAmountEquivalentTo1Dollar(double amount) {
  if ( amount > 0.0 ) {
    _unit_amount = amount;
    return true;
  } else {
      return false;
  }
}
bool operator==(const MonetaryUnit& one, const MonetaryUnit& two) {
    return (one.GetAmountEquivalentTo1Dollar()
            == two.GetAmountEquivalentTo1Dollar()
            && one.GetName() == two.GetName() &&
    one.GetSymbol() == two.GetSymbol());  //  overloading
}

