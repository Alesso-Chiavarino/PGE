#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int age;
    double grade;

    Student(string _name, int _age, double _grade) {
        name = _name;
        age = _age;
        grade = _grade;
    }

    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;
    }
};

class Group {
public:
    vector<Student> students;

    void addStudent(Student student) {
        students.push_back(student);
    }

    double calculateAverageGrade() {
        double total = 0;
        for (Student student : students) {
            total += student.grade;
        }
        return total / students.size();
    }
};

int main() {
    Student student1("John", 20, 85.5);
    Student student2("Anna", 22, 90.0);
    Student student3("Mike", 21, 78.0);

    Group group;
    group.addStudent(student1);
    group.addStudent(student2);
    group.addStudent(student3);

    cout << "Average Grade: " << group.calculateAverageGrade() << endl;

    return 0;
}
