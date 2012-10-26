#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {
  private:
    T value;
    int row;
    int col;
    Node<T>* down;
    Node<T>* right;

  public:
    Node<T>(int r, int c, T v);
    ~Node<T>();
    T getValue();
    void setValue(T v);
    int getRow();
    int getCol();
    Node<T>* getDown();
    Node<T>* getRight();
    void setDown(Node<T>* n);
    void setRight(Node<T>* n);
};

#endif
