#include <iostream>
unsigned int factorial_iterative(unsigned int n)
{
    unsigned int f = 1;
    for (unsigned int i = n; i > 0; i--)
    {
        f *= i;
    } 
    return f;
}

unsigned int factorial_recursive(unsigned int n)
{
    //base case
    if (n == 1 || n == 0)
    {
        return 1;
    }

    return n * factorial_recursive(n - 1);
}

unsigned int factorial_recursive_tail(unsigned int n, unsigned int result)
{
    if (n <= 1) 
    {
        return result;
    }
    return factorial_recursive_tail(n - 1, result * n);
}

unsigned int factorial_wrapper (unsigned int n)
{
    return factorial_recursive_tail(n, 1);
}

void move(char src, char dst)
{
    std::cout << "Move från " << src << " to " << dst << std::endl;
}

unsigned int counter(unsigned int n)
{
    return n++;
}

void hanoi(unsigned int n, char src, char pinne1, char pinne2)
{
    if (n == 0) //base case
    {
        return;
    }

    hanoi(n-1, src, pinne2, pinne1);
    move(src, pinne2);
    hanoi(n-1, pinne1, src, pinne2);
    counter(1);

}

int main()
{
    hanoi(5, 'a', 'b', 'c');
    std::cout << "Löste hanoi på " << counter(0) << " moves." << std::endl; 

    return 0;

}