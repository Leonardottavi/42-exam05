#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "provided/tree_bag.hpp"
#include "provided/searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag {
public:
    searchable_tree_bag() {}
    searchable_tree_bag(const searchable_tree_bag& src) : tree_bag(src), searchable_bag(src) {}
    searchable_tree_bag& operator=(const searchable_tree_bag& src) {
        if (this != &src) tree_bag::operator=(src);
        return *this;
    }
    ~searchable_tree_bag() {}

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

#endif
