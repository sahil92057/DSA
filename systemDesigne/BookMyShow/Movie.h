#include"PaymentStrategy.h"
#include"iostream"
using namespace std;
class Movie{
    private:
    string title;
    int duration;
    Movie(string MName, int length):title(MName), duration(length){};
    string getTitle()const {return title;}
};