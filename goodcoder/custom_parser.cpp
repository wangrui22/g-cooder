#include "custom_parser.h"
#include <stdio.h>
#include <boost/log/trivial.hpp>

namespace good_coder {

int parse(const char* str, Point3* res) {
    if (str == nullptr) {
        BOOST_LOG_TRIVIAL(fatal) << "input is null.";
        return -1;
    }

    if (res == nullptr) {
        BOOST_LOG_TRIVIAL(fatal) << "output result pointer is null.";
        return -1;
    }

    if (3 == sscanf(str, "%f%f%f", &res->x, &res->y, &res->z)) {
        return 0;
    } else {
        BOOST_LOG_TRIVIAL(fatal) << "invalid input's format.";
        return -1;
    }
}

int parse(const char* str, std::vector<Point3>* res) {
    if (str == nullptr) {
        BOOST_LOG_TRIVIAL(fatal) << "input is null.";
        return -1;
    }

    if (res == nullptr) {
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

    while (*src++ != ':') {
    }

    if (*src == '\t' || *src == '\n' || *src == '\0') {
        BOOST_LOG_TRIVIAL(fatal) << "invalid input's format : empty array.";
        return -1;
    }

    res->clear();
    res->resize(num);
    int cur_idx = 0;

    if (3 != sscanf(src, "%f%f%f", &(*res)[cur_idx].x, &(*res)[cur_idx].y,
                    &(*res)[cur_idx].z)) {
        res->clear();
        BOOST_LOG_TRIVIAL(fatal) << "invalid input's format.";
        return -1;
    }

    ++cur_idx;

    for (;;) {
        while (*src != '\t' && *src != '\n' && *src != '\0' && *src != ',') {
            ++src;
        }

        if (*src == ',' && *(src + 1) != '\t' && *(src + 1) != '\0' &&
                *(src + 1) != '\n') {
            if (3 != sscanf(++src, "%f%f%f", &(*res)[cur_idx].x, &(*res)[cur_idx].y,
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