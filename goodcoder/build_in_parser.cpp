/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved 
 * 
 **************************************************************************/
 
 /**
 * @file build_in_parser.cpp
 * @author wangrui(wangrui22@baidu.com)
 * @date 2017/08/21
 * @version 0.0.1 
 * @brief build in parser implementation
 *  
 **/

#include "build_in_parser.h"

#include <cstdio>
#include <cstring>

#include <boost/log/trivial.hpp>

namespace good_coder {
template <typename T> 
int parse(const char* str, T* res, const char* format) {
    if (str == NULL) {
        BOOST_LOG_TRIVIAL(fatal) << "input is null.";
        return -1;
    }

    if (res == NULL) {
        BOOST_LOG_TRIVIAL(fatal) << "output result pointer is null.";
        return -1;
    }

    if (1 == sscanf(str, format, res)) {
        return 0;
    } else {
        BOOST_LOG_TRIVIAL(fatal) << "invalid input's format.";
        return -1;
    }
}

template <typename T>
int parse(const char* str, std::vector<T>* res, const char* format) {
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
        BOOST_LOG_TRIVIAL(fatal) << "iinvalid input's format : array number is less than 1.";
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
    if (1 != sscanf(src, format, &(*res)[cur_idx])) {
        res->clear();
        BOOST_LOG_TRIVIAL(fatal) << "invalid input's format.";
        return -1;
    }
    ++cur_idx;

    while (true) {
        while (*src != '\t' && *src != '\n' && *src != '\0' && *src != ',') {
            ++src;
        }

        if (*src == ',' && *(src + 1) != '\t' && *(src + 1) != '\0' && *(src + 1) != '\n') {
            ++src;
            if (1 != sscanf(src, format, &(*res)[cur_idx])) {
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

int parse(const char* str, int* res) {
    return parse(str, res, "%d");
}

int parse(const char* str, uint32_t* res) {
    return parse(str, res, "%u");
}

int parse(const char* str, float* res) {
    return parse(str, res, "%f");
}

int parse(const char* str, double* res) {
    return parse(str, res, "%lf");
}

int parse(const char* str, uint64_t* res) {
    return parse(str, res, "%llu");
}

int parse(const char* str, std::vector<int>* res) {
    return parse(str, res, "%d");
}

int parse(const char* str, std::vector<float>* res) {
    return parse(str, res, "%f");
}

int parse(const char* str, std::vector<double>* res) {
    return parse(str, res, "%lf");
}

int parse(const char* str, std::vector<uint32_t>* res) {
    return parse(str, res, "%u");
}

int parse(const char* str, std::vector<uint64_t>* res) {
    return parse(str, res, "%llu");
}

int parse(const char* str, char* res, int space) {
    if (str == NULL) {
        BOOST_LOG_TRIVIAL(fatal) << "input is null.";
        return -1;
    }

    if (res == NULL) {
        BOOST_LOG_TRIVIAL(fatal) << "output result pointer is null.";
        return -1;
    }

    const char* src = str;
    int len = 0;
    while (*src != '\t' && *src != '\n' && *src != '\0') {
        src++;
        len++;
    }
    if (len + 1 > space) {
        BOOST_LOG_TRIVIAL(fatal) << "input char* array space overflow.";
        return -1;
    }

    memcpy(res, str, len);
    res[len] = '\0';

    return 0;
}
}
