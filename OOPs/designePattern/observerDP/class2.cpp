#include<bits/stdc++.h>
using namespace std;

class IObserver{
    public: 
    virtual ~IObserver(){}
    virtual void OnNotify()=0;
};


class watcher :public IObserver {
    public:
    explicit watcher(const string& name):mName(name){}
    void OnNotify  ()override{
        cout<<"watcher-"<< mName<<endl;
    }

    private:
    string mName;
};


class ISubject {
    public: 
      virtual ~ISubject(){};
      virtual void AddObserver(IObserver* observer){
        mObservers.push_front(observer);
      }
      virtual void RemoveObserver(IObserver* observer){
        mObservers.remove(observer);
      }

      void NotifyAll(){
        for(auto &o : mObservers){
            o->OnNotify();
        }
      }

      private:
      forward_list<IObserver*>mObservers;
};


class SomeSubject: public ISubject{
    public:
};


int main (){
    SomeSubject Subject;
    watcher watcher1("watcher1");
    watcher watcher2("watcher2");
    watcher watcher3("watcher3");

    Subject.AddObserver(&watcher1);
    Subject.AddObserver(&watcher2);
    Subject.AddObserver(&watcher3);
    Subject.NotifyAll();
    Subject.RemoveObserver(&watcher3);
    cout<<endl;
    Subject.NotifyAll();
    return 0;
}
  