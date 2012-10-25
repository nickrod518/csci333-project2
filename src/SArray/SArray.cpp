#include <iostream>
#include <assert.h>
#include <string>
#include "SArray.h"

using std::cout;
using std::endl;

template <typename T>
SArray<T>::SArray(int r, int c, T def) {
  assert(r > 0 && c > 0);

  defVal = def;
  numRows = r;
  numCols = c;

  rows = new Node<T>*[r];
  cols = new Node<T>*[c];

  for(int i = 0; i < r; ++i) {
    rows[i] = 0;
  }

  for(int i = 0; i < c; ++i) {
    cols[i] = 0;
  }
}

template <typename T>
SArray<T>::~SArray() {

}

template <typename T>
void SArray<T>::insert(int r, int c, T v) {
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());

  Node<T>** currRow = &(rows[r]);
  Node<T>** currCol = &(cols[c]);
  Node<T>* newNode = new Node<T>(v);
  while(*currRow != 0) {
    while(*currCol != 0) {
      if(*currRow == *currCol) {
        newNode->setNextDown(currCol);
        currCol->setNextDown(currCol->getNextDown());
      }
      *currRow = (*currRow)->getNextRight();
    }
    *currCol = (*currCol)->getNextDown();
  }
}

template <typename T>
T SArray<T>::access(int r, int c) {
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());

  if(rows[r] == 0 || cols[c] == 0) {
    return defVal;
  } else {
    Node<T>** currRow = &(rows[r]);
    Node<T>** currCol = &(cols[c]);
    while(*currRow != 0) {
      while(*currCol != 0) {
        if(*currRow == *currCol) {
          return (*currRow)->getValue();
        }
        *currRow = (*currRow)->getNextRight();
      }
      *currCol = (*currCol)->getNextDown();
    }
    return defVal;
  }
}

template <typename T>
void SArray<T>::remove(int r, int c) {
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());
}

template <typename T>
void SArray<T>::print() {
  cout << "[" << endl;
  for(int r = 0; r < getNumRows(); ++r) {
    for(int c = 0; c < getNumCols(); ++c) {
      //cout << theArray[r][c];
      if(r < getNumRows()-1 || c < getNumCols()-1) {
        cout << ", ";
      }
    }
    cout << endl;
  }
  cout << "]" << endl;
}

template <typename T>
int SArray<T>::getNumRows() {
  return numRows;
}

template <typename T>
int SArray<T>::getNumCols() {
  return numCols;
}

template class SArray<int>;
template class SArray<double>;
template class SArray<std::string>;
