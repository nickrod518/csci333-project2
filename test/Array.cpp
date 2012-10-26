#include "gtest/gtest.h"
#include "../src/AArray/AArray.h"
#include "../src/VArray/VArray.h"
#include "../src/SArray/SArray.h"
#include <string>

using std::string;


//BEGIN AARRAY TESTING

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
  AArray<int>* ai = new AArray<int>(5, 10, 1);
  ai->insert(1, 4, 0);
  ai->insert(0, 7, 200);
  EXPECT_EQ(1, ai->access(0, 0));
  EXPECT_EQ(1, ai->access(4, 9));
  EXPECT_EQ(1, ai->access(4, 8));
  EXPECT_EQ(0, ai->access(1, 4));
  EXPECT_EQ(200, ai->access(0, 7));
  delete ai;

  AArray<double>* ad = new AArray<double>(5, 10, 1.8);
  ad->insert(1, 4, 55.39);
  ad->insert(0, 7, .01);
  EXPECT_EQ(1.8, ad->access(0, 0));
  EXPECT_EQ(1.8, ad->access(4, 9));
  EXPECT_EQ(1.8, ad->access(4, 8));
  EXPECT_EQ(55.39, ad->access(1, 4));
  EXPECT_EQ(.01, ad->access(0, 7));
  delete ad;

  AArray<string>* as = new AArray<string>(5, 10, "ohai");
  as->insert(1, 4, "um");
  as->insert(0, 7, "world");
  EXPECT_EQ("ohai", as->access(0, 0));
  EXPECT_EQ("ohai", as->access(4, 9));
  EXPECT_EQ("ohai", as->access(4, 8));
  EXPECT_EQ("um", as->access(1, 4));
  EXPECT_EQ("world", as->access(0, 7));
  delete as;
}

TEST(AArray, Remove) {
  AArray<int>* ai = new AArray<int>(5, 10, 1);
  ai->insert(1, 4, 0);
  ai->insert(0, 7, 200);
  ai->remove(1, 4);
  ai->remove(0, 7);
  EXPECT_EQ(1, ai->access(1, 4));
  EXPECT_EQ(1, ai->access(0, 7));
  delete ai;

  AArray<double>* ad = new AArray<double>(5, 10, .1);
  ad->insert(1, 4, .4);
  ad->insert(0, 7, 20.2);
  ad->remove(1, 4);
  ad->remove(0, 7);
  EXPECT_EQ(.1, ad->access(1, 4));
  EXPECT_EQ(.1, ad->access(0, 7));
  delete ad;

  AArray<string>* as = new AArray<string>(5, 10, "abc");
  as->insert(1, 4, "jkl;");
  as->insert(0, 7, "project");
  as->remove(1, 4);
  as->remove(0, 7);
  EXPECT_EQ("abc", as->access(1, 4));
  EXPECT_EQ("abc", as->access(0, 7));
  delete as;
}

TEST(AArray, Print) {

}

TEST(AArray, GetNumRows) {
  int rows = 50;
  AArray<int>* ai = new AArray<int>(rows, 200, 0);
  EXPECT_EQ(50, ai->getNumRows());
  delete ai;

  rows = 20;
  AArray<double>* ad = new AArray<double>(rows, 200, 1.1);
  EXPECT_EQ(20, ad->getNumRows());
  delete ad;

  rows = 5;
  AArray<string>* as = new AArray<string>(rows, 200, "world");
  EXPECT_EQ(5, as->getNumRows());
  delete as;
}

TEST(AArray, GetNumCols) {
  int cols = 95;
  AArray<int>* ai = new AArray<int>(80, cols, 0);
  EXPECT_EQ(95, ai->getNumCols());
  delete ai;

  cols = 40;
  AArray<double>* ad = new AArray<double>(80, cols, 10.10);
  EXPECT_EQ(40, ad->getNumCols());
  delete ad;

  cols = 100;
  AArray<string>* as = new AArray<string>(80, cols, "hello");
  EXPECT_EQ(100, ad->getNumCols());
  delete as;
}


// BEGIN VARRAY TESTING

TEST(VArray, Initialize) {
  VArray<int>* ai = new VArray<int>(4, 30, 2);
  EXPECT_EQ(4, ai->getNumRows());
  EXPECT_EQ(30, ai->getNumCols());
  delete ai;

  VArray<double>* ad = new VArray<double>(5, 10, 1.4);
  EXPECT_EQ(5, ad->getNumRows());
  EXPECT_EQ(10, ad->getNumCols());
  delete ad;

  VArray<string>* as = new VArray<string>(5, 10, "hello");
  EXPECT_EQ(5, as->getNumRows());
  EXPECT_EQ(10, as->getNumCols());
  delete as;
}

TEST(VArray, Insert) {
  VArray<int>* ai = new VArray<int>(5, 10, 1);
  ai->insert(1, 4, 0);
  ai->insert(0, 7, 200);
  EXPECT_EQ(0, ai->access(1, 4));
  EXPECT_EQ(200, ai->access(0, 7));
  delete ai;

  VArray<double>* ad = new VArray<double>(5, 10, 1);
  ad->insert(1, 4, 12.3);
  ad->insert(0, 7, 400.003);
  EXPECT_EQ(12.3, ad->access(1, 4));
  EXPECT_EQ(400.003, ad->access(0, 7));
  delete ad;

  VArray<string>* as = new VArray<string>(5, 10, "hello");
  as->insert(1, 4, "ohai");
  as->insert(0, 7, "hi");
  EXPECT_EQ("ohai", as->access(1, 4));
  EXPECT_EQ("hi", as->access(0, 7));
  delete as;
}

TEST(VArray, Access) {
  VArray<int>* ai = new VArray<int>(5, 10, 1);
  ai->insert(1, 4, 0);
  ai->insert(0, 7, 200);
  EXPECT_EQ(1, ai->access(0, 0));
  EXPECT_EQ(1, ai->access(4, 9));
  EXPECT_EQ(1, ai->access(4, 8));
  EXPECT_EQ(0, ai->access(1, 4));
  EXPECT_EQ(200, ai->access(0, 7));
  delete ai;

  VArray<double>* ad = new VArray<double>(5, 10, 1.8);
  ad->insert(1, 4, 55.39);
  ad->insert(0, 7, .01);
  EXPECT_EQ(1.8, ad->access(0, 0));
  EXPECT_EQ(1.8, ad->access(4, 9));
  EXPECT_EQ(1.8, ad->access(4, 8));
  EXPECT_EQ(55.39, ad->access(1, 4));
  EXPECT_EQ(.01, ad->access(0, 7));
  delete ad;

  VArray<string>* as = new VArray<string>(5, 10, "ohai");
  as->insert(1, 4, "um");
  as->insert(0, 7, "world");
  EXPECT_EQ("ohai", as->access(0, 0));
  EXPECT_EQ("ohai", as->access(4, 9));
  EXPECT_EQ("ohai", as->access(4, 8));
  EXPECT_EQ("um", as->access(1, 4));
  EXPECT_EQ("world", as->access(0, 7));
  delete as;
}

TEST(VArray, Remove) {
  VArray<int>* ai = new VArray<int>(5, 10, 1);
  ai->insert(1, 4, 0);
  ai->insert(0, 7, 200);
  ai->remove(1, 4);
  ai->remove(0, 7);
  EXPECT_EQ(1, ai->access(1, 4));
  EXPECT_EQ(1, ai->access(0, 7));
  delete ai;

  VArray<double>* ad = new VArray<double>(5, 10, .1);
  ad->insert(1, 4, .4);
  ad->insert(0, 7, 20.2);
  ad->remove(1, 4);
  ad->remove(0, 7);
  EXPECT_EQ(.1, ad->access(1, 4));
  EXPECT_EQ(.1, ad->access(0, 7));
  delete ad;

  VArray<string>* as = new VArray<string>(5, 10, "abc");
  as->insert(1, 4, "jkl;");
  as->insert(0, 7, "project");
  as->remove(1, 4);
  as->remove(0, 7);
  EXPECT_EQ("abc", as->access(1, 4));
  EXPECT_EQ("abc", as->access(0, 7));
  delete as;
}

TEST(VArray, Print) {

}

TEST(VArray, GetNumRows) {
  int rows = 50;
  VArray<int>* ai = new VArray<int>(rows, 200, 0);
  EXPECT_EQ(50, ai->getNumRows());
  delete ai;

  rows = 20;
  VArray<double>* ad = new VArray<double>(rows, 200, 1.1);
  EXPECT_EQ(20, ad->getNumRows());
  delete ad;

  rows = 5;
  VArray<string>* as = new VArray<string>(rows, 200, "world");
  EXPECT_EQ(5, as->getNumRows());
  delete as;
}

TEST(VArray, GetNumCols) {
  int cols = 95;
  VArray<int>* ai = new VArray<int>(80, cols, 0);
  EXPECT_EQ(95, ai->getNumCols());
  delete ai;

  cols = 40;
  VArray<double>* ad = new VArray<double>(80, cols, 10.10);
  EXPECT_EQ(40, ad->getNumCols());
  delete ad;

  cols = 100;
  VArray<string>* as = new VArray<string>(80, cols, "hello");
  EXPECT_EQ(100, ad->getNumCols());
  delete as;
}



//BEGIN SARRAY TESTING

TEST(SArray, Initialize) {
  SArray<int>* ai = new SArray<int>(4, 30, 2);
  EXPECT_EQ(4, ai->getNumRows());
  EXPECT_EQ(30, ai->getNumCols());
  delete ai;

  SArray<double>* ad = new SArray<double>(5, 10, 1.4);
  EXPECT_EQ(5, ad->getNumRows());
  EXPECT_EQ(10, ad->getNumCols());
  delete ad;

  SArray<string>* as = new SArray<string>(5, 10, "hello");
  EXPECT_EQ(5, as->getNumRows());
  EXPECT_EQ(10, as->getNumCols());
  delete as;
}

TEST(SArray, Insert) {
  SArray<int>* ai = new SArray<int>(5, 10, 1);
  ai->insert(1, 4, 0);
  ai->insert(0, 7, 200);
  EXPECT_EQ(0, ai->access(1, 4));
  EXPECT_EQ(200, ai->access(0, 7));
  delete ai;

  SArray<double>* ad = new SArray<double>(5, 10, 1);
  ad->insert(1, 4, 12.3);
  ad->insert(0, 7, 400.003);
  EXPECT_EQ(12.3, ad->access(1, 4));
  EXPECT_EQ(400.003, ad->access(0, 7));
  delete ad;

  SArray<string>* as = new SArray<string>(5, 10, "hello");
  as->insert(1, 4, "ohai");
  as->insert(0, 7, "hi");
  EXPECT_EQ("ohai", as->access(1, 4));
  EXPECT_EQ("hi", as->access(0, 7));
  delete as;
}

TEST(SArray, Access) {
  SArray<int>* ai = new SArray<int>(5, 10, 1);
  ai->insert(1, 4, 0);
  ai->insert(0, 7, 200);
  EXPECT_EQ(1, ai->access(0, 0));
  EXPECT_EQ(1, ai->access(4, 9));
  EXPECT_EQ(1, ai->access(4, 8));
  EXPECT_EQ(0, ai->access(1, 4));
  EXPECT_EQ(200, ai->access(0, 7));
  delete ai;

  SArray<double>* ad = new SArray<double>(5, 10, 1.8);
  ad->insert(1, 4, 55.39);
  ad->insert(0, 7, .01);
  EXPECT_EQ(1.8, ad->access(0, 0));
  EXPECT_EQ(1.8, ad->access(4, 9));
  EXPECT_EQ(1.8, ad->access(4, 8));
  EXPECT_EQ(55.39, ad->access(1, 4));
  EXPECT_EQ(.01, ad->access(0, 7));
  delete ad;

  SArray<string>* as = new SArray<string>(5, 10, "ohai");
  as->insert(1, 4, "um");
  as->insert(0, 7, "world");
  EXPECT_EQ("ohai", as->access(0, 0));
  EXPECT_EQ("ohai", as->access(4, 9));
  EXPECT_EQ("ohai", as->access(4, 8));
  EXPECT_EQ("um", as->access(1, 4));
  EXPECT_EQ("world", as->access(0, 7));
  delete as;
}

TEST(SArray, Remove) {
  SArray<int>* ai = new SArray<int>(5, 10, 1);
  ai->insert(1, 4, 0);
  ai->insert(0, 7, 200);
  ai->remove(1, 4);
  ai->remove(0, 7);
  EXPECT_EQ(1, ai->access(1, 4));
  EXPECT_EQ(1, ai->access(0, 7));
  delete ai;

  SArray<double>* ad = new SArray<double>(5, 10, .1);
  ad->insert(1, 4, .4);
  ad->insert(0, 7, 20.2);
  ad->remove(1, 4);
  ad->remove(0, 7);
  EXPECT_EQ(.1, ad->access(1, 4));
  EXPECT_EQ(.1, ad->access(0, 7));
  delete ad;

  SArray<string>* as = new SArray<string>(5, 10, "abc");
  as->insert(1, 4, "jkl;");
  as->insert(0, 7, "project");
  as->remove(1, 4);
  as->remove(0, 7);
  EXPECT_EQ("abc", as->access(1, 4));
  EXPECT_EQ("abc", as->access(0, 7));
  delete as;
}

TEST(SArray, Print) {

}

TEST(SArray, GetNumRows) {
  int rows = 50;
  SArray<int>* ai = new SArray<int>(rows, 200, 0);
  EXPECT_EQ(50, ai->getNumRows());
  delete ai;

  rows = 20;
  SArray<double>* ad = new SArray<double>(rows, 200, 1.1);
  EXPECT_EQ(20, ad->getNumRows());
  delete ad;

  rows = 5;
  SArray<string>* as = new SArray<string>(rows, 200, "world");
  EXPECT_EQ(5, as->getNumRows());
  delete as;
}

TEST(SArray, GetNumCols) {
  int cols = 95;
  SArray<int>* ai = new SArray<int>(80, cols, 0);
  EXPECT_EQ(95, ai->getNumCols());
  delete ai;

  cols = 40;
  SArray<double>* ad = new SArray<double>(80, cols, 10.10);
  EXPECT_EQ(40, ad->getNumCols());
  delete ad;

  cols = 100;
  SArray<string>* as = new SArray<string>(80, cols, "hello");
  EXPECT_EQ(100, ad->getNumCols());
  delete as;
}
