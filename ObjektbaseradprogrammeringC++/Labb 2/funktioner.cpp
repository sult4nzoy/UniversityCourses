#include "linked_list.h"

linked_list::linked_list() // default
{
    head = nullptr;
    tail = nullptr;
}

linked_list::node::node(double value) // noden
{
    this->value = value;
    next = nullptr;
    prev = nullptr;
}


linked_list::linked_list(const linked_list &src) : head(nullptr), tail(nullptr)
{
    node *ptr = src.head;

    while (ptr != nullptr)
    {
        push_back(ptr->value);
        ptr = ptr->next;
    }
}

void linked_list::push_back(double value)
{
    if (is_empty())
    {
        head = new node(value);
        tail = head;
    }
    else
    {
        node *ptr = new node(value);
        ptr->prev = tail;
        tail->next = ptr;
        tail = ptr;
    }
}

void linked_list::push_front(double value)
{
    if (is_empty())
    {
        head = new node(value);
        tail = head;
    }
    else
    {
        node *ptr = new node(value);
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
}

void linked_list::print() const
{
    node *ptr = head;

    if (head == nullptr)
    {
        std::cout << "listan är tom" << std::endl;
    }

    else
    {
        for (ptr = head; ptr != nullptr; ptr = ptr->next)
        {
            std::cout << ptr->value << " ";
        }
        std::cout << std::endl;
    }
}

void linked_list::print_reverse() const
{
    node *ptr = tail;

    for (ptr = tail; ptr != nullptr; ptr = ptr->prev)
    {
        std::cout << ptr->value << " ";
    }
    std::cout << std::endl;
}

size_t linked_list::size() const
{
    size_t count = 0;

    node *ptr = head;

    if (ptr == nullptr)
    {
        std::cout << "listan är tom" << std::endl;
        return count;
    }

    else
    {
        while (ptr != nullptr)
        {
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}

bool linked_list::is_empty() const
{
    return head == nullptr && tail == nullptr;
}

void linked_list::remove(size_t pos)
{
    if (is_empty())
    {
        return;
    }

    if (pos == 0)
    {
        pop_front();
    }

    if (pos >= size() - 1)
    {
        pop_back();
    }

    node *ptr = head;

    for (size_t index = 0; index < pos && ptr != nullptr; index++)
    {
        ptr = ptr->next;
    }

    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;

    delete ptr;
}

void linked_list::insert(double value, size_t pos)
{
    if (pos == 0)
    {
        push_front(value);
    }

    if (pos >= size())
    {
        push_back(value);
    }

    node *ptr = head;
    for (size_t index = 0; index < pos && ptr != nullptr; index++)
    {
        ptr = ptr->next;
    }

    node *ptrski = new node(value);
    ptrski->next = ptr;
    ptrski->prev = ptr->prev;
    ptr->prev->next = ptrski;
    ptr->prev = ptrski;
}

double linked_list::front() const
{
    if (head != nullptr)
    {
        return head->value;
    }
    else
    {
        std::cout << "listan är tom" << std::endl;
        return 0;
    }
}

double linked_list::back() const
{
    if (tail != nullptr)
    {
        std::cout << "värdet längst bak på listan: " << tail->value << std::endl;
        return tail->value;
    }
    else
    {
        std::cout << "listan är tom" << std::endl;
        return 0;
    }
}

double linked_list::pop_back()
{
    if (is_empty())
    {
        std::cout << "listan är tom" << std::endl;
        return 0;
    }

    node *ptr = tail;
    double value = ptr->value;

    if (tail->prev != nullptr)
    {
        tail = tail->prev;
        tail->next = nullptr;
    }
    else
    {
        head = nullptr;
        tail = nullptr;
    }

    delete ptr;
    return value;
}

double linked_list::pop_front()
{
    if (is_empty())
    {
        std::cout << "listan är tom" << std::endl;
        return 0;
    }

    node *ptr = head;
    double value = ptr->value;

    if (head->next != nullptr)
    {
        head = head->next;
        head->prev = nullptr;
    }
    else
    {
        head = nullptr;
        tail = nullptr;
    }

    delete ptr;
    return value;
}

linked_list &linked_list::operator=(const linked_list &rhs)
{

    if (this != &rhs)
    {
        while (!is_empty())
        {
            pop_front();
        }

        node *ptr = rhs.head;

        while (ptr != nullptr)
        {
            push_back(ptr->value);
            ptr = ptr->next;
        }
    }

    return *this;
}

linked_list::~linked_list()
{
    if (is_empty())
    {
        return;
    }

    while (head != nullptr)
    {
        pop_front();
    }
}

linked_list &linked_list::operator+=(const linked_list &rhs)
{

    if (this == &rhs)
    {
        linked_list tempList(*this);
        node *ptr = tempList.head;
        
        while (ptr != nullptr)
        {
            push_back(ptr->value);
            ptr = ptr->next;
        }
    }
    else
    {
        node *ptr = rhs.head;
        while (ptr != nullptr)
        {
            push_back(ptr->value);
            ptr = ptr->next;
        }
    }

    return *this;
}

double linked_list::at(size_t pos) const
{
    if (is_empty())
    {
        return 0;
    }
    if (pos == 0)
    {
        return 0;
    }

    node *ptr = head;
    for (size_t index = 0; index < pos; index++)
    {
        if (is_empty())
        {
            std::cout << "listan är tom" << std::endl;
        }
        ptr = ptr->next;
    }
    return ptr->value;
}