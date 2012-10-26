#include <string>
#include "Node.h"

template <typename T>
Node<T>::Node(int r, int c, T v) {
  value = v;
  row = r;
  col = c;
  down = 0;
  right = 0;
}

template <typename T>
Node<T>::~Node() {

}

template <typename T>
T Node<T>::getValue() {
  return value;
}

template <typename T>
void Node<T>::setValue(T v) {
  value = v;
}

template <typename T>
int Node<T>::getRow() {
  return row;
}

template <typename T>
int Node<T>::getCol() {
  return col;
}

template <typename T>
Node<T>*& Node<T>::getDown() {
  return down;
}

template <typename T>
Node<T>*& Node<T>::getRight() {
  return right;
}

template <typename T>
void Node<T>::setDown(Node<T>& n) {
  down = &n;
}

template <typename T>
void Node<T>::setRight(Node<T>& n) {
  right = &n;
}

template class Node<int>;
template class Node<double>;
template class Node<std::string>;
