#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <vector>
#include "subject.h"
using namespace std;

class Professor {
public:
    string name;
    string id;
    vector<Subject> subjects;

    Professor(const string& name, const string& id);
    void assignSubject(const Subject& subject);
};

#endif
