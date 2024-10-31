// Created by Lisa Dion

#ifndef BUSINESS_TRACKER_TIMEPOINT_H
#define BUSINESS_TRACKER_TIMEPOINT_H

#include <iostream>
using std::ostream;

/*
 * Time Point class
 * Used to store an hour and minute time
 */

class TimePoint {
private:
    /* hour will have value between 0 and 11. 0 will print as 12.
     * This is to get the AM / PM to switch correctly. */
    int hour;
    int minute;
    bool pm;
public:
    /* Constructors */
    TimePoint();
    TimePoint(int hour, int minute, bool pm);

    /* Getters */
    int getHour() const;
    int getMinute() const;
    bool isPM() const;

    /* Setters
     * if hour or minute is not valid,
     * does not set field and returns false */
    bool setHour(int hour);
    bool setMinute(int minute);
    void makeAM();
    void makePM();

    /* Move TimePoint by set amount of time
     * @param delta is the positive or negative change */
    bool moveHour(int delta);
    bool moveMinute(int delta);

    /* Overloaded Operators */
    friend bool operator == (const TimePoint &lhs, const TimePoint &rhs);
    friend bool operator < (const TimePoint &lhs, const TimePoint &rhs);
    friend bool operator > (const TimePoint &lhs, const TimePoint &rhs);
    friend bool operator <= (const TimePoint &lhs, const TimePoint &rhs);
    friend bool operator >= (const TimePoint &lhs, const TimePoint &rhs);
    friend bool operator != (const TimePoint &lhs, const TimePoint &rhs);
    friend ostream& operator << (ostream& outs, const TimePoint &rhs);
};

#endif //BUSINESS_TRACKER_TIMEPOINT_H
