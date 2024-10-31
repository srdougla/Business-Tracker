#include "TimePoint.h"

TimePoint::TimePoint() : hour(1), minute(0), pm(true) {

}

TimePoint::TimePoint(int hour, int minute, bool pm) : pm(pm) {
    setHour(hour);
    setMinute(minute);
}

int TimePoint::getHour() const {
    return hour;
}

int TimePoint::getMinute() const {
    return minute;
}

bool TimePoint::isPM() const {
    return pm;
}

bool TimePoint::setHour(int hour) {
    if (hour >= 1 && hour <= 12) {
        if (hour == 12) {
            this->hour = 0;
        } else {
            this->hour = hour;
        }
        return true;
    }
    return false;
}

bool TimePoint::setMinute(int minute) {
    if (minute >= 0 && minute <= 59) {
        this->minute = minute;
        return true;
    }
    return false;
}

void TimePoint::makeAM() {
    pm = false;
}

void TimePoint::makePM() {
    pm = true;
}

bool TimePoint::moveHour(int delta) {
    if (hour + delta >= 0 && hour + delta <= 11) {
        hour += delta;
        return true;
    } else if (!pm && hour + delta >= 12 && hour + delta <= 24) {
        pm = true;
        hour = hour + delta - 12;
        return true;
    } else if (pm && hour + delta < 0 && hour + delta >= -11) {
        pm = false;
        hour = hour + delta + 12;
        return true;
    }
    return false;
}

bool TimePoint::moveMinute(int delta) {
    if (minute + delta >= 0 && hour + delta <= 59) {
        minute += delta;
        return true;
    } else if (minute + delta > 59 && moveHour((minute + delta) / 60)) {
        minute = minute + delta % 60;
        return true;
    } else if (minute + delta < 0 && moveHour((minute + delta) / 60)) {
        while (minute + delta < 0) {
            delta += 60;
        }
        minute += delta;
        return true;
    }
    return false;
}

bool operator == (const TimePoint &lhs, const TimePoint &rhs) {
    return lhs.hour == rhs.hour && lhs.minute == rhs.minute && lhs.pm == rhs.pm;
}

bool operator < (const TimePoint &lhs, const TimePoint &rhs) {
    if (!lhs.pm && rhs.pm) {
        return true;
    }
    if (lhs.pm == rhs.pm && lhs.hour < rhs.hour) {
        return true;
    }
    if (lhs.pm == rhs.pm && lhs.hour == rhs.hour && lhs.minute < rhs.minute) {
        return true;
    }
    return false;
}

bool operator > (const TimePoint &lhs, const TimePoint &rhs) {
    return !(lhs == rhs || lhs < rhs);
}

bool operator <= (const TimePoint &lhs, const TimePoint &rhs) {
    return lhs == rhs || lhs < rhs;
}

bool operator >= (const TimePoint &lhs, const TimePoint &rhs) {
    return !(lhs < rhs);
}

bool operator != (const TimePoint &lhs, const TimePoint &rhs) {
    return !(lhs == rhs);
}

ostream& operator << (ostream& outs, const TimePoint &rhs) {
    if (rhs.hour == 0) {
        outs << "12";
    } else {
        outs << rhs.hour;
    }
    outs << ":";
    if (rhs.minute < 10) {
        outs << "0";
    }
    outs << rhs.minute;
    if (rhs.pm) {
        outs << " PM";
    } else {
        outs << " AM";
    }
    return outs;
}