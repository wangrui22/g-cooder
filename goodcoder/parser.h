#ifndef PARSER_H
#define PARSER_H

#include <memory>
#include <vector>

#include "build_in_parser.h"
#include "custom_parser.h"

namespace good_cooder
{
    class Parser
    {
    public:
        Parser(int max_column = 4096) :_max_column(max_column),_row(0)
        {
            _str_cache.push_back(std::unique_ptr<const char*[]>(new const char*[_max_column]));
            memset(_str_cache[0].get(), 0, sizeof(const char*)*_max_column);
        }

        ~Parser()
        {

        }

        int read_line(const char* buffer)
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
            for(;;)
            {
                while (*src != '\t' && *src != '\n' && *src != '\0') { ++src; }
                if (*src == '\t' && *(src+1) != '\0' && *(src +1) != '\n')
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

        int read_all(const char* buffer)
        {
            return 0;
        }

        template<class T>
        int get_item(const int column, T* res)
        {
            if (_row == 0)
            {
                //TODO get before parse
                return -1;
            }

            if (column > _columns[0]-1)
            {
                //TODO stack overflow 
                return -1;
            }

            return parse(_str_cache[0][column], res);
        }

        template<class T>
        int get_item(const int row, const int column, T* result)
        {

        }

    protected:
    private:
        int _max_column;
        int _row;
        std::vector<int> _columns;
        std::vector<std::unique_ptr<const char*[]>> _str_cache;
    };
}

#endif // !PARSER_H_
