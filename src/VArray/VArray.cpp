#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include "VArray.h"

using std::cout;
using std::endl;
using std::vector;

template <typename T>
VArray<T>::VArray(int r, int c, T def) {
  assert(r > 0 && c > 0);

  defVal = def;
  theArray = new vector< vector<T> >(r, vector<T>(c, defVal));
}

template <typename T>
VArray<T>::~VArray() {

}

template <typename T>
void VArray<T>::insert(int r, int c, T v) {
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());
  theArray->at(r).at(c) = v;
}

template <typename T>
T VArray<T>::access(int r, int c) {
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());
  return theArray->at(r).at(c);
}

template <typename T>
void VArray<T>::remove(int r, int c) {
  assert(r >= 0 && r <= getNumRows());
  assert(c >= 0 && c <= getNumCols());
  theArray->at(r).at(c) = defVal;
}

template <typename T>
void VArray<T>::print() {
  cout << "[" << endl;
  for(int r = 0; r < getNumRows(); ++r) {
    for(int c = 0; c < getNumCols(); ++c) {
      cout << "\t" << theArray->at(r).at(c);
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
  return theArray->size();
}

template <typename T>
int VArray<T>::getNumCols() {
  return theArray->at(0).size();
}

template class VArray<int>;
template class VArray<double>;
template class VArray<std::string>;
