#ifndef __NODE_H__
#define __NODE_H__

class Node {
  private:
    int value;
    Node* down;
    Node* right;

  public:
    Node(int v);
    ~Node();
    int getValue();
    Node* getNextDown();
    Node* getNextRight();
    void setNextDown(Node* &n);
    void setNextRight(Node* &n);
};

#endif
