#include <iostream>
#include "AArray/AArray.h"

using std::cout;
using std::endl;

int main () {
  AArray<int>* a = new AArray<int>(5, 7, 0);
  cout << "initialized";
  a->insert(3, 5, 8);
  cout << "inserted";
  a->access(3, 5);
  cout << "accessed";
  a->print();
  cout << "printed";

  return 0;
}
