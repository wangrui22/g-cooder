#ifndef BUILD_IN_PARSER_H
#define BUILD_IN_PARSER_H

#include <stdint.h>
#include <vector>

namespace good_cooder {
int parse(const char *str, int *res);
int parse(const char *str, uint32_t *res);
int parse(const char *str, float *res);
int parse(const char *str, double *res);
int parse(const char *str, uint64_t *res);
int parse(const char *str, char *res);

//{num:item1,item2,item3...}
int parse(const char *str, std::vector<int> *res);
int parse(const char *str, std::vector<uint32_t> *res);
int parse(const char *str, std::vector<float> *res);
int parse(const char *str, std::vector<double> *res);
int parse(const char *str, std::vector<uint64_t> *res);
}

#endif
