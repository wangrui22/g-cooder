#include "parser.h"

namespace good_cooder
{
    Parser::Parser(int max_column ) : _max_column(max_column), _row(0)
    {
        _str_cache.push_back(std::unique_ptr<const char*[]>(new const char*[_max_column]));
        memset(_str_cache[0].get(), 0, sizeof(const char*)*_max_column);
    }

    Parser::~Parser()
    {
    }

    int Parser::read_line(const char* buffer)
    {
        if (buffer == nullptr)
        {
            //TODO log invalid input
            return -1;
        }

        const char* src = buffer;
        if (*src == '\n' || *src == '\0')
        {
            //TOOD log empty buffer
            return -1;
        }

        _row = 1;
        _columns.clear();
        _columns.resize(1);

        int col_idx = 0;
        _str_cache[0][col_idx++] = src;
        for (;;)
        {
            while (*src != '\t' && *src != '\n' && *src != '\0') { ++src; }
            if (*src == '\t' && *(src + 1) != '\0' && *(src + 1) != '\n')
            {
                _str_cache[0][col_idx++] = ++src;
            }
            else
            {
                break;
            }
        }

        _columns[0] = col_idx;

        return 0;
    }
}