#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

class IObserver {
public:
    virtual ~IObserver() {}
    virtual void OnNotify() = 0;
};

#endif // IOBSERVER_HPP
