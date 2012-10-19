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
  defVal = def;
  T** theArray = new T*[c];

  for(int i = 0; i < c; ++i) {
    theArray[i] = new T[r];
    for(int j = 0; j < r; ++j) {
      (*theArray)[j] = def;
    }
  }
}

template <typename T>
void AArray<T>::insert(int r, int c, T v) {
  **(theArray + c * numRows + r) = v;
}

template <typename T>
T AArray<T>::access(int r, int c) {
  return **(theArray + c * numRows + r);
}

template <typename T>
void AArray<T>::remove(int r, int c) {
  **(theArray + c * numRows + r) = defVal;
}

template <typename T>
void AArray<T>::print() {
  cout << "[ ";  
  for(int r = numRows - 1; r >= 0; --r) {
    for(int c = numCols - 1; c >= 0; --c) {
      cout << **(theArray + c * getNumRows() + r);
    }
    if(r > 1) {
        cout << ", ";
    }
  }
  cout << " ]" << endl;
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
