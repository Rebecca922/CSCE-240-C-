// Copyright 2024 Jiarong Xu
// implement Monetary Amnount Class functionality
#include"MonetaryAmount.h"
#include<iostream>
using std::ostream;
using std::cout;

bool MonetaryAmount::display_unit_name = false;


// constructor implementation
MonetaryAmount :: MonetaryAmount(double value, const MonetaryUnit& unit):
                                 _value(0.0), _unit(unit) {
  setValue(value);
                                 }
bool MonetaryAmount::setValue(double value) {
  if ( value >0 ) {
    _value = value;
    return true;
  } else {
    return false;
  }
}
bool MonetaryAmount::setUnit(const MonetaryUnit& unit) {
  _unit = unit;
  return true;
}

void MonetaryAmount::ConvertToUnit(const MonetaryUnit& unit) {
  double newV;
  if (MonetaryAmount::GetUnit() == unit) {
    return;
  }
  if (unit.GetSymbol() != "$") {
    newV = MonetaryAmount::GetValue() *
                unit.GetAmountEquivalentTo1Dollar();
  } else {
    //  cout << MonetaryAmount::GetValue();
    //  cout << MonetaryAmount::GetUnit().GetName();
    //  cout << MonetaryAmount::GetUnit().GetAmountEquivalentTo1Dollar();
    newV = MonetaryAmount::GetValue() /
           MonetaryAmount::GetUnit().GetAmountEquivalentTo1Dollar();
      }
  MonetaryAmount::setValue(newV);
  MonetaryAmount::setUnit(unit);
}
bool operator == (const MonetaryAmount& one, const MonetaryAmount& two) {
  double v1 = one.GetValue() / one.GetUnit().GetAmountEquivalentTo1Dollar();
  double v2 = two.GetValue() / two.GetUnit().GetAmountEquivalentTo1Dollar();
  return (v1 == v2);
}
bool operator > (const MonetaryAmount& one, const MonetaryAmount& two) {
  double v1 = one.GetValue() / one.GetUnit().GetAmountEquivalentTo1Dollar();
  double v2 = two.GetValue() / two.GetUnit().GetAmountEquivalentTo1Dollar();
  return (v1 > v2);
}
bool operator < (const MonetaryAmount& one, const MonetaryAmount& two) {
  double v1 = one.GetValue() / one.GetUnit().GetAmountEquivalentTo1Dollar();
  double v2 = two.GetValue() / two.GetUnit().GetAmountEquivalentTo1Dollar();
  return (v1 < v2);
}
ostream& operator << (ostream& out, const MonetaryAmount& m) {
  if ( MonetaryAmount::display_unit_name ) {
    out << m.GetValue() << " " << m.GetUnit().GetName();
    } else {
        out << m.GetUnit().GetSymbol() << m.GetValue();
    }
  return out;
}
MonetaryAmount operator + (const MonetaryAmount& one,
                           const MonetaryAmount& two) {
  double v2 = two.GetValue() / two.GetUnit().GetAmountEquivalentTo1Dollar()
              //  conver to dollow
              * one.GetUnit().GetAmountEquivalentTo1Dollar();
  double value = one.GetValue() + v2;
  MonetaryAmount newM(value, one.GetUnit());
  return newM;
}
/*
bool operator == (const MonetaryAmount& one, const MonetaryAmount& two) {
  //  converting all to dollor
  MonetaryUnit unit("US dollars", "$", 1.0);  //  converting to the same unit
  one.ConvertToUnit(unit);  
  two.ConvertToUnit(unit);  
  return (one.GetValue() == two.GetValue());
}
bool operator < (MonetaryAmount& one, MonetaryAmount& two) {
  MonetaryUnit unit("US dollars", "$", 1.0);  //  converting to the same unit
  one.ConvertToUnit(unit);  
  two.ConvertToUnit(unit);  
  return (one.GetValue() < two.GetValue());
}
bool operator > (MonetaryAmount& one, MonetaryAmount& two) {
  MonetaryUnit unit("US dollars", "$", 1.0);  //  converting to the same unit
  one.ConvertToUnit(unit);  
  two.ConvertToUnit(unit);  
  return (one.GetValue() > two.GetValue());
}
MonetaryAmount operator + (MonetaryAmount& one, MonetaryAmount& two) {  
  two.ConvertToUnit(one.GetUnit());  
  double value = one.GetValue() + two.GetValue();
  MonetaryAmount newM(value,one.GetUnit());
  return newM;
}
*/
