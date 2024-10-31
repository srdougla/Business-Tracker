#include "Meeting.h"

using namespace std;
Meeting::Meeting() {}

Meeting::Meeting(string n, string d, TimePoint st, TimePoint et, string loc, int num_att) :
          Event (n, d, st, et), location(loc), num_attendees(num_att) {}

// Getters
string Meeting::get_location() const {
    return location;
}
int Meeting::get_num_att() const {
    return num_attendees;
}

// Setters
void Meeting::set_location(string l) {
    location = l;
}
void Meeting::set_num_att(int n) {
    num_attendees = n;
}

// Override name getter so name is "Meeting"
string Meeting::get_name() const {
    return "Meeting";
}

// Overridden method to print altered info for a meeting
string Meeting::get_info() const {
    string print = Event::get_info();
    string num = to_string(num_attendees);
    print += location + "    ";
    print += num + " attendees\n";
    return print;
}

