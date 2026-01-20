#include "linked_list.h"

void print_list(linked_list list1);
linked_list merge(linked_list &list1, linked_list &list2);
bool isitSortedOrNot(linked_list &mergedList);

int main()
{

    std::cout << "-----------TEST 1-----------" << std::endl;
    linked_list list1;
    linked_list list2;

    int tempforFIRSTlist = 0;
    int tempforSECONDlist = 0;


    list1.push_back(0);
    list2.push_back(0);
   
    for (int num = 0; num < 9; num++)
    {
        int randomforFIRSTlist = std::rand() % 11;
        tempforFIRSTlist += randomforFIRSTlist;
        list1.push_back(tempforFIRSTlist);

        int randomforSECONDlist = std::rand() % 11;
        tempforSECONDlist += randomforSECONDlist;
        list2.push_back(tempforSECONDlist);
    }
    std::cout << "List 1: " << std::endl;
    list1.print();
    std::cout << "----------------------------" << std::endl;
    std::cout << "List 2: " << std::endl;
    list2.print();
    std::cout << "---------------------------- " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "-----------TEST 2-----------" << std::endl;
    int fifthfromFIRSTlist = list1.at(4);
    int fifthfromSECONDlist = list2.at(4);

    if (fifthfromFIRSTlist > fifthfromSECONDlist)
    {
        list1.remove(4);
        std::cout << "Listora efter vi tagit bort femte siffran (index 4) från lista 1 (då värdet i den noden var större): " << std::endl;
    }
    else if (fifthfromSECONDlist > fifthfromFIRSTlist)
    {
        list2.remove(4);
        std::cout << "Listorna efter vi tagit bort femte siffran (index 4) från lista 2 (då värdet i den noden var större): " << std::endl;
    }
    else
    {
        std::cout << "Femte värdet i båda listorna var likadan " << "(" << fifthfromFIRSTlist << "), " << "därför tar jag bort femte siffran i lista 1" << std::endl;
    }

    std::cout << "List 1: " << std::endl;
    list1.print();
    std::cout << "----------------------------" << std::endl;
    std::cout << "List 2: " << std::endl;
    list2.print();
    std::cout << "----------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "-----------TEST 3-----------" << std::endl;
    linked_list list3;

    if (list1.size() > list2.size())
    {
        std::cout << "Lista 1 var större än lista 2, så vi gör en kopia av lista 1 och lägger in den i lista 3 och skriver ut den baklänges." << std::endl;
        list3 = list1;
        list3.print_reverse();
    }
    else
    {
        std::cout << "Lista 2 var större än lista 1, så vi gör en kopia av lista 2 och lägger in den i lista 3 och skriver ut den baklänges." << std::endl;
        list3 = list2;
        std::cout << "Lista 3: " << std::endl;
        list3.print_reverse();
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "-----------TEST 4-----------" << std::endl;
    int count = 5;
    for (int i = 0; i < count; i++)
    {
        list1.pop_back();
        list1.push_front(list1.pop_back());
    }
    std::cout << "Lista 1 efter vi tagit bort varannan värde:" << std::endl;
    std::cout << "Lista 1:" << std::endl;
    list1.print();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "-----------TEST 5-----------" << std::endl;
    std::cout << "Skriver ut den halverade listan med NYA print funktionen som skapades i efterhand:" << std::endl;
    print_list(list1);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "-----------TEST 6-----------" << std::endl;
    std::cout << "Skriver ut den mergade listan (den har mergat lista 1 och 2)" << std::endl;
    linked_list list4 = merge(list1, list2);
    list4.print();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "-----------TEST 7-----------" << std::endl;
    std::cout << "Är den sorterad?" << std::endl;
    isitSortedOrNot(list4);

    return 0;
}


void print_list(linked_list list1)
{
    list1.print();
}

linked_list merge(linked_list &list1, linked_list &list2)
{
    linked_list mergedList;

    while (!list1.is_empty() && !list2.is_empty())
    {
        if (list1.front() <= list2.front())
        {
            double tempValue1 = list1.pop_front();
            mergedList.push_back(tempValue1);
        }

        else
        {
            double tempValue2 = list2.pop_front();
            mergedList.push_back(tempValue2);
        }
    }

    while (!list1.is_empty())
    {
        double tempValue3 = list1.pop_front();
        mergedList.push_back(tempValue3);
    }

    while (!list2.is_empty())
    {
        double tempValue4 = list2.pop_front();
        mergedList.push_back(tempValue4);

        // mergedList += list1 += list2;
    }
    return mergedList;
}


bool isitSortedOrNot(linked_list &mergedList)
{   
    if(mergedList.is_empty())
    {
        std::cout << "Listan är tom." << std::endl;
    }

    for (int i = 0; i < mergedList.size() - 1; i++)
    {
        if (mergedList.at(i) > mergedList.at(i + 1))
        {
            std::cout << "Nej" << std::endl;
            return false;
        }
    }
    std::cout << "Ja" << std::endl;
    return true;
} 
