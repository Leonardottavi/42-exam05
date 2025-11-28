#pragma once
#include "provided/tree_bag.hpp"
#include "provided/searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag {
public:
    bool has(int item) const {
        node* current = tree;
        while (current) {
            if (item < current->value) current = current->l;
            else if (item > current->value) current = current->r;
            else return true;
        }
        return false;
    }
};
