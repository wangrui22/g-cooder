/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved 
 * 
 **************************************************************************/
 
 /**
 * @file custom_parser.h
 * @author wangrui(wangrui22@baidu.com)
 * @date 2017/08/21
 * @version 0.0.1 
 * @brief custom parser declaration
 *  
 **/

#ifndef GOODCODER_CUSTOM_PARSER_H
#define GOODCODER_CUSTOM_PARSER_H

#include <stdint.h>
#include <vector>

namespace good_coder {
struct Point3 {
    float x;
    float y;
    float z;
};

// {x y z}
int parse(const char* str, Point3* res);
//{num:x y z , x y z , x y z , }
int parse(const char* str, std::vector<Point3>* res);
}

#endif