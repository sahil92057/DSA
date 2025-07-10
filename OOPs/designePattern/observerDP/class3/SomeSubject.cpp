#include "ISubject.hpp"

void ISubject::AddObserver(IObserver* observer) {
    mObservers.push_front(observer);
}

void ISubject::RemoveObserver(IObserver* observer) {
    mObservers.remove(observer);
}

void ISubject::NotifyAll() {
    for (auto& observer : mObservers) {
        observer->OnNotify();
    }
}
