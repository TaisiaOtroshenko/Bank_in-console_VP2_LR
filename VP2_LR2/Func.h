#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<typename Type>

void Sort(Type* arr);

template<typename Type, typename T>
Type* Filter(Type* arr, T par);

template<typename Type>
void Del(Type* arr, size_t index);

template<typename Type>
void Add(Type* arr);

template<typename Type>
void Edit(Type* arr, size_t index);