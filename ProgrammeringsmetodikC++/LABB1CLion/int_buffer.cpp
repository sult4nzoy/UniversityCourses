#include "int_buffer.h"

int_buffer::int_buffer(size_t size) : ptr(new int[size]), buffer_size(size)
{
}

int_buffer::int_buffer(const int* source, size_t size) : int_buffer(size)//Overloaded constructor
{
    std::copy_n(source, size, ptr);
}

int_buffer::int_buffer(const int_buffer& rhs) : int_buffer(rhs.begin(), rhs.size())// copy construct
{
}

int_buffer::int_buffer(int_buffer&& rhs) noexcept //Move constructor
{
    swap(rhs);
}


int_buffer& int_buffer::operator=(const int_buffer& rhs)
{
    int_buffer temp(rhs);
    swap(temp);
    return *this;
}


int_buffer& int_buffer::operator=(int_buffer&& rhs) noexcept  //Move assign
{
    swap(rhs);
    return *this;
}

int& int_buffer::operator[](size_t index)
{
    return this->ptr[index];
}

const int& int_buffer::operator[](size_t index) const
{
    return this->ptr[index];
}

size_t int_buffer::size() const
{
    return this->buffer_size;
}

int* int_buffer::begin()
{
    return this->ptr;
}

int* int_buffer::end()
{
    return this->ptr + this->buffer_size;
}

const int* int_buffer::begin() const
{
    return this->ptr;
}

const int* int_buffer::end() const
{
    return this->ptr + this->buffer_size;
}

int_buffer::~int_buffer()
{
    delete[] this->ptr;
}

void int_buffer::swap(int_buffer& obj)
{
    std::swap(obj.buffer_size, this->buffer_size);
    std::swap(obj.ptr, this->ptr);
}