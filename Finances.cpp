#include "Finances.h"
#include <iostream>

using namespace std;

// Default constructor
Finances::Finances() : category(), amount(0), date(""), description("")  {}

// Constructor
Finances::Finances (FinanceType c, double a, string dt, string ds) :
        category(c), amount(a), date(dt), description(ds) {}

// Alternate constructor for int category
Finances::Finances (int c, double a, string dt, string ds) :
        category(convert_enum(c)), amount(a), date(dt), description(ds) {}

FinanceType Finances::get_type_input() {
    // Display 5 options of categories to user and get them to select one
    int choice;
    cout << "1. Revenue" << endl
         << "2. Expense" << endl
         << "3. Asset" << endl
         << "4. Liability" << endl
         << "5. Miscellaneous/Other" << endl
         << "Select a category to record: ";

    bool invalid = true;
    while (invalid) {
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 5) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Enter a number 1 - 5: ";
        } else {
            // Return choice as the enum value it corresponds to
            // return convert_enum(choice);
            invalid = false;
        }
    }
    return convert_enum(choice);
}

// Helper function for linking int to enum
FinanceType Finances::convert_enum(int choice) {
    switch (choice) {
        case 1:
            return FinanceType::Revenue;
        case 2:
            return FinanceType::Expense;
        case 3:
            return FinanceType::Asset;
        case 4:
            return FinanceType::Liability;
        default:
            return FinanceType::Miscellaneous;
    }
}

// Overload << operator for Finances
ostream& operator << (ostream& output, Finances& finances) {
    // Get the name of the enum to output
    string cat_name;
    int cat_num = finances.get_category();

    // Set cat_name to a string of the category it corresponds to
    switch (cat_num) {
        case 0:
            cat_name = "REVENUE";
            break;
        case 1:
            cat_name = "EXPENSE";
            break;
        case 2:
            cat_name = "ASSET";
            break;
        case 3:
            cat_name = "LIABILITY";
            break;
        case 4:
            cat_name = "MISCELLANEOUS";
            break;
    }
    output << cat_name << " $" << finances.get_amount() << "     "
           << finances.get_date() << "     " << finances.get_description() << endl;
    return output;
}

// Header output
void Finances::show_header() {
    cout << endl << "CATEGORY      AMOUNT     DATE     DESCRIPTION" << endl
         << "-------------------------------------------------------------" << endl;
}

// Getters
FinanceType Finances::get_category() {
    return category;
}
double Finances::get_amount() const {
    return amount;
}
string Finances::get_date() const {
    return date;
}
string Finances::get_description() const {
    return description;
}

// Setters
void Finances::set_category(FinanceType c) {
    category = c;
}
void Finances::set_amount(double a) {
    amount = a;
}
void Finances::set_date(string dt) {
    date = dt;
}
void Finances::set_description(string ds) {
    description = ds;
}
