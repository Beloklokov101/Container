#include <iostream>
#include "tree.hpp"

using std::cin;
using std::cout;
using std::endl;



template<typename T>
void tree<T>::insert(const T& value)
{
    struct element* el = paste1(root, n);
}

template<typename T>
bool tree<T>::exists(const T& value)
{
    return (search1(root, n))?true:false;
};

template<typename T>
void tree<T>::remove(const T& value)
{
    struct element* el = delete_element(root, n);
}

template<typename T>
void tree<T>::print()
{
    print1(root);
}



template<typename T>
tree<T>::tree()
{

}

template<typename T>
tree<T>::tree(const tree<T>& t)
{
    copy(t.take_root(), *this);
}

template<typename T>
void tree<T>::operator=(const tree<T>& t)
{
    while (root)
    {
        root = delete_element(root, root->number);
    }

    copy(t.take_root(), *this);
} 



template<typename T>
tree<T>::~tree()
{
    //МОЖЕТ БЫТЬ НЕ ТАК
    while (root)
    {
        root = delete_element(root, root->number);
    }
}

template<typename T>
struct element* tree<T>::take_root() const
{
    return root;
}

template<typename T>
struct element* tree<T>::create_new_element(const T& new_number)
{
    struct element* elem = new struct element;
    elem->number = new_number;
    elem->left = NULL;
    elem->right = NULL;
    elem->height = 1;
    return elem;
}

template<typename T>
T tree<T>::height(element* el)
{
    T h;
    h = el?el->height:0;
    return h;
}

template<typename T>
T tree<T>::balance_factor(element* el)
{
    T delta;
    delta = height(el->right) - height(el->left);
    return delta;
}

template<typename T>
void tree<T>::check(element* el)
{
    T hl = height(el->left);
    T hr = height(el->right);
    el->height = (hl>hr?hl:hr) + 1;
}

template<typename T>
struct element* tree<T>::rightrotate(element* el_R)
{
    element* el_L = el_R->left;
    el_R->left = el_L->right;
    el_L->right = el_R;
    check(el_R);
    check(el_L);
    return el_L;
}

template<typename T>
struct element* tree<T>::leftrotate(element* el_L)
{
    element* el_R = el_L->right;
    el_L->right = el_R->left;
    el_R->left = el_L;
    check(el_L);
    check(el_R);
    return el_R;
}

template<typename T>
struct element* tree<T>::balance(element* el)
{
    check(el);
    if (balance_factor(el) == 2)
    {
        if (balance_factor(el->right) < 0)
        {
            el->right = rightrotate(el->right);
        }
        struct element* el0 = leftrotate(el);
        return el0;
    }
    if (balance_factor(el) == -2)
    {
        if (balance_factor(el->left) > 0)
        {
            el->left = leftrotate(el->left);
        }
        struct element* el2 = rightrotate(el);
        return el2;
    }
    return el;
}

template<typename T>
struct element* tree<T>::paste1(element* el, const T& n)
{
    if(!el)
    {
        struct element* el0 = create_new_element(n);
        cout << "create new number = " << el0->number << endl;
        root = el0;
        return el0;
    }
    if(n < el->number)
    {
        el->left = paste1(el->left, n);
    }
    else
    {
        el->right = paste1(el->right, n);
    }
    struct element* el2 = balance(el);
    root = el2;
    return el2;
}

template<typename T>
struct element* tree<T>::min_elem(element* el)
{
    struct element* el0;
    if(el->left)
    {
        el0 = min_elem(el->left);
    }
    else
    {
        el0 = el;
    }
    return el0;
}

template<typename T>
struct element* tree<T>::check_min(element* el)
{
    if(el->left == 0)
    {
        return el->right;
    }
    el->left = check_min(el->left);
    struct element* el0 = balance(el);
    return el0;
}

template<typename T>
struct element* tree<T>::delete_element(element* el, const T& n)
{
    if(!el) return NULL;
    if(n < el->number)
    {
        el->left = delete_element(el->left, n);
    }
    else if(n > el->number)
    {
        el->right = delete_element(el->right, n);
    }
    else
    {
        struct element* el_L = el->left;
        struct element* el_R = el->right;
        cout << "delete number = " << el->number << endl;
        delete el;
        if(!el_R)
        {
            return el_L;
        }
        struct element* min = min_elem(el_R);
        min->right = check_min(el_R);
        min->left = el_L;
        struct element* el0 = balance(min);
        root = el0;
        return el0;
    }
    struct element* el0 = balance(el);
    root = el0;
    return el0;
}

template<typename T>
void tree<T>::print1(element* el) const
{
    if(!el->left)
    {
        cout << "Number " << el->number << endl;
    }
    else
    {
        print1(el->left);
        cout << "Number " << el->number << endl;
    }
    if(el->right)
    {
        print1(el->right);
    }
}

template<typename T>
element* tree<T>::next(element* el, const element* el_find, bool* flag) const
{
    if(!el->left)
    {
        if (el == el_find)
        {
            *flag = 1;
        }

        if (*flag == 1)
        {
            return el;
        }
    }
    else
    {
        if (el == el_find)
        {
            *flag = 1;
        }

        if (*flag == 1)
        {
            return el;
        }
        
        next(el->left, el_find, flag);
    }
    if(el->right)
    {
        next(el->right, el_find, flag);
    }
}


template<typename T>
void tree<T>::copy(element* el, tree<T>& t)
{
    if(!el->left)
    {
        t.insert(el->number);
    }
    else
    {
        print1(el->left);
        t.insert(el->number);
    }
    if(el->right)
    {
        print1(el->right);
    }
}


template<typename T>
struct element* tree<T>::search1(element* el, const T& n)
{
    struct element* el0;
    if(!el) return NULL;
    if(n < el->number)
    {
        el0 = search1(el->left, n);
    }
        else if(n > el->number)
        {
            el0 = search1(el->right, n);
        }
            else
            {
                el0 = el;
            }
    return el0;
}

//поменять инты на Т