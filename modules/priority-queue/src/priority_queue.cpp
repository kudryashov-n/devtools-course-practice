// Copyright 2020 Egorov Danil

#include "include/priority_queue.h"

node::node() : key(0), data(0) {}

node::node(int _key = 0) 
    : key(_key), data(0) {}

node::node(int _data = 0)
    : key(0), data(_data) {}

node::node(int _key, int _data)
    : key(_key), data(_data) {}

std::list<node>::iterator priority_queue::get_min_it()
{
    std::list<node>::iterator it = queue.begin();
    std::list<node>::iterator min = it;

    while (it != queue.end())
    {
        if (it->key < min->key)
        {
            min = it;
        }
        ++it;
    }

    return min;
}

std::list<node>::iterator priority_queue::get_max_it()
{
    std::list<node>::iterator it = queue.begin();
    std::list<node>::iterator max = it;

    while (it != queue.end())
    {
        if (it->key > max->key)
        {
            max = it;
        }
        ++it;
    }

    return max;
}

bool priority_queue::is_empty()
{
    return queue.empty();
}

void priority_queue::insert(node _node)
{
    queue.push_back(_node);
}

node* priority_queue::extract_minimum()
{
    if (is_empty()) return nullptr;

    std::list<node>::iterator min = get_min_it();

    node* _node = new node(min->key, min->data);

    return _node;
}

node* priority_queue::extract_maximum()
{
    if (is_empty()) return nullptr;

    std::list<node>::iterator max = get_max_it();

    node* _node = new node(max->key, max->data);

    return _node;
}

bool priority_queue::deleteMin()
{
    if (is_empty()) return false;

    std::list<node>::iterator min = get_min_it();

    queue.erase(min);

    return true;
}

bool priority_queue::deleteMax()
{
    if (is_empty()) return false;

    std::list<node>::iterator max = get_max_it();

    queue.erase(max);

    return true;
}
