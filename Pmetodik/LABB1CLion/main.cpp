
#include "int_sorted.h"
void printIntSorted(const int_sorted& a)
{
    for (auto e : a )
    {
        std::cout << e << " ";
    }
}

void printIntBuffer(const int_buffer& obj)
{
    for (auto e : obj)
    {
        std::cout << e << ", ";
    }
}

void selectionSort(int_buffer &buffer)
{
    const size_t size = buffer.size();
    for (size_t i = 0; i < size; i++) {
        size_t idx = i;
        for (size_t j = i + 1; j < size; j++)
        {
            if (buffer[j] < buffer[idx])
            {
                idx = j;
            }
        }
        std::swap(buffer[i], buffer[idx]);
    }
}

int_buffer f(int_buffer buf)
{
    int count = 0;
    for (int* i = buf.begin(); i != buf.end(); i++, count++)
    {
        *i = count;
    }

    for (const int* i = buf.begin(); i != buf.end(); i++)
    {
        std:: cout << *i << ", ";
    }

    return int_buffer(buf);
}

int main()
{
    std::cout << "______________________________" << std::endl;
    std::cout << "Testing f function (r-value)" << std::endl;
    int_buffer buf(10);
    int_buffer B0 = f(buf);
    std::cout << std::endl;
    std::cout << "______________________________" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "______________________________" << std::endl;
    std::cout << "Testing: Assignment operator= " << std::endl;
    int_buffer B1(10);
    int_buffer B2(5);
    B2 = B1;
    for (int i = 0; i < 10; i++)
    {
        B2[i] = i;
    }
    printIntBuffer(B2);
    std::cout << std::endl;
    std::cout << "______________________________" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "______________________________" << std::endl;
    std::cout << "Testing: Move assignment operator" << std::endl;

    int_buffer B3(0);

    B3 = int_buffer(10);
    for (int i = 0; i < 10; i++)
    {
        B3[i] = i;
    }
    printIntBuffer(B3);
    std::cout << std::endl;
    std::cout << "______________________________" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "______________________________" << std::endl;

    std::cout << "Testing: Copy constructor" << std::endl;
    int_buffer B4(f(int_buffer(10)));
    // int_buffer B4(10);

    int_buffer B5 = B4;
    for (int i = 0; i < 10; i++)
    {
        B5[i] = i;
    }
    printIntBuffer(B5);
    std::cout << std::endl;
    std::cout << "______________________________" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << "______________________________" << std::endl;
    std::cout << "Testing: Move construct" << std::endl;
    int_buffer B6(10);
    int_buffer B7(std::move(B6));
    for (int i = 0; i < 10; i++)
    {
        B7[i] = i;
    }
    printIntBuffer(B7);
    std::cout << std::endl;
    std::cout << "B6 size after moving " << B6.size() << std::endl;
    std::cout << "______________________________" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << "______________________________" << std::endl;
    std::cout << "Testing: insert func" << std::endl;
    int_buffer Test1(10);
    for (int i = 0; i < 10; i++)
    {
        Test1[i] = i;
    }
    int_sorted B8(Test1.begin(), Test1.size());
    B8.insert(5);
    B8.insert(100);
    B8.insert(1);
    printIntSorted(B8);
    std::cout << std::endl;
    std::cout << "______________________________" << std::endl;


    std::cout << std::endl;


    std::cout << "______________________________" << std::endl;
    std::cout << "Creating a int_buffer object with 100k elements to test sort vs selectionsort" << std::endl;
    int_buffer Test2(100000);
    for (size_t i = 0; i < Test2.size(); i++)
    {
        size_t randomValue = rand() % Test2.size();
        Test2[i] = randomValue;
    }
    const auto startVanligSort = std::chrono::steady_clock::now();
    int_sorted Test3(Test2.begin(), Test2.size());
    const auto endVanligSort = std::chrono::steady_clock::now();
    const std::chrono::duration<double> diffVanligSort = endVanligSort - startVanligSort;



    std::cout << "Tiden det tog att sortera 100000 element (vanliga sort): " << diffVanligSort.count() << "s" << std::endl;
    //first test: 0.239657s
    //second test: 0.261537s
    //third test: 0.237229s


    int_buffer Test4(100000);
    for (size_t i = 0; i < Test4.size(); i++)
    {
        size_t randomValue = rand() % Test4.size();
        Test4[i] = randomValue;
    }
    const auto startSelectionSort = std::chrono::steady_clock::now();
    selectionSort(Test4);
    const auto endSelectionSort = std::chrono::steady_clock::now();
    const std::chrono::duration<double> diffSelectionSort = endSelectionSort - startSelectionSort;
    std::cout << "Tiden det tog att sortera 100000 element (selection sort): " << diffSelectionSort.count() << "s" << std::endl;
    std::cout << "______________________________" << std::endl;
    return 0;
}