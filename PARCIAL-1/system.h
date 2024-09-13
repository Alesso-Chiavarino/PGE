#ifndef SYSTEM_H
#define SYSTEM_H

#include <unordered_map>
#include <functional>
#include <iostream>
using namespace std;

class System {
private:
    unordered_map<int, function<void()>> events;  // Event map

public:
    void registerEvent(int option, const function<void()>& callback);
    void dispatchEvent(int option);
    void showMenu();
};

#endif
