#include <iostream>
#include "SArray.h"

using std::cout;
using std::endl;

int main () {
  SArray<int>* a = new SArray<int>(5, 7, 0);
  cout << "initialized" << endl;

  a->insert(3, 5, 8);
  cout << "first insert" << endl;
  a->insert(3, 6, 20);
  cout << "second insert" << endl;
  a->insert(1, 2, 40);
  cout << "third insert" << endl;
  cout << "inserted" << endl;

  cout << "accessed: " << a->access(3, 5) << endl;
  cout << "accessed: " << a->access(1, 1) << endl;

  a->remove(3, 6);
  a->remove(1, 1);

  a->print();
  delete a;
  return 0;
}
