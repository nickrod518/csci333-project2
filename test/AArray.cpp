#include "gtest/gtest.h"
#include "../src/AArray/AArray.h"
#include <string>

using std::string;

TEST(AArray, Initialize) {
  AArray<int>* ai = new AArray<int>(4, 30, 2);
  EXPECT_EQ(4, ai->getNumRows());
  EXPECT_EQ(30, ai->getNumCols());
  delete ai;

  AArray<double>* ad = new AArray<double>(5, 10, 1.4);
  EXPECT_EQ(5, ad->getNumRows());
  EXPECT_EQ(10, ad->getNumCols());
  delete ad;

  AArray<string>* as = new AArray<string>(5, 10, "hello");
  EXPECT_EQ(5, as->getNumRows());
  EXPECT_EQ(10, as->getNumCols());
  delete as;
}

TEST(AArray, Insert) {
  AArray<int>* ai = new AArray<int>(5, 10, 1);
  ai->insert(1, 4, 0);
  ai->insert(0, 7, 200);
  EXPECT_EQ(0, ai->access(1, 4));
  EXPECT_EQ(200, ai->access(0, 7));
  delete ai;

  AArray<double>* ad = new AArray<double>(5, 10, 1);
  ad->insert(1, 4, 12.3);
  ad->insert(0, 7, 400.003);
  EXPECT_EQ(12.3, ad->access(1, 4));
  EXPECT_EQ(400.003, ad->access(0, 7));
  delete ad;

  AArray<string>* as = new AArray<string>(5, 10, "hello");
  as->insert(1, 4, "ohai");
  as->insert(0, 7, "hi");
  EXPECT_EQ("ohai", as->access(1, 4));
  EXPECT_EQ("hi", as->access(0, 7));
  delete as;
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
  delete a;
}

TEST(AArray, Remove) {
  AArray<int>* a = new AArray<int>(5, 10, 1);
  a->insert(1, 4, 0);
  a->insert(0, 7, 200);

  a->remove(1, 4);
  a->remove(0, 7);

  EXPECT_EQ(1, a->access(1, 4));
  EXPECT_EQ(1, a->access(0, 7));
  delete a;
}

TEST(AArray, Print) {

}

TEST(AArray, GetNumRows) {
  int rows = 50;
  AArray<int>* a = new AArray<int>(rows, 200, 0);

  EXPECT_EQ(50, a->getNumRows());
  delete a;
}

TEST(AArray, GetNumCols) {
  int cols = 95;
  AArray<int>* a = new AArray<int>(80, cols, 0);

  EXPECT_EQ(95, a->getNumCols());
  delete a;
}
