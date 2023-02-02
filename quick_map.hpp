#ifndef QUICK_MAP_HPP
#define QUICK_MAP_HPP

#include "custom_string.hpp"
#include "node.hpp"
#include <map>
#include <memory>
#include <utility>

class quick_map {
  private:
    std::map<custom_string, std::shared_ptr<const node>> internal_map;

    std::shared_ptr<const node> *smallest_values;
    std::shared_ptr<const node> *largest_values;

    const int quick_access_amount;
    int node_count;

  public:
    quick_map() = delete;
    quick_map(int quick_access_amount);
    quick_map(int quick_access_amount, std::pair<const custom_string, double> *elements, int length);
    quick_map(const quick_map &) = delete;
    quick_map(quick_map &&) = delete;
    ~quick_map();

    void insert(const custom_string &key, double val);
    double remove(const custom_string &key);
    double search(const custom_string &key) const;
    void print_smallest_values() const;
    void print_largest_values() const;

    friend std::ostream &operator<<(std::ostream &os, const quick_map &map);
};

#endif