#include "Event.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Default Constructor
Event::Event() : name(""), date(""), start_time(12,0,true), end_time(12,0,true) {}

// Constructor
Event::Event (string n, string d, TimePoint st, TimePoint et) :
        name(n), date(d), start_time(st), end_time(et) {}

// Create a formatted string of all information regarding event
string Event::get_info() const{
    stringstream ss;
    ss << get_date() << "    " <<
    get_name() << "    " <<
    get_start_time() << "    " <<
    get_end_time() << "    ";
    return ss.str();
}

// Overload << operator for Event
ostream& operator << (ostream& output, const Event& event) {
    output << event.get_info();
    return output;
}


// Getters
string Event::get_name() const {
    return name;
}
string Event::get_date() const {
    return date;
}
TimePoint Event::get_start_time() const {
    return start_time;
}
TimePoint Event::get_end_time() const {
    return end_time;
}

// Setters
void Event::set_name(string n) {
    name = n;
}
void Event::set_date(string d) {
    date = d;
}
void Event::set_start_time(TimePoint st) {
    start_time = st;
}
void Event::set_end_time(TimePoint et) {
    end_time = et;
}
