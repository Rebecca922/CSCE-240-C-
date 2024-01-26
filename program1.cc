// Copyright 2024 Jiarong Xu
#include<iostream>
#include<iomanip>
using std::cout;
using std::endl;
using std::cin;
int m, d, y;  // beginning balence
int m1, d1, y1;  // different transaction
int m0, d0, y0;  // the 30th date
int m2, d2, y2;  // save the previous date
int l, l1, d_o_m;  // use to tell length
double n_b, o_b, v, avg, sum, od;  //  for the balence cal
bool islep = false;
bool b = false;  // check more than 30 days or not & for chron check
bool boo = false;  // check after or not;
int len(int mm, int dm, int ym, int m1m, int d1m, int y1m);
int d_m(int mm);
int lep(int ym);
int date(int mm, int dm, int ym);
int chrono(int mm, int dm, int ym, int m1m, int d1m, int y1m);
int main() {
  char dc, op1, op2;
  avg = 0;
  cin >> m >> op1 >> d >> op2 >> y >> n_b;
  sum = 0;  // the default value
  date(m, d, y);
  for (int i = 0; !b; ++i) {  //  looping until 30 days
    // need to check chronological or not
    cin >> dc >> m1 >> op1 >> d1 >> op2 >> y1 >> v;
    if (i > 0) {
      chrono(m2, d2, y2, m1, d1, y1);
      if (!boo) {
        cout << "Entries must be provided in chronological order.\n"
             << m1 << "/" << d1 << "/" << y1 << " entered after "
             << m2 << "/" << d2 << "/" << y2 << endl;
        return 0;
        }
      boo = false;
      }
     if (i == 0) {
       m2 = d2 = y2 = 0;
       }
    chrono(m0, d0+1, y0, m1, d1, y1);  //  when the input is exactly the 30 day
    // assign the input date is after the 30 days or not
    if (boo) {
      len(m2, d2, y2, m0, d0, y0);
      sum += l * n_b;  // the last few days balence
      l1 = 30;
      b = true;
      break;
      } else {
          // save the previous date to compare with the new dates
          o_b = n_b;
          switch ( dc ) {  // check debit or credit
            case 'd' :
              od = n_b - v;
              n_b -= v;
              if (od < 0) {
                n_b -= 15;
                cout << "Overdraft on " << m1 << "/" << d1
                     << "/" << y1 << ". $15 overdraft fee assessed." << endl;
                }
              break;
            case 'c' :
              n_b += v;
              break;
            case 'q' :
              m0 = m1;
              d0 = d1;
              y0 = y1;  // will print out on the quit date
              len(m, d, y, m2, d2, y2);
              l1 = l;
              b = true;  // stop the program
              sum += n_b;
              avg = sum/l1;
              cout << std::setprecision(2)
                   << std::setiosflags(std :: ios::fixed);
              cout << l <<"-day average balance (" << m << "/" << d << "/"
                   << y << "-" << m0 << "/" << d0
                   << "/" << y0  << "): $" << avg << endl;
              return 0;
            }
        if (i > 0) {
          len(m2, d2, y2, m1, d1, y1);
          } else {
              len(m, d, y, m1, d1, y1);
              }
        sum += (l - 1) *  o_b;
        m2 = m1;
        d2 = d1;
        y2 = y1;
    }
    }
  avg = sum/l1;
  cout << std::setprecision(2)
       << std::setiosflags(std :: ios::fixed);
  cout <<"30-day average balance (" << m << "/" << d << "/"
       << y << "-" << m0 << "/" << d0 << "/" << y0  << "): $" << avg << endl;
  return 0;  // for potential debugging
  }
// what length it is between days
int len(int mm, int dm, int ym, int m1m, int d1m, int y1m) {
  if (mm == 0 || m1m == 0) {  //  the first one is over 30 days
    l = 30;
    } else {
        if (y1m > ym) {
          d_m(mm);
          l = d1m + d_o_m - dm + 1;
          } else {
              if (m1m > mm) {
                d_m(mm);
                l = d1m + d_o_m - dm +1;
                } else {
                    l = d1m - dm + 1;
                    }
              }
         }
  return 0;
  }
// how many days in this month
int d_m(int mm) {
  switch (mm) {
    case 4:
    case 6:
    case 9:
    case 11:
      d_o_m = 30;
      break;
    case 2:
      lep(y);
      islep ? d_o_m = 29 : d_o_m = 28;  // feb days
      break;
    default:
      d_o_m = 31;
      break;
    }
  return 0;
  }
// lep year or not
int lep(int ym) {
  if (ym % 400 == 0) {
    islep = true;
    } else {
        if (ym % 100 != 0 && ym % 4 == 0) {
          islep = true;
          }
        }
  return 0;
  }
// get the 30th date
int date(int mm, int dm, int ym) {
  d0 = dm + 29;
  m0 = mm;
  y0 = ym;
  d_m(mm);
  if (d0 > d_o_m) {
    m0 += 1;
    d0 -= d_o_m;
    if (m0 > 12) {
      m0 = 1;
      y0 += 1;
      }
    }
  return 0;
  }
// check is after or same or not
int chrono(int mm, int dm, int ym, int m1m, int d1m, int y1m) {
  if (y1m > ym) {
    boo = true;
    } else if (y1m == ym) {
        if (m1m > mm) {
          boo = true;
          } else if (m1m == mm) {
              if (d1m >= dm) {
                boo = true;
                }
              }
        }
  return 0;
  }
