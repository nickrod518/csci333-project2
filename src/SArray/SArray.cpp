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
  for(int i = 0; i < getNumRows(); ++i) {
    Node<T>** curr = &(rows[i]);
    while(*curr != 0) {
      Node<T>* oldNode = *curr;
      curr = &((*curr)->getRight());
      delete oldNode;
    }
  }
}

template <typename T>
void SArray<T>::insert(int r, int c, T v) {
  assert(r >= 0 && r < getNumRows());
  assert(c >= 0 && c < getNumCols());

  Node<T>** currRow = &(cols[c]);
  while(*currRow != 0 && (*currRow)->getRow() < r) {
    currRow = &((*currRow)->getDown());
  }

  Node<T>** currCol = &(rows[r]);
  while(*currCol != 0 && (*currCol)->getCol() < c) {
    currCol = &((*currCol)->getRight());
  }

  Node<T>* newNode = new Node<T>(r, c, v);
  newNode->setDown(**currRow);
  newNode->setRight(**currCol);
  *currRow = newNode;
  *currCol = newNode;
}

template <typename T>
T SArray<T>::access(int r, int c) {
  assert(r >= 0 && r < getNumRows());
  assert(c >= 0 && c < getNumCols());

  if(rows[r] == 0 || cols[c] == 0) {
    return defVal;
  } else {
    Node<T>** curr = &(rows[r]);
    while(*curr != 0) {
      if((*curr)->getCol() == c) {
        return (*curr)->getValue();
      }
      curr = &((*curr)->getRight());
    }
    return defVal;
  }
}

template <typename T>
void SArray<T>::remove(int r, int c) {
  assert(r >= 0 && r < getNumRows());
  assert(c >= 0 && c < getNumCols());

  Node<T>** currRow = &(cols[c]);
  while(*currRow != 0 && (*currRow)->getRow() < r) {
    currRow = &((*currRow)->getDown());
  }
  Node<T>** nextRow = 0;
  if(*currRow != 0) {
    nextRow = &((*currRow)->getDown());
    (*currRow)->setDown(**nextRow);
  }

  Node<T>** currCol = &(rows[r]);
  while(*currCol != 0 && (*currCol)->getCol() < c) {
    currCol = &((*currCol)->getRight());
  }
  Node<T>** nextCol = 0;
  if(*currRow != 0) {
    nextCol = &((*currCol)->getRight());
    (*currCol)->setRight(**nextCol);
  }

  Node<T>* oldRow = *currRow;
  Node<T>* oldCol = *currCol;
  if(oldRow != 0) {
    delete oldRow;
  } else if(oldCol != 0) {
    delete oldCol;
  }
}

template <typename T>
void SArray<T>::print() {
  cout << "[" << endl;
  for(int r = 0; r < getNumRows(); ++r) {
    for(int c = 0; c < getNumCols(); ++c) {
      cout << access(r, c);
      if(r < getNumRows()-1 || c < getNumCols()-1) {
        cout << ", \t";
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
