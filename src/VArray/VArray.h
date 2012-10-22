#ifndef __VARRAY_H__
#define __VARRAY_H__

#include <vector>

using std::vector;

template <typename T>
class VArray {
  private:
    vector< vector<T> >* theArray;
    T defVal;
    int numRows;
    int numCols;

  public:
    VArray<T>(int r, int c, T def);
    ~VArray<T>();
    void insert(int r, int c, T v);
    T access(int r, int c);
    void remove(int r, int c);
    void print();
    int getNumRows();
    int getNumCols();
};

#endif
