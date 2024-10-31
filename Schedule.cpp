#include "Schedule.h"
#include <iostream>

// Constructor
Schedule::Schedule() {}


// Display a header for the schedule list
void Schedule::schedule_header() {
    cout << endl << "DATE         START       END        NAME" << endl
         << "---------------------------------------------------------" << endl;
}

// Overload << operator for Schedule
ostream& operator << (ostream& output, const Schedule& schedule) {
    for (auto& event : schedule.schedule) {
        output << *event;
    }
    return output;
}

// Add event object to vector
void Schedule::add_event(Event* event) {
    schedule.push_back(event);
}

int Schedule::get_schedule_size() {
    return schedule.size();
}

vector<Event*>& Schedule::get_schedule() {
    return schedule;
};