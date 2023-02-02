#ifndef NODE_HPP
#define NODE_HPP

#include "custom_string.hpp"

struct node {
    custom_string key;
    double value;

    node(const custom_string &key, double val);
};

#endif