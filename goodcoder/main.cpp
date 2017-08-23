#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "gtest/gtest.h"

#include "parser.h"

const char *test = "comlog\t12345678\t3."
                   "1415926\t18446744073709551615\tgoodcoder\t3:12,23,34\t10 "
                   "12 23\t3:1 2 3,3 4 5,7 8 9\n";

class TestPArser : public ::testing::Test {
public:
  virtual void SetUp() { _test_c = new good_cooder::Parser(); }
  virtual void TearDown() { delete _test_c; }
  good_cooder::Parser *_test_c;
};

TEST_F(TestPArser, FirstTest) {
  char item_c[256];
  double item_f;
  int item_i;
  uint64_t item_llu;
  std::vector<int> item_is;
  good_cooder::Point3 pt;
  std::vector<good_cooder::Point3> pts;

  EXPECT_EQ(0, _test_c->read_line(test));

  EXPECT_EQ(0, _test_c->get_item(0, item_c));
  EXPECT_EQ(0, strcmp("comlog", item_c));

  EXPECT_EQ(0, _test_c->get_item(1, &item_i));
  EXPECT_EQ(12345678, item_i);

  EXPECT_EQ(0, _test_c->get_item(2, &item_f));
  EXPECT_EQ(3.1415926, item_f);

  EXPECT_EQ(0, _test_c->get_item(3, &item_llu));
  EXPECT_EQ(18446744073709551615, item_llu);

  EXPECT_EQ(0, _test_c->get_item(4, item_c));
  EXPECT_EQ(0, strcmp("goodcoder", item_c));

  EXPECT_EQ(0, _test_c->get_item(5, &item_is));
  EXPECT_EQ(3, item_is.size());
  EXPECT_EQ(12, item_is[0]);
  EXPECT_EQ(23, item_is[1]);
  EXPECT_EQ(34, item_is[2]);

  EXPECT_EQ(0, _test_c->get_item(6, &pt));
  EXPECT_EQ(10, pt.x);
  EXPECT_EQ(12, pt.y);
  EXPECT_EQ(23, pt.z);

  EXPECT_EQ(0, _test_c->get_item(7, &pts));
  EXPECT_EQ(3, pts.size());

  EXPECT_EQ(1, pts[0].x);
  EXPECT_EQ(2, pts[0].y);
  EXPECT_EQ(3, pts[0].z);

  EXPECT_EQ(3, pts[1].x);
  EXPECT_EQ(4, pts[1].y);
  EXPECT_EQ(5, pts[1].z);

  EXPECT_EQ(7, pts[2].x);
  EXPECT_EQ(8, pts[2].y);
  EXPECT_EQ(9, pts[2].z);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}