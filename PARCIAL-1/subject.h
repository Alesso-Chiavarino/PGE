#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
using namespace std;

class Subject {
public:
    string name;
    string id;
    string professor;

    Subject(const string& name, const string& id, const string& professor);
};

#endif
