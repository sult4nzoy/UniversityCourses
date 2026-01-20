//
// Created by OmarK on 2025-10-21.
//

#include "MyFunc.h"

MyFunc::MyFunc(double mean) : mean(mean)
{
}

double MyFunc::operator()(double xi) {
    return xi - mean;
}
