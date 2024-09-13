#include "system.h"

int main() {
    System system;
    bool running = true;

    // Registering events (callbacks)
    system.registerEvent(1, [&]() {
        cout << "Student registration is not implemented yet." << endl;
    });

    system.registerEvent(2, [&]() {
        cout << "Assigning subjects to professor is not implemented yet." << endl;
    });

    system.registerEvent(3, [&]() {
        cout << "Exiting..." << endl;
        running = false;
    });

    // Main event loop (dispatcher loop)
    while (running) {
        system.showMenu();
        int choice;
        cout << "Enter option: ";
        cin >> choice;
        system.dispatchEvent(choice);
    }

    return 0;
}
