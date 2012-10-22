#include "Node.h"
#include <assert.h>

Node::Node(int v) {
  value = v;
  next = 0;
}

Node::~Node() {
}

int Node::getValue() {
  return value;
}

Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* &n) {
  next = n;
}
