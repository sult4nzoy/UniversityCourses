//
// Created by OmarK on 2025-10-02.
//

#include <vector>
#include <string>
template <typename T, typename COMP = std::less<T>>
class pq {
    public:
    pq();
    pq(COMP comp);

    template <typename IT>
    pq(IT first, IT last, COMP comp = COMP());

    void push(T element);
    T pop();
    bool empty() const;
    size_t size() const;
    auto begin();
    auto front();


    private:
    std::vector<T> data;
    COMP comp;
};


