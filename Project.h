#ifndef BUSINESS_TRACKER_PROJECT_H
#define BUSINESS_TRACKER_PROJECT_H

#include "Event.h"

using namespace std;

class Project : public Event {

private:
    string deadline; // The date the project must be complete by
    int duration; // The length of the project (in days)

public:
    // Constructors
    Project();
    Project(string name, string date, TimePoint start, TimePoint end, string deadline, int duration);

    // Getters
    string get_deadline() const;
    int get_duration() const;

    // Overridden method
    string get_name() const override;
    string get_info() const override;

    // Setters
    void set_deadline(string dl);
    void set_duration(int dur);

};


#endif //BUSINESS_TRACKER_PROJECT_H
