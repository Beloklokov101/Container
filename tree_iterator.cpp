#include <iostream>
#include "tree_iterator.hpp"
#include "tree.hpp"



template<typename T>
tree_iterator<T>::tree_iterator(): el(nullptr)
{

}

template<typename T>
tree_iterator<T>::tree_iterator(element* el): el(el)
{

}

template<typename T>
tree_iterator<T>::reference tree_iterator<T>::operator*() const
{
    return el->number;
}

/*
template<typename T>
tree_iterator<T>& tree_iterator<T>::operator++()
{
    el = 
}
*/