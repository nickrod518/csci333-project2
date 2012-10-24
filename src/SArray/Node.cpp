#include <string>
#include "Node.h"

template <typename T>
Node<T>::Node(T v) {
  value = v;
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
Node*& Node<T>::getNextDown() {
  return down;
}

template <typename T>
Node*& Node<T>::getNextRight() {
  return right;
}

template <typename T>
void Node<T>::setNextDown(Node* &n) {
  down = &n;
}

template <typename T>
void Node<T>::setNextRight(Node* &n) {
  right = &n;
}

template class SArray<int>;
template class SArray<double>;
template class SArray<std::string>;
