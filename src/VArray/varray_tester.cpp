#include <iostream>
#include "VArray.h"

using std::cout;
using std::endl;

int main () {
  VArray<int>* v = new VArray<int>(5, 7, 0);
  cout << "initialized" << endl;

  v->insert(3, 5, 8);
  v->insert(3, 6, 20);
  v->insert(1, 2, 40);
  cout << "inserted" << endl;

  cout << "accessed: " << v->access(3, 5) << endl;
  cout << "accessed: " << v->access(1, 1) << endl;

  v->print();

  return 0;
}
