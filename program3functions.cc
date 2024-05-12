//  Copyright 2024 Jiarong Xu
#include<iostream>
#include<iomanip>
#include"p3compares.h"
#include"program3functions.h"
using std::ispunct;
using std::tolower;
using std::cout;

void RemoveValues(int array[], int size, int value) {
  for (int i = 0; i < size; ++i) {
    if (array[i] == value) {
      array[i] = -999;  //  replace
      for (int j = i; j < size - 1 && array[j+1] != -999; ++j) {  // swap
        int temp = array[j+1];
        array[j+1] = array[j];
        array[j] = temp;
        }
        --i;  //  check the new swap value
      }
    }
  }
void ShiftArray(int array[], int size, int moving) {
  if (moving >= size) {
    moving -= size;
    }
  if (moving >= 0) {  //  moving to the right
    for (int j = 1; j <= moving; ++j) {  //  move whatever times
      // move once
      int temp = array[0];  // save array[0]
      for (int i = 1; i < size; ++i) {
        array[i-1] = array[i];
        }
      array[size-1] = temp;
      }
    } else {
        for (int j = -1; j >= moving; --j) {  //  move whatever times
          // move once
          int temp = array[size-1];  // save array[0]
          for (int i = size -2; i >= 0; --i) {
            array[i+1] = array[i];
            }
          array[0] = temp;
          }
        }
  }
int CountLetters(const char a1[]) {
  int count = 0;
  int counttotal = 0;
  for (int i = 0; a1[i] != '\0'; ++i) {
    ++counttotal;
    if (a1[i] == ' ' || ispunct(a1[i])) {
      ++count;
      }
  }
  return counttotal - count;
}
void GetLetterArray(const char a1[], char la1[], int size1) {
  int j = 0;
  for (int i = 0; a1[i] != '\0'; ++i) {
    if (a1[i] != ' ' && !ispunct(a1[i])) {
      la1[j] = a1[i];
      ++j;
      }
    }
  la1[size1-1] = '\0';
  }
bool EqualIgnoreCase(const char c1, const char c2) {
  char lc1 = tolower(c1);
  char lc2 = tolower(c2);
  return lc1 == lc2;
  }
bool IsAnagram(const char a1[], const char a2[], bool CaseMatter) {
  if (a1 == nullptr && a2 == nullptr) {
    return true;
    }
  //  find the size of the pure letters
  int size1 = CountLetters(a1)+1;
  int size2 = CountLetters(a2)+1;
  //  get the pure letters array
  char la1[size1];
  char la2[size2];
  GetLetterArray(a1, la1, size1);
  GetLetterArray(a2, la2, size2);
  if (size1 != size2) {
    //  cout << size1 << size2;
    return false;  //  check the size
    }
  for (int i = 0; i < size1; ++i) {
    for (int j = 0; j < size2; ++j) {
      //  cout << i << la1[i] << j << la1[j];
      if (CaseMatter) {
        //  cout << "case";
        if (la1[i] == la2[j]) {
        //  cout << la2[j];
          la2[j] = '-';
        //  cout << la2[j];
          break;
          }
        } else {
          //  cout << "non case";
          if (EqualIgnoreCase(la1[i], la2[j])) {
            la2[j] = ' ';
            break;
            }
          }
        if (j == size1 - 1) {
        //  cout << "false";
          return false;
          }
      }
    }
  return true;
}
bool Replace1With2(char a1[], int size, char value,
                   char replace1, char replace2) {
  int counttotal = 0;  // use to check how many is it now
  int count = 0;  //  use to check how many need to be replace
  for (int i = 0; a1[i] != '\0'; ++i) {
    ++counttotal;
    if (a1[i] == value) {
      ++count;
      }
    }
  int lenth = counttotal + count;
  //  cout << "ct " << counttotal << " c " << count << " lenth " << lenth;
  if (lenth >= size) {
  //  cout << "ct " << counttotal << " c " << count << " lenth " << lenth;
    return false;
  }
  for (int i = 0; i < size; ++i) {
    if (a1[i] == value) {
      a1[i] = replace1;
      for (int j = size - 1; j > i + 1; --j) {
        a1[j] = a1[j-1];
      }
      a1[i+1] = replace2;
    }
  }
  return true;
}
void SwapRowsAndColumns(int a1[][kSquareSize]) {
  int a2[kSquareSize] [kSquareSize];
  for (int i = 0; i < kSquareSize; ++i) {
    for (int j = 0; j < kSquareSize; ++j) {
      a2[i][j] = a1[i][j];
    }
  }
  for (int i = 0; i < kSquareSize; ++i) {
    for (int j = 0; j < kSquareSize; ++j) {
      a1[i][j] = a2[j][i];
      }
    }
}
