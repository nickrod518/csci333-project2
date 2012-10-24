#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {
  private:
    T value;
    Node* down;
    Node* right;

  public:
    Node(T v);
    ~Node();
    T getValue();
    Node* getNextDown();
    Node* getNextRight();
    void setNextDown(Node* &n);
    void setNextRight(Node* &n);
};

#endif
