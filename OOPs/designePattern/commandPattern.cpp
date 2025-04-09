// Command Pattern 
#include<bits/stdc++.h>
#include "iostream"
using namespace std;
struct Character {
    int x;int y;
    string name;
    Character (string _name):name(_name){}
    void move(int _x, int _y){
        x=_x;
        y=_y;
    }
};

class Command{
    public:
    virtual ~Command(){}
    virtual void Execute(Character &c)=0;
    virtual void Undo(Character &c)=0;
};

class Move : public Command{
    public:
    void Execute(Character &c){
        cout<<c.name<<" "<<" moved"<<endl;
    };
    void Undo(Character &c){
        cout<<c.name<<" "<<" moved undo "<<endl;
    };
};



int main(){
    Character mike("mike");
    vector<Command*> commans_queue;
    Move* m1= new Move;
    commans_queue.push_back(m1);
    Move* m2= new Move;
    commans_queue.push_back(m2);
    Move* m3= new Move;
    commans_queue.push_back(m3);
    Move* m4= new Move;
    commans_queue.push_back(m4);
    
    for(auto it :commans_queue){
        it->Execute(mike);
    }
    for(int i=commans_queue.size()-1; i>=0; i--){
        commans_queue[i]->Undo(mike);
    }
    
    return 0;
}