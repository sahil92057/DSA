#ifndef ISUBJECT_HPP
#define ISUBJECT_HPP

#include "IObserver.hpp"
#include <forward_list>

class ISubject {
public:
    virtual ~ISubject() {}

    virtual void AddObserver(IObserver* observer);
    virtual void RemoveObserver(IObserver* observer);
    void NotifyAll();

private:
    std::forward_list<IObserver*> mObservers;
};

#endif // ISUBJECT_HPP
