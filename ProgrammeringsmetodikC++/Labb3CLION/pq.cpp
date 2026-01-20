//
// Created by OmarK on 2025-10-02.
//

#include "pq.h"

#include <algorithm>
#include <iostream>

template<typename T, typename COMP>
pq<T, COMP>::pq()
{
}

template<typename T, typename COMP>
pq<T, COMP>::pq(COMP comp) : comp(comp)
{
}

template<typename T, typename COMP>
template<typename IT>
pq<T, COMP>::pq(IT first, IT last, COMP comp) : data(first, last)
{
    std::sort(data.begin(), data.end(), comp);
}

template<typename T, typename COMP>
void pq<T, COMP>::push(T element)
{
    data.push_back(element);
    std::sort(data.begin(), data.end(), comp);
}

template<typename T, typename COMP>
T pq<T, COMP>::pop()
{
    T top = data.front();
    data.erase(data.begin());
    return top;

}

template<typename T, typename COMP>
bool pq<T, COMP>::empty() const
{
    return data.empty();
}

template<typename T, typename COMP>
size_t pq<T, COMP>::size() const
{
    return data.size();
}

template<typename  T, typename COMP>
auto pq<T, COMP>::begin() {
    return data.begin();
}

template<typename T, typename COMP>
auto pq<T, COMP>::front() {
    return data.front();
}
