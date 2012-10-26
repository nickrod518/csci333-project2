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
      *curr = (*curr)->getRight();
      delete oldNode;
    }
  }
}

template <typename T>
void SArray<T>::insert(int r, int c, T v) {
  assert(r >= 0 && r < getNumRows());
  assert(c >= 0 && c < getNumCols());

  Node<T>** currRow = &(rows[r]);
  Node<T>* nextRight = 0;
  while(*currRow != 0 && (*currRow)->getCol() < c) {
    *currRow = (*currRow)->getRight();
    nextRight = (*currRow)->getRight();
  }

  Node<T>** currCol = &(cols[c]);
  Node<T>* nextDown = 0;
  while(currRow != 0 && (*currCol)->getRow() < r) {
    *currCol = (*currCol)->getDown();
    nextDown = (*currCol)->getDown();
  }

  Node<T>* newNode = new Node<T>(r, c, v);
  newNode->setRight(nextRight);
  newNode->setDown(nextDown);
  (*currRow)->setRight(newNode);
  (*currCol)->setDown(newNode);
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
      if((*curr)->getRow() == r && (*curr)->getCol() == c) {
        return (*curr)->getValue();
      }
      *curr = (*curr)->getRight();
    }
    return defVal;
  }
}

template <typename T>
void SArray<T>::remove(int r, int c) {
  assert(r >= 0 && r < getNumRows());
  assert(c >= 0 && c < getNumCols());

  Node<T>** currRow = &(rows[r]);
  Node<T>* nextRight = 0;
  while(*currRow != 0 && (*currRow)->getCol() < c) {
    *currRow = (*currRow)->getRight();
    nextRight = (*currRow)->getRight();
  }

  Node<T>** currCol = &(cols[c]);
  Node<T>* nextDown = 0;
  while(currRow != 0 && (*currCol)->getRow() < r) {
    *currCol = (*currCol)->getDown();
    nextDown = (*currCol)->getDown();
  }

  Node<T>* oldNode = *currRow;
  (*currRow)->setRight(nextRight);
  (*currCol)->setDown(nextDown);
  delete oldNode;
}

template <typename T>
void SArray<T>::print() {
  cout << "[" << endl;
  for(int r = 0; r < getNumRows(); ++r) {
    for(int c = 0; c < getNumCols(); ++c) {
      cout << access(r, c);
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
