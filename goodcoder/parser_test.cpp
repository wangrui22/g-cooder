/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved 
 * 
 **************************************************************************/
 
 /**
 * @file parser_test.cpp
 * @author wangrui(wangrui22@baidu.com)
 * @date 2017/08/21
 * @version 0.0.1 
 * @brief word parser unit test
 *  
 **/

#include <cstdio>
#include <cstdlib>

#include "gtest/gtest.h"
#include "parser.h"

const char* TEST_RECORD = "comlog\t12345678\t3."
                          "1415926\t9223372036854775807\tgoodcoder\t3:12,23,34\t10 "
                          "12 23\t3:1 2 3,3 4 5,7 8 9\n";

class TestParser : public ::testing::Test {
public:
    TestParser() : _test_c(NULL) {}

    virtual ~TestParser() {
        if (_test_c) {
            delete _test_c;
            _test_c = NULL;
        }
    }

    virtual void SetUp() {
        _test_c = new good_coder::Parser();
    }

    virtual void TearDown() {
        if (_test_c) {
            delete _test_c;
            _test_c = NULL;
        }
    }

    good_coder::Parser* _test_c;
};

TEST_F(TestParser, testFloat) {
    double item_f = 0.0;
    EXPECT_EQ(0, _test_c->read_line(TEST_RECORD));

    EXPECT_EQ(0, _test_c->get_item(2, &item_f));
    EXPECT_EQ(3.1415926, item_f);
}

TEST_F(TestParser, testCharStr) {
    char item_c[256];
    EXPECT_EQ(0, _test_c->read_line(TEST_RECORD));

    EXPECT_EQ(0, _test_c->get_item(0, item_c, 256));
    EXPECT_EQ(0, strcmp("comlog", item_c));

    EXPECT_EQ(0, _test_c->get_item(4, item_c, 256));
    EXPECT_EQ(0, strcmp("goodcoder", item_c));
}

TEST_F(TestParser, testInt) {
    int item_i = 0;
    EXPECT_EQ(0, _test_c->read_line(TEST_RECORD));

    EXPECT_EQ(0, _test_c->get_item(1, &item_i));
    EXPECT_EQ(12345678, item_i);
}

TEST_F(TestParser, testUInt64) {
    uint64_t item_llu = 0;
    EXPECT_EQ(0, _test_c->read_line(TEST_RECORD));

    EXPECT_EQ(0, _test_c->get_item(3, &item_llu));
    EXPECT_EQ(9223372036854775807, item_llu);
}

TEST_F(TestParser, testIntArray) {
    std::vector<int> item_is;
    EXPECT_EQ(0, _test_c->read_line(TEST_RECORD));

    EXPECT_EQ(0, _test_c->get_item(5, &item_is));
    EXPECT_EQ(3, item_is.size());
    EXPECT_EQ(12, item_is[0]);
    EXPECT_EQ(23, item_is[1]);
    EXPECT_EQ(34, item_is[2]);
}

TEST_F(TestParser, testPoint3) {
    good_coder::Point3 pt;
    EXPECT_EQ(0, _test_c->read_line(TEST_RECORD));

    EXPECT_EQ(0, _test_c->get_item(6, &pt));
    EXPECT_EQ(10, pt.x);
    EXPECT_EQ(12, pt.y);
    EXPECT_EQ(23, pt.z);
}

TEST_F(TestParser, testPoint3Array) {
    std::vector<good_coder::Point3> pts;
    EXPECT_EQ(0, _test_c->read_line(TEST_RECORD));

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

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}