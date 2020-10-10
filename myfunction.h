//
// Created by anleeno on 2019/11/24.
//

#ifndef CLIONPROJECT_MYFUNCTION_H
#define CLIONPROJECT_MYFUNCTION_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void insert_a_character(char *s);

double keep_two_decimal_places(double h);

int is_prime(int n);

void Goldbach(int n);

double sum_alternate_signs();

void rhombus(int size);

void count_of_capital_letters();

void bubble_sort();

void select_sort();

void hanoi_move(char x, char y);

void hanoi(int n, char a, char b, char c);

void char_reverse();

char *str_cmp(char *pstr1, char *pstr2);

char *remove_char_from_str(char s[],char c);

int *array_reverse(int *a,int n);

void octalToDecimal();

//循环右移三位
void rightloop(char *a, int n);

#endif //CLIONPROJECT_MYFUNCTION_H
