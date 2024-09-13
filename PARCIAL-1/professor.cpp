#include "professor.h"

Professor::Professor(const string& name, const string& id)
    : name(name), id(id) {}

void Professor::assignSubject(const Subject& subject) {
    subjects.push_back(subject);
}
