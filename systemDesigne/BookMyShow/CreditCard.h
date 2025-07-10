#include "PaymentStrategy.h"
using namespace std;
#include"iostream"


class CreditCard :public paymentStrategy{
    public:
    bool pay(double amount)override{
        cout<<"Paid through Credti Card ";
        return true;
    }
};