#include <iostream>
#include <assert.h>
#include <string>
#include <list>
#include <vector>
#include "VArray.h"

using std::cout;
using std::endl;
using std::vector;

template <typename T>
VArray<T>::VArray(int r, int c, T def) {
  assert(r > 0 && c > 0);

  defVal = def;
  numRows = r;
  numCols = c;
  //theArray = new vector<T*>(r);
  theArray = new vector< vector<T*>* >;

  for(int i = 0; i < r; ++i) {
    //theArray[i] = new vector<T>(c, def);
    theArray->at(i) = new vector<T>(c, def);
  }
}

template <typename T>
VArray<T>::~VArray() {

}

template <typename T>
void VArray<T>::insert(int r, int c, T v) {
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());
}

template <typename T>
T VArray<T>::access(int r, int c) {
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());
}

template <typename T>
void VArray<T>::remove(int r, int c) {
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());
}

template <typename T>
void VArray<T>::print() {
  cout << "[" << endl;
  for(int r = 0; r < getNumRows(); ++r) {
    for(int c = 0; c < getNumCols(); ++c) {
      cout << theArray[r][c];
      if(r < getNumRows()-1 || c < getNumCols()-1) {
        cout << ", ";
      }
    }
    cout << endl;
  }
  cout << "]" << endl;
}

template <typename T>
int VArray<T>::getNumRows() {
  return numRows;
}

template <typename T>
int VArray<T>::getNumCols() {
  return numCols;
}

template class VArray<int>;
template class VArray<double>;
template class VArray<std::string>;
