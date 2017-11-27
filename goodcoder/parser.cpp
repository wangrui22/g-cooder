/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved 
 * 
 **************************************************************************/
 
 /**
 * @file parser.cpp
 * @author wangrui(wangrui22@baidu.com)
 * @date 2017/08/21
 * @version 0.0.1 
 * @brief word parser interface implementation
 *  
 **/


#include "parser.h"
#include <cstring>

namespace good_coder {
Parser::Parser(): _row(0), _column(0) {
    memset(_str_cache, 0, sizeof(const char*) * MAX_COLUMN);
}

Parser::~Parser() {}

int Parser::read_line(const char* buffer) {
    if (buffer == NULL) {
        BOOST_LOG_TRIVIAL(fatal) << "input line buffer is null.";
        return -1;
    }

    const char* src = buffer;

    if (*src == '\n' || *src == '\0') {
        BOOST_LOG_TRIVIAL(fatal) << "input line buffer is empty.";
        return -1;
    }

    _row = 1;
    _column = 1;

    int col_idx = 0;
    _str_cache[col_idx++] = src;

    while (true) {
        while (*src != '\t' && *src != '\n' && *src != '\0') {
            ++src;
        }

        if (*src == '\t' && *(src + 1) != '\t' && *(src + 1) != '\n' && *(src + 1) != '\0') {
            _str_cache[col_idx++] = ++src;
        } else {
            break;
        }
    }

    _column = col_idx;

    BOOST_LOG_TRIVIAL(info) << "read line buffer success.";

    return 0;
}
}