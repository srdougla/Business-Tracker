#ifndef BUSINESS_TRACKER_SCHEDULE_H
#define BUSINESS_TRACKER_SCHEDULE_H
#include "Event.h"
#include "TimePoint.h"
#include <string>
#include <vector>

using namespace std;

// Class schedule has-a event(s)
class Schedule {

private:
    vector<Event*> schedule; // Component class

public:
    // Default constructor
    Schedule();

    // Output a header before listing schedule items
    static void schedule_header();

    // Overloaded operator to easily output schedule objects
    friend ostream &operator<<(ostream &output, const Schedule &schedule);

    // Add event object to vector
    void add_event(Event* event);

    int get_schedule_size();

    vector<Event*> &get_schedule();
};

#endif //BUSINESS_TRACKER_SCHEDULE_H