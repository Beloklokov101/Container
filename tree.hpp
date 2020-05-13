#ifndef TREE_H
#define TREE_H

#include "container.hpp"
#include "tree_iterator.hpp"

template<typename T>
struct element
{
    T number;
    T height;
    element* left;
    element* right;
};

template<typename T>
class tree: public Container
{
    public:
        void insert(const T& value);
        bool exists(const T& value);
        void remove(const T& value);
        void print();

    protected:
    
    struct element* root;
        
        tree();
        tree(const tree<T>& t);
        void operator=(const tree<T>& t);

        ~tree();

        struct element* take_root() const;

        struct element* create_new_element(const T& new_number);

        //The block instruments for the following methods
        T height(element* el);
        T balance_factor(element* el);
        void check(element* el);

        //Rotates
        struct element* rightrotate(element* el_R);
        struct element* leftrotate(element* el_L);
        struct element* balance(element* el);

        //Curve insert,
        //because initially insert worked by returning a pointer
        //to the element being considered at the time,
        //which is not required in the task
        struct element* paste1(element* el, const T& n);

        //Instruments
        struct element* min_elem(element* el);
        struct element* check_min(element* el);

        //Curve remove for the same reason
        struct element* delete_element(element* el, const T& n);

        //--||--
        void print1(element* el) const;

        element* next(element* el, const element* el_find, bool* flag) const;

        void copy(element* el, tree<T>& t));

        //--||--
        struct element* search1(element* el, const T& n);


        using iterator = tree_iterator<T>;
        using const_iterator = tree_iterator<const T>;

        unsigned int size() const;

        iterator begin() const;
        iterator end() const;

        const_iterator cbegin() const;
        const_iterator cend() const;
};

#endif