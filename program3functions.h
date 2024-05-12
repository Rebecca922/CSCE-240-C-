//  Copyright 2024 Jiarong Xu
#ifndef _PROGRAM3FUNCTIONS_H_
#define _PROGRAM3FUNCTIONS_H_
#include"p3compares.h"
void RemoveValues(int array[], int size, int value);

void ShiftArray(int array[], int size, int moving);

int CountLetters(const char a1[]);

void GetLetterArray(const char a1[], char la1[], int size1);

bool EqualIgnoreCase(const char c1, const char c2);

bool IsAnagram(const char a1[], const char a2[], bool CaseMatter = false);

bool Replace1With2(char a1[], int size, char value,
                   char replace1, char replace2);

void SwapRowsAndColumns(int a1[][kSquareSize]);

#endif
