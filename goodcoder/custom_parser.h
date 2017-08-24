#ifndef CUSTOM_PARSER_H
#define CUSTOM_PARSER_H

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