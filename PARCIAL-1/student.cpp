#include "student.h"

Student::Student(const string& name, const string& id)
    : name(name), id(id) {}

void Student::registerSubject(const Subject& subject) {
    subjects.push_back(subject);
}
