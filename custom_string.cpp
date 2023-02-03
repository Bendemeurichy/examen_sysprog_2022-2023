/**
 * @file custom_string.cpp
 * @author your name (+ student ID)
 * @date 2023-02-03
 */

#include "custom_string.hpp"
#include <cstring>
#include <iostream>


custom_string::custom_string() {
}

// TODO: C-string constructor
custom_string::custom_string(const char *c_str) {
    length=strlen(c_str);
    content=new char[length+1];
    content=strcpy(content,c_str);
    
    capacity=length+1;
}

// TODO: destructor
custom_string::~custom_string() {

}

// TODO: copy constructor
custom_string::custom_string(const custom_string &str) {
}

// TODO: move constructor
custom_string::custom_string(custom_string &&str) {
}

// TODO: assignment operator
custom_string &custom_string::operator=(const custom_string &str) {
    return *this;
}

// TODO: move assignment operator
custom_string &custom_string::operator=(custom_string &&str) {
    return *this;
}

// TODO: comparison operator (alfabetische vergelijking)
bool custom_string::operator<(const custom_string &str) const {
    return false;
}

// TODO: equality operator
bool custom_string::operator==(const custom_string &str) const {
    return false;
}

// TODO: output stream operator
std::ostream &operator<<(std::ostream &os, const custom_string &str) {
    return os;
}
