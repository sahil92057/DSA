#include "Watcher.hpp"

Watcher::Watcher(const std::string& name) : mName(name) {}

void Watcher::OnNotify() {
    std::cout << "Watcher - " << mName << std::endl;
}
