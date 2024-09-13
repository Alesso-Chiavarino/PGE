#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "subject.h"
using namespace std;

class Student {
public:
    string name;
    string id;
    vector<Subject> subjects;

    Student(const string& name, const string& id);
    void registerSubject(const Subject& subject);
};

#endif
