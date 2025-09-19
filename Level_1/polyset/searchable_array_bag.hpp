#pragma once
#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag {
public:
    bool has(int item) const {
        for (int i = 0; i < size; i++) if (data[i] == item) return true;
        return false;
    }
};
