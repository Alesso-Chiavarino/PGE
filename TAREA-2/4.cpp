#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    virtual void eat() = 0;
    virtual void sleep() = 0;
};

class Dog : public Animal {
public:
    void eat() override {
        cout << "The dog is eating." << endl;
    }

    void sleep() override {
        cout << "The dog is sleeping." << endl;
    }

    void bark() {
        cout << "The dog is barking." << endl;
    }
};

class Cat : public Animal {
public:
    void eat() override {
        cout << "The cat is eating." << endl;
    }

    void sleep() override {
        cout << "The cat is sleeping." << endl;
    }

    void meow() {
        cout << "The cat is meowing." << endl;
    }
};

int main() {
    Dog dog;
    dog.eat();
    dog.sleep();
    dog.bark();

    Cat cat;
    cat.eat();
    cat.sleep();
    cat.meow();

    return 0;
}
