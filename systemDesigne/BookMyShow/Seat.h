#include"iostream"
using namespace std;

class Seat{
    public:
    int seatNumber;
    bool booked=false;
    Seat(int sNo):seatNumber(sNo), booked(false){};
    int getSeatNumber(){return seatNumber;}
    bool isBooked()const{ return booked;}
    void book(){booked=true;} 
};