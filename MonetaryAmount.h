// Copyright Jiarong Xu
// define the MonetaryAmount class
#ifndef _MONETARYAMOUNT_H_
#define _MONETARYAMOUNT_H_
#include"MonetaryUnit.h"
#include<iostream>
#include<string>
using std::ostream;
using std::string;
class MonetaryAmount {
  //  overload:
friend bool operator == (const MonetaryAmount& one, const MonetaryAmount& two);
friend bool operator < (const MonetaryAmount& one, const  MonetaryAmount& two);
friend bool operator > (const MonetaryAmount& one, const  MonetaryAmount& two);
friend ostream& operator << (ostream& out, const MonetaryAmount& m);
friend MonetaryAmount operator + (const MonetaryAmount& one,
                                  const MonetaryAmount& two);
 public:
  //  constructor
  explicit MonetaryAmount(double value = 0.0, const MonetaryUnit& =
                          MonetaryUnit("US dollars", "$", 1.0));
  double GetValue() const { return _value; }
  MonetaryUnit GetUnit() const { return _unit; }
  void ConvertToUnit(const MonetaryUnit&);
  static bool display_unit_name;
  bool setValue(double);
  bool setUnit(const MonetaryUnit&);

 private:
  double _value;
  MonetaryUnit _unit;  // composition
};
#endif
