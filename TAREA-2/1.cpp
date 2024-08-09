#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;
    string gender;

    Person(string _name, int _age, string _gender) {
        name = _name;
        age = _age;
        gender = _gender;
    }

    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", Gender: " << gender << endl;
    }
};

class Employee : public Person {
public:
    double salary;
    string position;

    Employee(string _name, int _age, string _gender, double _salary, string _position)
        : Person(_name, _age, _gender) {
        salary = _salary;
        position = _position;
    }

    void displayDetails() {
        Person::displayDetails();
        cout << "Salary: " << salary << ", Position: " << position << endl;
    }
};

int main() {
    Person person("John", 30, "Male");
    person.displayDetails();

    Employee employee("Anna", 28, "Female", 50000.0, "Manager");
    employee.displayDetails();

    return 0;
}
