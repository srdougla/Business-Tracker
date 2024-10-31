#include "Clients.h"
#include <iostream>

using namespace std;

// Default Constructor
Clients::Clients() : name("Null"), address("Null"), phone("Null"), status("Null"), notes("Null") {}
// Constructor
Clients::Clients (string n, string a, string p, string s, string z) :
        name(n), address(a), phone(p), status(s), notes(z) {}

// Getters
string Clients::get_name() const {
    return name;
}
string Clients::get_address() const {
    return address;
}
string Clients::get_phone() const {
    return phone;
}
string Clients::get_status() const {
    return status;
}
string Clients::get_notes() const {
    return notes;
}

// Setters
void Clients::set_name(string n) {
    name = n;
}
void Clients::set_address(string a) {
    address = a;
}
void Clients::set_phone(string p) {
    phone = p;
}
void Clients::set_status(string s) {
    status = s;
}
void Clients::set_notes(string n) {
    notes = n;
}

// Overload << operator for Clients
ostream& operator << (ostream& output, Clients& client) {
    output << "CLIENT: " << client.get_name() << endl
           << client.get_address() << endl
           << "#" << client.get_phone() << endl
           << "STATUS IS " << client.get_status() << endl
           << "Notes: " << client.get_notes() << endl;
    return output;
}