#include "gtest/gtest.h"
#include "../src/AArray/AArray.h"

TEST(AArray, Initialize) {
  AArray<int>* a = new AArray<int>(4, 30, 2);

  EXPECT_EQ(4, a->getNumRows());
  EXPECT_EQ(30, a->getNumCols());
  delete a;
}

TEST(AArray, Insert) {
  AArray<int>* a = new AArray<int>(5, 10, 1);
  a->insert(1, 4, 0);
  a->insert(0, 7, 200);

  EXPECT_EQ(0, a->access(1, 4));
  EXPECT_EQ(200, a->access(0, 7));
}

TEST(AArray, Access) {
  AArray<int>* a = new AArray<int>(5, 10, 1);
  a->insert(1, 4, 0);
  a->insert(0, 7, 200);

  EXPECT_EQ(1, a->access(0, 0));
  EXPECT_EQ(1, a->access(4, 9));
  EXPECT_EQ(1, a->access(4, 8));
  EXPECT_EQ(0, a->access(1, 4));
  EXPECT_EQ(200, a->access(0, 7));
}

TEST(AArray, Remove) {
  AArray<int>* a = new AArray<int>(5, 10, 1);
  a->insert(1, 4, 0);
  a->insert(0, 7, 200);

  a->remove(1, 4);
  a->remove(0, 7);

  EXPECT_EQ(1, a->access(1, 4));
  EXPECT_EQ(1, a->access(0, 7));
}

TEST(AArray, Print) {

}

TEST(AArray, GetNumRows) {
  int rows = 50;
  AArray<int>* a = new AArray<int>(rows, 200, 0);

  EXPECT_EQ(50, a->getNumRows());
}

TEST(AArray, GetNumCols) {
  int cols = 95;
  AArray<int>* a = new AArray<int>(80, cols, 0);

  EXPECT_EQ(95, a->getNumCols());
}
