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
        Parser(int max_column = 4096);
        ~Parser();
        int read_line(const char* buffer);


        int read_all(const char* buffer);

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
