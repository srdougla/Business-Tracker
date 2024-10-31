#include "Project.h"

using namespace std;

Project::Project() {}
Project::Project(string n, string d, TimePoint st, TimePoint et, string dl, int dur) :
        Event (n, d, st, et), deadline(dl), duration(dur) {}

// Getters
string Project::get_deadline() const {
    return deadline;
}
int Project::get_duration() const {
    return duration;
}

// Setters
void Project::set_deadline(string dl) {
    deadline = dl;
}
void Project::set_duration(int dur) {
    duration = dur;
}

// Overridden method to print altered info for a meeting
string Project::get_info() const {
    string num = to_string(duration);
    string print = deadline + "     Project      " + num + " days\n";
    return print;
}
string Project::get_name() const {
    return "Project";
}