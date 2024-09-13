#include "system.h"

void System::registerEvent(int option, const function<void()>& callback) {
    events[option] = callback;
}

void System::dispatchEvent(int option) {
    if (events.find(option) != events.end()) {
        events[option]();
    } else {
        cout << "Invalid option." << endl;
    }
}

void System::showMenu() {
    cout << "Menu Options:" << endl;
    cout << "1. Register Student" << endl;
    cout << "2. Assign Subject to Professor" << endl;
    cout << "3. Exit" << endl;
}
