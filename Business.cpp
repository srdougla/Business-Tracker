#include "Business.h"
#include <string>

using namespace std;

Business::Business() : name(""), owner("") {}

Business::Business(string n, string o) : name(n), owner(o) {}

string Business::get_name() const {
    return name;
}
string Business::get_owner() const {
    return owner;
}

void Business::set_name(string n) {
    name = n;
}
void Business::set_owner(string o) {
    owner = o;
}

void Business::clear_name() {
    name = "";
}
void Business::clear_owner() {
    owner = "";
}

