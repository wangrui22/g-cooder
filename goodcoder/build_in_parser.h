/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved 
 * 
 **************************************************************************/
 
 /**
 * @file build_in_parser.h
 * @author wangrui(wangrui22@baidu.com)
 * @date 2017/08/21
 * @version 0.0.1 
 * @brief build in parser declaration
 *  
 **/

#ifndef GOODCODER_BUILD_IN_PARSER_H
#define GOODCODER_BUILD_IN_PARSER_H

#include <stdint.h>
#include <vector>

namespace good_coder {
int parse(const char* str, int* res);
int parse(const char* str, uint32_t* res);
int parse(const char* str, float* res);
int parse(const char* str, double* res);
int parse(const char* str, uint64_t* res);
int parse(const char* str, char* res, int space);

//{num:item1,item2,item3...}
int parse(const char* str, std::vector<int>* res);
int parse(const char* str, std::vector<uint32_t>* res);
int parse(const char* str, std::vector<float>* res);
int parse(const char* str, std::vector<double>* res);
int parse(const char* str, std::vector<uint64_t>* res);
}

#endif
