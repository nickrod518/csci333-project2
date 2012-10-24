#include <iostream>
#include <assert.h>
#include <string>
#include <list>
#include <vector>
#include "SArray.h"
#include "Node.h"

using std::cout;
using std::endl;

template <typename T>
SArray<T>::SArray(int r, int c, T def) {
  assert(r > 0 && c > 0);

  defVal = def;
  numRows = r;
  numCols = c;

  row = new Node<T>*[r];
  col = new Node<T>*[c];

  for(int i = 0; i < r; ++i) {
    row[i] = new Node<T>(def);
  }

  for(int i = 0; i < c; ++i) {
    col[i] = new Node<T>(def);
  }
}

template <typename T>
SArray<T>::~SArray() {

}

template <typename T>
void SArray<T>::insert(int r, int c, T v) {
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());
}

template <typename T>
T SArray<T>::access(int r, int c) {
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());
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
