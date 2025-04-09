// #include<bits/stdc++.h>
// using namespace std;

// class Logger{
//     // Retireve the single instance of the object creation, and we will enforce only one of these objects get created in our code logic. 
//     public:
//     static Logger* getInstance(){
//           if(logNumber==nullptr){
//             logNumber=new Logger;
//         }
//         return logNumber;
//     }
//     void printMessage(){
//         cout<<"accessing the log\n";
//         for(auto& it : m_messages){
//             cout<<it<<endl;
//         }
     
//     }
//     void addMessage(string str){
//         m_messages.push_back(str);
//     }
//     private:
//     Logger(){
//         cout<<"Logger constructor called"<<endl;
//     };
//     ~Logger(){
//         cout<<"Logger destructor called"<<endl;
//     };
//     static Logger* logNumber;
//     vector<string>m_messages;
// };
// Logger* Logger:: logNumber=nullptr;



// int main (){

//     Logger::getInstance()->addMessage("m1");
//     Logger::getInstance()->addMessage("m2");
//     Logger::getInstance()->addMessage("m3");
//         Logger::getInstance()->printMessage();
//     return 0;
// }










#include<bits/stdc++.h>
using namespace std;

class Logger{
    // Retireve the single instance of the object creation, and we will enforce only one of these objects get created in our code logic. 
    public:
    static Logger* getInstance(){
         static Logger* logNumber= new Logger;
        return logNumber;
    }
    void printMessage(){
        cout<<"accessing the log\n";
        for(auto& it : m_messages){
            cout<<it<<endl;
        }
     
    }
    void addMessage(string str){
        m_messages.push_back(str);
    }
    private:
    Logger(){
        cout<<"Logger constructor called"<<endl;
    };
    ~Logger(){
        cout<<"Logger destructor called"<<endl;
    };
   
    vector<string>m_messages;
};




int main (){

    Logger::getInstance()->addMessage("m1");
    Logger::getInstance()->addMessage("m2");
    Logger::getInstance()->addMessage("m3");
        Logger::getInstance()->printMessage();
    return 0;
}