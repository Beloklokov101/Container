#ifndef TREE_IT_H
#define TREE_IT_H

#include <iostream>
#include <iterator>
#include "tree.hpp"


template<typename T>
class tree_iterator
{
protected:
    element* el;

public:

    using iterator_category = std::forward_iterator_tag;

    using value_type = T;
    using pointer = T*;
    using reference = T&;

    using difference_type = std::ptrdiff_t;

    tree_iterator();
    tree_iterator(element* el);

    reference operator*() const;

    tree_iterator<T>& operator++();
    tree_iterator<T>& operator++(int);

    bool operator==(const tree_iterator<T>& it) const;
    bool operator!=(const tree_iterator<T>& it) const;


};

#endif