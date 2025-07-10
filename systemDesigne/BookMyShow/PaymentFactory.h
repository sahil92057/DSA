#include"CreditCard.h"
#include"PaymentStrategy.h"
#include"UpiPayment.h"
#include"iostream"
using namespace std;


class PaymentFactory:paymentStrategy{
    private:
    PaymentFactory();
    public:
     static shared_ptr<paymentStrategy> getPaymentStrategy(const string &type){
        if(type=="Credit Card"){
            return make_shared<CreditCard>();
        }else if("Upi"){
            return make_shared<UpiPayment>();
        }else{
            // return runtime_error("Unknown payment error/"); 
        }

    }
};