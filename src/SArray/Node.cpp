#include "Node.h"

Node::Node(int v) {
  value = v;
  down = 0;
  right = 0;
}

Node::~Node() {
}

int Node::getValue() {
  return value;
}

Node* Node::getNextDown() {
  return down;
}

Node* Node::getNextRight() {
  return right;
}

void Node::setNextDown(Node* &n) {
  down = n;
}

void Node::setNextRight(Node* &n) {
  right = n;
}
