/**
 * @file quick_map.cpp
 * @author your name (student ID)
 * @date 2023-02-03
 */

#include "quick_map.hpp"
#include "custom_string.hpp"
#include "node.hpp"
#include <cassert>
#include <iostream>
#include <map>
#include <memory>
#include <utility>
#include<algorithm>

quick_map::quick_map(int quick_access_amount) : quick_access_amount(quick_access_amount) {
    smallest_values=new std::shared_ptr<const node>[quick_access_amount];
    largest_values=new std::shared_ptr<const node>[quick_access_amount];
    internal_map=std::map<custom_string,std::shared_ptr<const node>>();
    node_count=0;
}

// TODO: constructor 2 (gegeven: quick_access_amount initializer)
quick_map::quick_map(int quick_access_amount, std::pair<const custom_string, double> *elements, int length) : quick_access_amount(quick_access_amount) {
    node_count=length;
    for (int i=0; i<length;i++){
        std::shared_ptr<const node> p1(new node(elements[i].first,elements[i].second));
        internal_map[elements[i].first] = p1;
        for (int j = 0; j < quick_access_amount; j++)
        {
            if((p1->value)<((smallest_values[j])->value)){
                std::shared_ptr<const node> temp=smallest_values[i];
                smallest_values[i]=p1;
                p1=temp;
                temp.reset();
            }
            if ((p1->value) < ((largest_values[j])->value)) {
                std::shared_ptr<const node> temp = smallest_values[i];
                smallest_values[i] = p1;
                p1 = temp;
                temp.reset();
            }
        }
        
    }
}

// TODO: destructor
quick_map::~quick_map() {
}

// TODO: node toevoegen aan de quick_map
void quick_map::insert(const custom_string &key, double val) {
    assert(val >= 0);
}

// TODO: node met `key` verwijderen uit de quick_map
double quick_map::remove(const custom_string &key) {
    return -1;
}

// Gegeven: zoek node met `key` in de quick_map
double quick_map::search(const custom_string &key) const {
    auto it = internal_map.find(key);

    if (it != internal_map.end()) {
        return it->second->value;
    }

    return -1;
}

// Gegeven: print de `smallest_values` array
void quick_map::print_smallest_values() const {
    int amount = 0;

    if (node_count >= quick_access_amount) {
        amount = quick_access_amount;
    } else {
        amount = node_count;
    }

    std::cout << amount << " smallest nodes in the tree:" << std::endl;

    for (int i = 0; i < amount; i++) {
        if (smallest_values[i] != nullptr) {
            std::cout << "Node with key: " << smallest_values[i]->key << " and value: " << smallest_values[i]->value << std::endl;
        } else {
            std::cout << "nullptr" << std::endl;
        }
    }
}

// Gegeven: print de `largest_values` array
void quick_map::print_largest_values() const {
    int amount = 0;

    if (node_count >= quick_access_amount) {
        amount = quick_access_amount;
    } else {
        amount = node_count;
    }

    std::cout << amount << " largest nodes in the tree:" << std::endl;

    for (int i = 0; i < amount; i++) {
        if (largest_values[i] != nullptr) {
            std::cout << "Node with key: " << largest_values[i]->key << " and value: " << largest_values[i]->value << std::endl;
        } else {
            std::cout << "nullptr" << std::endl;
        }
    }
}

// TODO: output stream operator
std::ostream &operator<<(std::ostream &os, const quick_map &map) {
    return os;
}
