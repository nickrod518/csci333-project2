#ifndef __AARRAY_H__
#define __AARRAY_H__

template <typename T>
class AArray {
  private:
    T** theArray;
    T defVal;
    int numRows;
    int numCols;

  public:
    AArray<T>(int r, int c, T def);
    ~AArray<T>();
    void insert(int r, int c, T v);
    T access(int r, int c);
    void remove(int r, int c);
    void print();
    int getNumRows();
    int getNumCols();
};

#endif
