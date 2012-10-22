#include "gtest/gtest.h"
#include "../src/VArray/VArray.h"

TEST(Array, Initialize) {
  VArray<int>* v = new VArray<int>(4, 30, 2);

  EXPECT_EQ(4, v->getNumRows());
  EXPECT_EQ(30, v->getNumCols());
  delete v;
}

TEST(VArray, Insert) {
  VArray<int>* v = new VArray<int>(5, 10, 1);
  v->insert(1, 4, 0);
  v->insert(0, 7, 200);

  EXPECT_EQ(0, v->access(1, 4));
  EXPECT_EQ(200, v->access(0, 7));
}

TEST(VArray, Access) {
  VArray<int>* v = new VArray<int>(5, 10, 1);
  v->insert(1, 4, 0);
  v->insert(0, 7, 200);

  EXPECT_EQ(1, v->access(0, 0));
  EXPECT_EQ(1, v->access(4, 9));
  EXPECT_EQ(1, v->access(4, 8));
  EXPECT_EQ(0, v->access(1, 4));
  EXPECT_EQ(200, v->access(0, 7));
}

TEST(VArray, Remove) {
  VArray<int>* v = new VArray<int>(5, 10, 1);
  v->insert(1, 4, 0);
  v->insert(0, 7, 200);

  v->remove(1, 4);
  v->remove(0, 7);

  EXPECT_EQ(1, v->access(1, 4));
  EXPECT_EQ(1, v->access(0, 7));
}

TEST(VArray, Print) {

}

TEST(VArray, GetNumRows) {
  int rows = 50;
  VArray<int>* v = new VArray<int>(rows, 200, 0);

  EXPECT_EQ(50, v->getNumRows());
}

TEST(VArray, GetNumCols) {
  int cols = 95;
  VArray<int>* v = new VArray<int>(80, cols, 0);

  EXPECT_EQ(95, v->getNumCols());
}
