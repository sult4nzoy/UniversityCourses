//
// Created by OmarK on 2025-10-21.
//

#ifndef LABB5CLION_MYFUNC_H
#define LABB5CLION_MYFUNC_H

class MyFunc {
public:
    double mean;
    MyFunc(double mean);
    double operator()(double xi);
};


#endif //LABB5CLION_MYFUNC_H
