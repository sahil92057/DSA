#ifndef WATCHER_HPP
#define WATCHER_HPP

#include "IObserver.hpp"
#include <string>
#include <iostream>

class Watcher : public IObserver {
public:
    explicit Watcher(const std::string& name);
    void OnNotify() override;

private:
    std::string mName;
};

#endif // WATCHER_HPP
