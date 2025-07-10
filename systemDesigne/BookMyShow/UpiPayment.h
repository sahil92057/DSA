#include "PaymentStrategy.h"
using namespace std;
#include"iostream"


class UpiPayment :public paymentStrategy{
    public:
    bool pay(double amount)override{
        cout<<"Paid through UPI ";
        return true;
    }
};