#include "Business.h"
#include "Clients.h"
#include "Event.h"
#include "Finances.h"
#include "Meeting.h"
#include "Project.h"
#include "Schedule.h"
#include <iostream>
#include <vector>

using namespace std;

bool test_business();
bool test_clients();
bool test_event();
bool test_finances();
bool test_meeting();
bool test_project();
bool test_schedule();
bool test_timepoint();

int main() {
    if (test_business()) {
        cout << "All Business tests passed." << endl;
    }
    if (test_clients()) {
        cout << "All Clients tests passed." << endl;
    }
    if (test_event()) {
        cout << "All Event tests passed." << endl;
    }
    if (test_finances()) {
        cout << "All Finances tests passed." << endl;
    }
    if (test_meeting()) {
        cout << "All Meeting tests passed." << endl;
    }
    if (test_project()) {
        cout << "All Project tests passed." << endl;
    }
    if (test_schedule()) {
        cout << "All Schedule tests passed." << endl;
    }
    if (test_timepoint()) {
        cout << "All TimePoint tests passed." << endl;
    }
    return 0;
}

bool test_business() {
    bool passed = true;

    Business business;
    business.set_name("Name");
    if (business.get_name() != "Name") {
        cout << "FAILED Business name test." << endl;
        passed = false;
    }
    business.set_owner("Owner");
    if (business.get_owner() != "Owner") {
        cout << "FAILED Business owner test." << endl;
        passed = false;
    }
    business.clear_name();
    business.clear_owner();
    if (business.get_name() != "" || business.get_owner() != "") {
        cout << "FAILED Business fields clear test." << endl;
        passed = false;
    }
    return passed;
}

bool test_clients() {
    bool passed = true;

    Clients client;
    client.set_name("Name");
    if (client.get_name() != "Name") {
        cout << "FAILED Client name test." << endl;
        passed = false;
    }
    client.set_address("Address");
    if (client.get_address() != "Address") {
        cout << "FAILED Client address test." << endl;
        passed = false;
    }
    client.set_phone("Phone");
    if (client.get_phone() != "Phone") {
        cout << "FAILED Client phone test." << endl;
        passed = false;
    }
    client.set_status("Status");
    if (client.get_status() != "Status") {
        cout << "FAILED Client status test." << endl;
        passed = false;
    }
    client.set_notes("Notes");
    if (client.get_notes() != "Notes") {
        cout << "FAILED Client notes test." << endl;
        passed = false;
    }
    return passed;
}

bool test_event() {
    bool passed = true;
    TimePoint t1 (10,30,false);
    TimePoint t2(11,30,false);
    Event event ("Name","Date",t1,t2);

    if(event.get_name() != "Name") {
        cout << "FAILED Event name test." << endl;
        passed = false;
    }
    if(event.get_date() != "Date") {
        cout << "FAILED Event date test." << endl;
        passed = false;
    }
    if(event.get_start_time() != t1) {
        cout << "FAILED Event start time test." << endl;
        passed = false;
    }
    if(event.get_end_time() != t2) {
        cout << "FAILED Event end time test." << endl;
        passed = false;
    }

    return passed;
}
bool test_finances() {
    bool passed = true;

    Finances finance (1, 10.5, "date", "description");
    if (finance.get_category() != Revenue) {
        cout << "FAILED Finance ENUM test." << endl;
        passed = false;
    }
    if (finance.get_amount() != 10.5) {
        cout << "FAILED Finance double amount test." << endl;
        passed = false;
    }
    if (finance.get_date() != "date") {
        cout << "FAILED Finance date test." << endl;
        passed = false;
    }
    if (finance.get_description() != "description") {
        cout << "FAILED Finance description test." << endl;
        passed = false;
    }
    if (Expense != finance.convert_enum(2)) {
        cout << "FAILED Finance convert enum test." << endl;
    }
    return passed;
}

bool test_meeting() {
    bool passed = true;

    TimePoint t1 (10,30,false);
    TimePoint t2(11,30,false);

    Meeting* meeting = new Meeting("Name","Date",t1,t2,"Location",3);

    if (meeting->get_name() != "Meeting") {
       cout << "FAILED Meeting default name test." << endl;
       passed = false;
    }
    if (meeting->get_num_att() != 3) {
        cout << "FAILED Meeting num attendees test." << endl;
        passed = false;
    }
    return passed;
}

bool test_project() {
    bool passed = true;

    TimePoint t1 (10,30,false);
    TimePoint t2(11,30,false);

    Project* project = new Project("Name","Date",t1,t2,"Deadline",30);

    if (project->get_name() != "Project") {
        cout << "FAILED Project default name test." << endl;
        passed = false;
    }
    if (project->get_deadline() != "Deadline") {
        cout << "FAILED Project deadline test." << endl;
        passed = false;
    }
    if (project->get_duration() != 30) {
        cout << "FAILED Project duration test." << endl;
        passed = false;
    }

    return passed;
}

bool test_schedule() {
    bool passed = true;

    Schedule schedule;

    TimePoint t1 (10,30,false);
    TimePoint t2(11,30,false);
    Event* event  = new Event("Name","Date",t1,t2);
    schedule.add_event(event);

    if (schedule.get_schedule_size() != 1) {
        cout << "FAILED Schedule get size 1 test." << endl;
        cout << "FAILED Schedule add event test." << endl;
        passed = false;
    }

    return passed;
}

bool test_timepoint() {
    bool passed = true;

    TimePoint time1;
    TimePoint time2;

    time1.setHour(0);
    if (time1.getHour() != 1) {
        cout << "FAILED 0 hour test case." << endl;
        passed = false;
    }
    time1.setHour(13);
    if (time1.getHour() != 1) {
        cout << "FAILED 13 hour test case." << endl;
        passed = false;
    }
    time1.setHour(0);
    if (time1.getHour() != 1) {
        cout << "FAILED -5 hour test case." << endl;
        passed = false;
    }
    time1.setHour(4);
    if (time1.getHour() != 4) {
        cout << "FAILED 4 hour test case." << endl;
        passed = false;
    }
    time1.setMinute(60);
    if (time1.getMinute() != 0) {
        cout << "FAILED 60 minute test case." << endl;
        passed = false;
    }
    time1.setMinute(0);
    if (time1.getMinute() != 0) {
        cout << "FAILED 0 minute test case." << endl;
        passed = false;
    }
    time1.setMinute(-5);
    if (time1.getMinute() != 0) {
        cout << "FAILED -5 minute test case." << endl;
        passed = false;
    }
    time1.setMinute(30);
    if (time1.getMinute() != 30) {
        cout << "FAILED 30 minute test case." << endl;
        passed = false;
    }
    time1.makePM();
    if (!time1.isPM()) {
        cout << "FAILED make PM test case." << endl;
        passed = false;
    }
    time1.makeAM();
    if (time1.isPM()) {
        cout << "FAILED make AM test case." << endl;
        passed = false;
    }
    time1.moveHour(10);
    if (time1.getHour() != 2 || !time1.isPM()) {
        cout << "FAILED move by 12 hours test case." << endl;
        passed = false;
    }
    time1.setHour(1);
    time1.setMinute(30);
    time1.moveMinute(45);
    if (time1.getHour() != 2 || time1.getMinute() != 15) {
        cout << "FAILED move by 45 mins test case." << endl;
        passed = false;
    }

    return passed;
}
