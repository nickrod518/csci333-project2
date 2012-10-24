#ifndef __SARRAY_H__
#define __SARRAY_H__

#include "Node.h"

template <typename T>
class SArray {
  private:
    T defVal;
    Node<T>** row;
    Node<T>** col;
    int numRows;
    int numCols;

  public:
    SArray<T>(int r, int c, T def);
    ~SArray<T>();
    void insert(int r, int c, T v);
    T access(int r, int c);
    void remove(int r, int c);
    void print();
    int getNumRows();
    int getNumCols();
};

#endif
