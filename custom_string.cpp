/**
 * @file custom_string.cpp
 * @author your name (+ student ID)
 * @date 2023-02-03
 */

#include "custom_string.hpp"
#include <cstring>
#include <iostream>


custom_string::custom_string() {
    content=nullptr;
    length=0;
    capacity=0;
}

custom_string::custom_string(const char *c_str) {
    length=strlen(c_str);
    content=new char[length+1];
    strcpy(content,c_str);
    capacity=length+1;
}

custom_string::~custom_string() {
    delete [] content;
}

custom_string::custom_string(const custom_string &str):custom_string(str.content) {
    
}

custom_string::custom_string(custom_string &&str) : content(str.content), length(str.length),capacity(str.capacity) {
    str.content=nullptr;
}


custom_string &custom_string::operator=(const custom_string &str) {
    if(this->capacity>=str.capacity){
        strcpy(this->content,str.content);
    } else {
        this->content=new char[str.capacity];
        strcpy(this->content,str.content);
        this->capacity = str.capacity;
    }
    this->length=str.length;
    
    return *this;
}

custom_string &custom_string::operator=(custom_string &&str) {
    
    this->content=str.content;
    str.content=nullptr;
    this->capacity=str.capacity;
    str.capacity=0;

    this->length = str.length;
    str.length=0;
    return *this;
}

bool custom_string::operator<(const custom_string &str) const {
    if (std::strcmp(this->content, str.content) < 0) {
        return true;
    }
    return false;
}

bool custom_string::operator==(const custom_string &str) const {
    return std::strcmp(this->content,str.content)==0;
}

// TODO: output stream operator
std::ostream &operator<<(std::ostream &os, const custom_string &str) {
    os<<str.content;
    return os;
}
