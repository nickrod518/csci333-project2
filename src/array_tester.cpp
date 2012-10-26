#include <iostream>
#include "AArray/AArray.h"
#include "VArray/VArray.h"
#include "SArray/SArray.h"

using std::cout;
using std::endl;

int main () {
  AArray<int>* a = new AArray<int>(5, 7, 0);

  a->insert(3, 5, 8);
  a->insert(3, 6, 20);
  a->insert(1, 2, 40);

  a->remove(3, 6);

  cout << "accessed: " << a->access(3, 5) << endl;
  cout << "accessed: " << a->access(1, 1) << endl;

  a->print();
  delete a;



  VArray<int>* v = new VArray<int>(5, 7, 0);

  v->insert(3, 5, 8);
  v->insert(3, 6, 20);
  v->insert(1, 2, 40);

  v->remove(3, 6);

  cout << "accessed: " << v->access(3, 5) << endl;
  cout << "accessed: " << v->access(1, 1) << endl;

  v->print();
  delete v;



  SArray<int>* s = new SArray<int>(5, 7, 0);

  s->insert(3, 5, 8);
  s->insert(3, 6, 20);
  s->insert(1, 2, 40);

  v->remove(3, 6);

  cout << "accessed: " << s->access(3, 5) << endl;
  cout << "accessed: " << s->access(1, 1) << endl;

  s->print();
  delete s;

  return 0;
}
