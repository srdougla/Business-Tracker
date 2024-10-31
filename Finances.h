#ifndef BUSINESS_TRACKER_FINANCES_H
#define BUSINESS_TRACKER_FINANCES_H

#include <string>

using namespace std;

/*
 * Enumeration to classify all categories of transactions
 * the user can choose from when entering a transaction
 */
enum FinanceType {
    Revenue,
    Expense,
    Asset,
    Liability,
    Miscellaneous
};

class Finances {

private:
    FinanceType category; // The category the user chooses when entering a transaction
    double amount; // The amount of money involved in the transaction
    string date; // The date of the transaction
    string description; // A short description of how and what was exchanged, spent, earned, etc.

public:
    // Default constructor
    Finances();

    // Constructor
    Finances (FinanceType category, double amount, string date, string description);

    // Constructor for int as a category
    Finances (int category, double amount, string date, string description);

    /*
     * Display all categories and let the user pick one
     * Returns: the finance type from the enum of 5 options
     */
    static FinanceType get_type_input();

    /*
     * Helper function to convert an int into the corresponding enum category
     * Param: an int representing the number that corresponds to the selected enum
     * Returns: the FinanceType the int links to in the enum
     */
    static FinanceType convert_enum(int choice);

    /*
     * Overloaded operator for printing finance objects nicely
     */
    friend ostream& operator << (ostream& os, Finances& finances);

    /*
     * Helper function to print the header of the transaction list for better organization
     */
    static void show_header();

    // Getters
    /*
     * Returns: a category from the enumerated types
     */
    FinanceType get_category();
    /*
     * Returns: a double representing the amount involved in the transaction
     */
    double get_amount() const;
    /*
     * Returns: a string representing the date of the transaction
     */
    string get_date() const;
    /*
     * Returns: a string of the description of the transaction
     */
    string get_description() const;

    // Setters
    /*
     * Param: cat, a FinanceType enum representing the category of the transaction
     */
    void set_category(FinanceType cat);
    /*
     * Param: amt, a double representing the amount involved in the transaction
     */
    void set_amount(double amt);
    /*
     * Param: dt, a string of the description of the transaction
     */
    void set_date(string dt);
    /*
     * Param: des, a string of the description of the transaction
     */
    void set_description(string des);

};

#endif //BUSINESS_TRACKER_FINANCES_H
