#include <iostream>
#include "AArray/AArray.h"

using std::cout;
using std::endl;

int main () {
  AArray<int>* a = new AArray<int>(5, 7, 0);
  cout << "initialized" << endl;

  a->insert(3, 5, 8);
  a->insert(3, 6, 20);
  a->insert(1, 2, 40);
  cout << "inserted" << endl;

  cout << "accessed: " << a->access(3, 5) << endl;
  cout << "accessed: " << a->access(1, 1) << endl;

  a->print();
  return 0;
}
