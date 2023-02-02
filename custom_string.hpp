#ifndef CUSTOM_STRING_HPP
#define CUSTOM_STRING_HPP

#include <cstring>
#include <ostream>

class custom_string {
  private:
    char *content;
    unsigned int length;
    unsigned int capacity;

  public:
    custom_string();
    custom_string(const char *c_str);
    ~custom_string();

    // copy constructor
    custom_string(const custom_string &str);

    // move constructor
    custom_string(custom_string &&str);

    // operators

    custom_string &operator=(const custom_string &str);
    custom_string &operator=(custom_string &&str);
    bool operator<(const custom_string &str) const;
    bool operator==(const custom_string &str) const;
    friend std::ostream &operator<<(std::ostream &os, const custom_string &str);
};

#endif
