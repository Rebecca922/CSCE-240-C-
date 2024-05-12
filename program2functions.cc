//  Copyright 2024 Jiarong Xu
#include"program2functions.h"
#include<iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::stoi;
using std::abs;
bool IsPrime(int num) {
  if (num < 2) {
    return false;
    }
  bool found_di = false;  //  use to record result + record 2
  for (int i = 2; i < num && !found_di; ++i) {  // 2 is not in loop
    found_di = (num % i)== 0;  //  cleaner
    }
  return !found_di;  //  return !found divisor
  }
int ToClosestPrime(int num) {
    bool found_P = false;
  for (int i = 0; !found_P; ++i) {
    if (IsPrime(num+i)) {
      return i;  //  do not need to change found_P to true
      } else {
          if (IsPrime(num-i)) {
            return -i;  //  auto return the value and stop the function
            }
          }
    }
    return -1;  //  if find nothing
  }
//  incorrect
void PrintPrimesBetween(int low, int up, bool In_Range) {
  bool first = true;
  for (int i = low + (In_Range ? 0 : 1); i <= up - (In_Range ? 0 : 1); ++i) {
    if (IsPrime(i)) {  //  check is prime
        if (first) {
          first = false;
        } else {
            cout << ", ";  //  print "," before started at the second one
        }
      cout << i;
      }
    }
  }
int LargestPrimeSequence(int num) {
  string num_s = to_string(num);
  int l_Prime = -1;  //. set up
  for (int i=0; i < num_s.size(); ++i) {  //  where is starts
    for (int j=1; j <= (num_s.size()-i); ++j) {  //  for how long
      string sub_str = num_s.substr(i, j);
      int sub_num = stoi(sub_str);
      if (IsPrime(sub_num)) {
        if (sub_num > l_Prime) {  //  check prime
          l_Prime = sub_num;  //  check max
          }
        }
      }
    }
  return l_Prime;
}
void PrintAsDollarsAndCents(int num) {
  int dollar = num / 100;  //  dollar value
  int cent = num % 100;  //  cent value
  char dime;
  //  cent>=10 ? dime = '\0' : dime = '0'; why this one not working?
  if (cent < 10) {
    dime = '0';
    cout << "$" << dollar << "." << dime << cent;
  } else {
      cout << "$" << dollar << "." << cent;
  }
}
char Closest(int c) {
  int a1[7] = {2000, 1000, 500, 100, 25, 10, 5};  //  set up array
  char a2[7] = {'w', 't', 'f', 'o', 'q', 'd', 'n'};
  int min = 2000;
  int index = -1;
  for (int i = 0; i < 7; ++i) {
    int diff = a1[i] - c;  //  finding the differnce
    if (diff < 0) {
      continue;
    }
    if (diff < min) {
      min = diff;
      index = i;
      }
    }
  if (index == -1) {
    return 'p';
  } else {
      return a2[index];
  }
}
void dect(int& start, int& reminder, int (&a3)[8]) {
  int a1[8] = {2000, 1000, 500, 100, 25, 10, 5, 1};  //  set up array
  while (a3[start] > 0 && reminder >= a1[start]) {
        reminder -= a1[start];
        --a3[start];
}
  if (a3[start] == 0 && reminder >= a1[start+1]) {  //  pass a3
    start += 1;
    dect(start, reminder, a3);
  }
}
bool MakePurchase(int c, int& w, int& t, int& f,
                  int& o, int& q, int& d, int& n, int& p) {
  int total_c = 2000 * w + 1000 * t + 500 * f +
                100 * o + 25 * q + 10 * d + 5 * n + p;
  int reminder = c;
    int a1[8] = {2000, 1000, 500, 100, 25, 10, 5, 1};  //  set up array
    char a2[8] = {'w', 't', 'f', 'o', 'q', 'd', 'n', 'p'};
    int a3[8] = {w, t, f, o, q, d, n, p};  //  value array
    int start = 0;  //  the first un-zero value
  if (total_c > c) {
    for (int j = 0; j < 8; ++j) {
      if (a3[j] == 0) {
        continue;
      }
      start = j;  //  the first un-zero va4lue
      break;
    }
  dect(start, reminder, a3);
    int change = 0;
    for (int i = 0; i < 8 && reminder > 0; ++i) {
      if (Closest(reminder) == a2[i]) {
        if (a3[i] > 0) {
        change = a1[i] - reminder;
        a3[i] -= 1;
        } else {
        for (int j = i - 1; j > 0 && a3[j+1] == 0; --j) {
        if (a3[j] > 0) {
          change = a1[j] - c;
          a3[j] -= 1;
          break;
        }
        }
        }
        for (int a = 0; a < 8; ++a) {
          a3[a] += change / a1[a];
          change %= a1[a];
        }
        a3[7] += change;
      }
    }
    w = a3[0];
    t = a3[1];
    f = a3[2];
    o = a3[3];
    q = a3[4];
    d = a3[5];
    n = a3[6];
    p = a3[7];
    return true;
  } else {
      if (total_c == c) {
        w = t = f = o = q = d = n = p = 0;
        return true;
        } else {
            return false;
            }
       }
  }
