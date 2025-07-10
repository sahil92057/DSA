#include "Watcher.hpp"
#include "ISubject.hpp"

int main() {
    ISubject subject;

    Watcher watcher1("Watcher1");
    Watcher watcher2("Watcher2");
    Watcher watcher3("Watcher3");

    subject.AddObserver(&watcher1);
    subject.AddObserver(&watcher2);
    subject.AddObserver(&watcher3);

    std::cout << "Initial Notification:\n";
    subject.NotifyAll();

    subject.RemoveObserver(&watcher3);
    std::cout << "\nAfter Removing Watcher3:\n";
    subject.NotifyAll();

    return 0;
}
