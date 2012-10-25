#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {
  private:
    T value;
    int row;
    int col;
    Node* down;
    Node* right;

  public:
    Node(T v, int r, int c);
    ~Node();
    T getValue();
    void setValue(T v);
    Node* getNextDown();
    Node* getNextRight();
    void setNextDown(Node* &n);
    void setNextRight(Node* &n);
};

#endif
