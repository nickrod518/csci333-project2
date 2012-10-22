#include <iostream>
#include <assert.h>
#include <string>
#include <list>
#include <vector>
#include "AArray.h"

using std::cout;
using std::endl;

template <typename T>
AArray<T>::AArray(int r, int c, T def) {
  assert(r > 0 && c > 0);

  defVal = def;
  numRows = r;
  numCols = c;
  theArray = new T*[r];

  for(int i = 0; i < r; ++i) {
    theArray[i] = new T[c];
    for(int j = 0; j < c; ++j) {
      theArray[i][j] = def;
    }
  }
}

template <typename T>
AArray<T>::~AArray() {
  for(int i = 0; i < getNumRows(); ++i) {
    delete[] theArray[i];
  }
  delete[] theArray;
}

template <typename T>
void AArray<T>::insert(int r, int c, T v) {
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());
  theArray[r][c] = v;
}

template <typename T>
T AArray<T>::access(int r, int c) {
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());
  return theArray[r][c];
}

template <typename T>
void AArray<T>::remove(int r, int c) {
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());
  theArray[r][c] = defVal;
}

template <typename T>
void AArray<T>::print() {
  cout << "[" << endl;
  for(int r = 0; r < getNumRows(); ++r) {
    for(int c = 0; c < getNumCols(); ++c) {
      cout << "\t" << theArray[r][c];
      if(r < getNumRows()-1 || c < getNumCols()-1) {
        cout << ", ";
      }
    }
    cout << endl;
  }
  cout << "]" << endl;
}

template <typename T>
int AArray<T>::getNumRows() {
  return numRows;
}

template <typename T>
int AArray<T>::getNumCols() {
  return numCols;
}

template class AArray<int>;
template class AArray<double>;
template class AArray<std::string>;
