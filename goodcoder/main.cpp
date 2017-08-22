#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "parser.h"

int main(int argc, char* argv[])
{
    using namespace  good_cooder;

    const char* test = "comlog\t12345678\t3.1415926\t18446744073709551615\tgoodcoder\t3:12,23,34\t10 12 23\t3:1 2 3,3 4 5,7 8 9\n";

    Parser parser;
    parser.read_line(test);
    char* item_c = new char[256];
    double item_f;
    int item_i;
    uint64_t item_llu;
    std::vector<int> item_is;
    Point3 pt;
    std::vector<Point3> pts;

    if (0 == parser.get_item(0, item_c))
    {
        printf("%s\n", item_c);
    }

    if (0 == parser.get_item(1, &item_i))
    {
        printf("%i\n" , item_i);
    } 

    if (0 == parser.get_item(2, &item_f))
    {
        printf("%lf\n", item_f);
    }

    if (0 == parser.get_item(3, &item_llu))
    {
        printf("%llu\n", item_llu);
    }

    if (0 == parser.get_item(4, item_c))
    {
        printf("%s\n", item_c);
    }

    if (0 == parser.get_item(5, &item_is))
    {
        for (auto it = item_is.begin() ;it != item_is.end() ; ++it)
        {
            printf("%d ", *it);
        }
        printf("\n");
    }

    if (0 == parser.get_item(6, &pt))
    {
        printf("point : %f %f %f\n", pt.x , pt.y , pt.z);
    }

    if (0 == parser.get_item(7, &pts))
    {
        for (auto it = pts.begin(); it != pts.end(); ++it)
        {
            printf("point : %f %f %f , ", (*it).x, (*it).y, (*it).z);
        }
        printf("\n");
    }

    return 0;
}