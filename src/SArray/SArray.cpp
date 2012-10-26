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
cout << "0";
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());
cout << "1";
  Node<T>** currRow = &rows[r];
  while(*currRow != 0 && (*currRow)->getCol() < c) {
    *currRow = (*currRow)->getRight();
  }
cout << "2";
  Node<T>** currCol = &cols[c];
  while(currRow != currCol) {
    *currCol = (*currCol)->getDown();
  }
cout << "3";
  Node<T>* nextRight = 0;
  if(*currRow != 0) {
    nextRight = (*currRow)->getRight();
  }
cout << "4";
  Node<T>* nextDown = 0;
  if(*currCol != 0) {
    nextDown = (*currCol)->getDown();
  }
cout << "5";
  Node<T>* temp = new Node<T>(r, c, v);
  temp->setRight(nextRight);
  temp->setDown(nextDown);
  (*currRow)->setRight(temp);
  (*currCol)->setDown(temp);
}

template <typename T>
T SArray<T>::access(int r, int c) {
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());

  if(rows[r] == 0 || cols[c] == 0) {
    return defVal;
  } else {
    Node<T>** curr = &rows[r];
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
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());

  Node<T>** currRow = &rows[r];
  while(*currRow != 0 && (*currRow)->getCol() < c) {
    *currRow = (*currRow)->getRight();
  }

  Node<T>** currCol = &cols[c];
  while(currRow != currCol) {
    *currCol = (*currCol)->getDown();
  }

  Node<T>* nextRight = 0;
  if(*currRow != 0) {
    nextRight = (*currRow)->getRight();
  }

  Node<T>* nextDown = 0;
  if(*currCol != 0) {
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
