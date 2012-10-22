#ifndef __SARRAY_H__
#define __SARRAY_H__

template <typename T>
class SArray {
  private:
    T** theArray;
    T defVal;
    int numRows;
    int numCols;
    Node* down;
    Node* over;

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
