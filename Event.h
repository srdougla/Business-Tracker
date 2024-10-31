#ifndef BUSINESS_TRACKER_EVENT_H
#define BUSINESS_TRACKER_EVENT_H

#include "TimePoint.h"

using namespace std;

class Event {
protected:
    string name; // The title of the event
    string date; // The date of the event
    // Component classes: Event has-a TimePoint
    TimePoint start_time; // The start time of the event
    TimePoint end_time; // The end time of the event

public:
    // Default constructor
    Event();
    // Constructor
    Event (string name, string date, TimePoint start_time, TimePoint end_time);

    // Destructor
    virtual ~Event() {}

    // Returns a nicely formatted string of all information about the event object
    virtual string get_info() const;

    // Overloaded operator to easily output schedule objects
    friend ostream& operator << (ostream& output, const Event& event);

    // Getters
    /*
     * Returns: a string representing the name of the event
     */
    virtual string get_name() const;
    /*
     * Returns: a string representing the date
     */
    string get_date() const;
    /*
     * Returns: a TimePoint object representing the time the event starts
     */
    TimePoint get_start_time() const;
    /*
     * Returns: a TimePoint object representing the time the event ends
     */
    TimePoint get_end_time() const;


    // Setters
    /*
     * Param: n, a string for the name
     */
    void set_name(string n);
    /*
     * Param: d, a string for the date
     */
    void set_date(string d);
    /*
     * Param: st, a TimePoint object representing the time the event starts
     */
    void set_start_time(TimePoint st);
    /*
     * Param: et, a TimePoint object representing the time the event ends
     */
    void set_end_time(TimePoint et);

};


#endif //BUSINESS_TRACKER_EVENT_H
