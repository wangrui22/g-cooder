#include "parser.h"
#include "string.h"

namespace good_coder {
Parser::Parser() :  _row(0) {
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
    _columns.clear();
    _columns.resize(1);

    int col_idx = 0;
    _str_cache[col_idx++] = src;

    while (true) {
        while (*src != '\t' && *src != '\n' && *src != '\0') {
            ++src;
        }
        
        if(*src == '\n' || *src == '\0') {
            break;
        }

        if (*src == '\t' && *(src + 1) != '\0' && *(src + 1) != '\n') {
            _str_cache[col_idx++] = ++src;
        } else {
            break;
        }
    }

    _columns[0] = col_idx;

    BOOST_LOG_TRIVIAL(info) << "read line buffer success.";

    return 0;
}
}