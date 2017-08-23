#include "custom_parser.h"
#include <stdio.h>

namespace good_cooder {

int parse(const char *str, Point3 *res) {
  if (str == nullptr) {
    // TODO log
    return -1;
  }

  if (res == nullptr) {
    // TODO log
    return -1;
  }

  if (3 == sscanf(str, "%f%f%f", &res->x, &res->y, &res->z)) {
    return 0;
  } else {
    // TODO log
    return -1;
  }
}

int parse(const char *str, std::vector<Point3> *res) {
  if (str == nullptr) {
    // TODO log
    return -1;
  }

  if (res == nullptr) {
    // TODO log
    return -1;
  }

  int num = 0;
  if (1 != sscanf(str, "%d[^:]", &num)) {
    // TODO log
    return -1;
  }

  if (num < 1) {
    // TODO log
    return -1;
  }

  const char *src = str;
  while (*src++ != ':') {
  }
  if (*src == '\t' || *src == '\n' || *src == '\0') {
    // TODO log
    return -1;
  }

  res->clear();
  res->resize(num);
  int cur_idx = 0;
  if (3 != sscanf(src, "%f%f%f", &(*res)[cur_idx].x, &(*res)[cur_idx].y,
                  &(*res)[cur_idx].z)) {
    res->clear();
    return -1;
  }
  ++cur_idx;

  for (;;) {
    while (*src != '\t' && *src != '\n' && *src != '\0' && *src != ',') {
      ++src;
    }
    if (*src == ',' && *(src + 1) != '\t' && *(src + 1) != '\0' &&
        *(src + 1) != '\n') {
      if (3 != sscanf(++src, "%f%f%f", &(*res)[cur_idx].x, &(*res)[cur_idx].y,
                      &(*res)[cur_idx].z)) {
        res->clear();
        return -1;
      }
      ++cur_idx;
    } else {
      break;
    }
  }

  if (cur_idx != num) {
    res->clear();
    return -1;
  }

  return 0;
}
}