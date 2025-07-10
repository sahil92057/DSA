

class paymentStrategy{
    public:
    virtual bool pay(double amount)=0;
    virtual ~paymentStrategy()=default;
};