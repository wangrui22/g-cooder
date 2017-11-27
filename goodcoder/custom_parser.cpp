/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved 
 * 
 **************************************************************************/
 
 /**
 * @file custom_parser.cpp
 * @author wangrui(wangrui22@baidu.com)
 * @date 2017/08/21
 * @version 0.0.1 
 * @brief custom parser implementation
 *  
 **/

#include "custom_parser.h"
#include <cstdio>
#include <boost/log/trivial.hpp>

namespace good_coder {
const int POINT_COORD_COUNT = 3;

int parse(const char* str, Point3* res) {
    if (str == NULL) {
        BOOST_LOG_TRIVIAL(fatal) << "input is null.";
        return -1;
    }

    if (res == NULL) {
        BOOST_LOG_TRIVIAL(fatal) << "output result pointer is null.";
        return -1;
    }

    if (POINT_COORD_COUNT == sscanf(str, "%f%f%f", &res->x, &res->y, &res->z)) {
        return 0;
    } else {
        BOOST_LOG_TRIVIAL(fatal) << "invalid input's format.";
        return -1;
    }
}

int parse(const char* str, std::vector<Point3>* res) {
    if (str == NULL) {
        BOOST_LOG_TRIVIAL(fatal) << "input is null.";
        return -1;
    }

    if (res == NULL) {
        BOOST_LOG_TRIVIAL(fatal) << "output result pointer is null.";
        return -1;
    }

    int num = 0;

    if (1 != sscanf(str, "%d[^:]", &num)) {
        BOOST_LOG_TRIVIAL(fatal) << "invalid input's format.";
        return -1;
    }

    if (num < 1) {
        BOOST_LOG_TRIVIAL(fatal) << "invalid input's format : array number is less than 1.";
        return -1;
    }

    const char* src = str;

    while (*src++ != ':') {}

    if (*src == '\t' || *src == '\n' || *src == '\0') {
        BOOST_LOG_TRIVIAL(fatal) << "invalid input's format : empty array.";
        return -1;
    }

    res->clear();
    res->resize(num);
    int cur_idx = 0;

    if (POINT_COORD_COUNT != sscanf(src, "%f%f%f", &(*res)[cur_idx].x, &(*res)[cur_idx].y,
                                    &(*res)[cur_idx].z)) {
        res->clear();
        BOOST_LOG_TRIVIAL(fatal) << "invalid input's format.";
        return -1;
    }

    ++cur_idx;

    while (true) {
        while (*src != '\t' && *src != '\n' && *src != '\0' && *src != ',') {
            ++src;
        }

        if (*src == ',' && *(src + 1) != '\t' && *(src + 1) != '\0' &&
                *(src + 1) != '\n') {
            if (POINT_COORD_COUNT != sscanf(++src, "%f%f%f", &(*res)[cur_idx].x, &(*res)[cur_idx].y,
                                            &(*res)[cur_idx].z)) {
                res->clear();
                BOOST_LOG_TRIVIAL(fatal) << "invalid input's format.";
                return -1;
            }

            ++cur_idx;
        } else {
            break;
        }
    }

    if (cur_idx != num) {
        res->clear();
        BOOST_LOG_TRIVIAL(fatal) << "invalid input's format : array number mismatch.";
        return -1;
    }

    return 0;
}
}
