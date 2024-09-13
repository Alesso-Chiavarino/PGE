#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
using namespace std;

class Schedule {
public:
    string day;
    string startTime;
    string endTime;

    Schedule(const string& day, const string& startTime, const string& endTime);
};

#endif
