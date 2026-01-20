#include "pq.cpp"


struct Order
{
    std::string name = "";
    int price = 0;
};

struct CompareOrder{
    bool operator()(const Order& lhs, const Order& rhs) const{
        return lhs.price < rhs.price;
    }
};

int randomizePrice() {
    return std::rand() % 16 + 15;
}


template<typename T>
void trade(pq< T, CompareOrder>& buy_orders, pq<T, CompareOrder>& sell_orders) {
    CompareOrder comp;

    while (!buy_orders.empty() && !sell_orders.empty()) {
        if (comp(buy_orders.front(), sell_orders.front())) {
            buy_orders.pop();
        }
        else {
            std::cout << buy_orders.begin()->name << " köpte för " << buy_orders.begin()->price <<
                      " kr, såld av " << sell_orders.begin()->name << " för " << sell_orders.begin()->price
                      << " kr" << std::endl;

            buy_orders.pop();
            sell_orders.pop();
        }
    }
}

auto main() -> int  {

    pq<Order,CompareOrder> buyords;
    pq<Order,CompareOrder> sellorders;

    std::string ErikPendel = "Erik Pendel";
    std::string JoakimVonAnka = "Joakim Von Anka";
    std::string JarlWallenburg = "Jarl Wallenburg";


    // for (int i = 0; i < 7; i++) {
    //     buyords.push({ ErikPendel, randomizePrice() });
    //     sellorders.push({ ErikPendel, randomizePrice() });
    //
    //     buyords.push({ JoakimVonAnka, randomizePrice() });
    //     sellorders.push({ JoakimVonAnka, randomizePrice() });
    //
    //     buyords.push({ JarlWallenburg, randomizePrice() });
    //     sellorders.push({ JarlWallenburg, randomizePrice() });
    // }


    buyords.push({ErikPendel, randomizePrice()});
    buyords.push({ErikPendel, randomizePrice()});
    buyords.push({ErikPendel, randomizePrice()});
    buyords.push({ErikPendel, randomizePrice()});
    buyords.push({ErikPendel, randomizePrice()});
    buyords.push({ErikPendel, randomizePrice()});
    buyords.push({ErikPendel, randomizePrice()});
    sellorders.push({ErikPendel, randomizePrice()});
    sellorders.push({ErikPendel, randomizePrice()});
    sellorders.push({ErikPendel, randomizePrice()});
    sellorders.push({ErikPendel, randomizePrice()});
    sellorders.push({ErikPendel, randomizePrice()});
    sellorders.push({ErikPendel, randomizePrice()});
    sellorders.push({ErikPendel, randomizePrice()});

    buyords.push({JoakimVonAnka, randomizePrice()});
    buyords.push({JoakimVonAnka, randomizePrice()});
    buyords.push({JoakimVonAnka, randomizePrice()});
    buyords.push({JoakimVonAnka, randomizePrice()});
    buyords.push({JoakimVonAnka, randomizePrice()});
    buyords.push({JoakimVonAnka, randomizePrice()});
    buyords.push({JoakimVonAnka, randomizePrice()});
    sellorders.push({JoakimVonAnka, randomizePrice()});
    sellorders.push({JoakimVonAnka, randomizePrice()});
    sellorders.push({JoakimVonAnka, randomizePrice()});
    sellorders.push({JoakimVonAnka, randomizePrice()});
    sellorders.push({JoakimVonAnka, randomizePrice()});
    sellorders.push({JoakimVonAnka, randomizePrice()});
    sellorders.push({JoakimVonAnka, randomizePrice()});

    buyords.push({JarlWallenburg, randomizePrice()});
    buyords.push({JarlWallenburg, randomizePrice()});
    buyords.push({JarlWallenburg, randomizePrice()});
    buyords.push({JarlWallenburg, randomizePrice()});
    buyords.push({JarlWallenburg, randomizePrice()});
    buyords.push({JarlWallenburg, randomizePrice()});
    buyords.push({JarlWallenburg, randomizePrice()});
    sellorders.push({JarlWallenburg, randomizePrice()});
    sellorders.push({JarlWallenburg, randomizePrice()});
    sellorders.push({JarlWallenburg, randomizePrice()});
    sellorders.push({JarlWallenburg, randomizePrice()});
    sellorders.push({JarlWallenburg, randomizePrice()});
    sellorders.push({JarlWallenburg, randomizePrice()});
    sellorders.push({JarlWallenburg, randomizePrice()});

    trade(buyords, sellorders);

    return 0;
}