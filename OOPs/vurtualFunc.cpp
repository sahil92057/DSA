#include<bits/stdc++.h>
#include "iostream"
using namespace std;

class Entity{
    public: 
    // here we are adding virtual 
   virtual string getName(){
        return "Entity";
    }
};
class Player :public Entity{
    private: 
    string n_Name;
    public :
    Player(string name) :n_Name(name) {}
    string getName() override{return n_Name;}
};
int main(){
    Entity ent;
    Player *play= new Player("player");
    // cout<<play->getName();
    // here the problem is, we have declare ent2 of type Entity and assigning the value of Player  play to et2, but is giving the answer of Entity
    // bcoz  it return the value of type. we can solve this problem by using vritual keyword to the base  fucntion of the base class
    Entity *ent2= play;
    cout<<ent2->getName();
    return 0;
}