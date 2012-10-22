#include "gtest/gtest.h"
#include "../src/AArray/AArray.h"

TEST(AArray, Initialize) {
  AArray<int>* a = new AArray<int>(4, 30, 2);

  EXPECT_EQ(4, a->getNumRows());
  EXPECT_EQ(30, a->getNumCols());
  delete a;
}
