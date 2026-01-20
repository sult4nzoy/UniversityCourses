#pragma once
#include <iostream>
#include "int_buffer.h"
#include <chrono>
class int_sorted
{
public:

    int_sorted(const int* source, size_t size);
    size_t size() const;
    void insert(int value);
    const int* begin() const;
    const int* end() const;
    int_sorted merge(const int_sorted&merge_with) const;

    // bool isSorted(const int_buffer &obj);


private:

    int_buffer buf;
    int* ptr = nullptr;
    size_t sorted_size = 0;
    int value = 0;
    explicit int_sorted(const int_buffer& obj);
    friend int_sorted sort(const int* begin, const int* end);
    int_sorted();
    int_sorted(int value);

};

int_sorted sort(const int* begin, const int* end);
