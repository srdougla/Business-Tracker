#ifndef BUSINESS_TRACKER_MEETING_H
#define BUSINESS_TRACKER_MEETING_H

#include "Event.h"
#include <string>

using namespace std;

class Meeting : public Event {
private:
    string location; // The location of the meeting
    int num_attendees; // The number of people attending the meeting

public:
    // Constructor
    Meeting();
    Meeting(string name, string date, TimePoint start_time, TimePoint end_time, string loc, int num_att);

    // Getters
    string get_location() const;
    int get_num_att() const;

    // Overridden methods
    string get_name() const override;
    string get_info() const override;

    // Setters
    void set_location(string loc);
    void set_num_att(int num);

};


#endif //BUSINESS_TRACKER_MEETING_H
