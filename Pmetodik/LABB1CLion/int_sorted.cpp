#include "int_sorted.h"

int_sorted::int_sorted(const int* source, size_t size) : buf(source, size)
{
    sort(source, source + size);
}

int_sorted::int_sorted(const int_buffer& obj) : buf(obj)
{
}

int_sorted::int_sorted() : buf(0)
{
}

int_sorted::int_sorted(int value) : buf(1)
{
}

size_t int_sorted::size() const
{
    return this->buf.size();
}

void int_sorted::insert(int value)
{
    int_sorted is(&value, 1);
    *this = merge(is);
}

const int* int_sorted::begin() const
{
    return this->buf.begin();
}

const int* int_sorted::end() const
{
    return this->buf.end();
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const
{
    int_buffer buffer = int_buffer(this->size() + merge_with.size());

    int* index = buffer.begin();
    const int* a = this->begin();
    const int* b = merge_with.begin();
    while (a != this->end() && b != merge_with.end())
    {
        if (*a < *b)
        {
            *index++ = *a++;
        }
        else
        {
            *index++ = *b++;
        }
    }
    while ( a != this->end())
    {
        *index++ = *a++;
    }
    while ( b != merge_with.end())
    {
        *index++ = *b++;
    }

    return int_sorted(buffer);
}

// bool isSorted(const int_sorted &obj)
// {
//     if (obj.begin() == obj.end())
//     {
//         std::cout << "Object is empty" << std::endl;
//         return false;
//     }
//
//     const int* a = obj.begin();
//     while (a != obj.end())
//     {
//         const int* b = a + 1;
//         if (a > b)
//         {
//             std::cout << "Arrayen är inte sorterad";
//             return false;
//         }
//         b = a;
//     }
//     std::cout << "Arrayen är sorterad";
//     return true;
// }

int_sorted sort(const int* begin, const int* end)
{
    int_buffer buffer = int_buffer(end - begin);

    if (begin == end)
    {
        return int_sorted();
    }
    if (begin == end - 1)
    {
        return int_sorted(*begin);
    }

    ptrdiff_t middle = (end - begin) / 2;

    const int* mid = begin + middle;
    return sort(begin, mid).merge(sort(mid,end));
}



