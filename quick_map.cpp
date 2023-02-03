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

quick_map::quick_map(int quick_access_amount, std::pair<const custom_string, double> *elements, int length) : quick_access_amount(quick_access_amount) {
    node_count=length;
    for (int i=0; i<length;i++){
        insert(elements[i].first,elements[i].second);
    }
}

quick_map::~quick_map() {
    for(int i=0;i<quick_access_amount;i++){
        smallest_values[i].reset();
        largest_values[i].reset();
    }
    for (auto it = internal_map.begin(); it != internal_map.end(); it++) {
        it->second.reset();
    }
}

void quick_map::insert(const custom_string &key, double val) {
    assert(val >= 0);
    std::shared_ptr<const node> p1=std::shared_ptr<const node>(new node(key, val));
    internal_map[key] = p1;
    for (int i = 0; i < quick_access_amount; i++) {
        std::shared_ptr<const node> p2 = p1;
        if ((smallest_values[i] == nullptr || p1->value) < ((smallest_values[i])->value)) {
            std::shared_ptr<const node> temp = smallest_values[i];
            smallest_values[i] = p1;
            p1 = temp;
            temp.reset();
        }
        if (largest_values[i] == nullptr || (p2->value) < ((largest_values[i])->value)) {
            std::shared_ptr<const node> temp = largest_values[i];
            smallest_values[i] = p2;
            p1 = temp;
            temp.reset();
        }
        p2.reset();
    }
    p1.reset();
    node_count++;
}

// TODO: node met `key` verwijderen uit de quick_map
double quick_map::remove(const custom_string &key) {
    if(quick_map::search(key)==-1){
        return -1;
    }
    node_count--;
    
    auto it =internal_map.begin();
    std::shared_ptr<const node> p1 = it->second;
    while(!(p1->key==key)){
        it++;
        p1=it->second;
    }
    internal_map[p1->key].reset();
    internal_map.erase(key);
    double val=p1->value;
    for(int i=0;i<quick_access_amount;i++){
        
    }
    p1.reset();
    return val;
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

std::ostream &operator<<(std::ostream &os, const quick_map &map) {
    os<<"Map (key:<key, value>)\n";
    for(auto it = map.internal_map.begin();it!=map.internal_map.end();it++){
        os<< it->second->key <<": <"<< it->second->key << ", " << it->second->value <<">";
    }

    return os;
}
