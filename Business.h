#ifndef BUSINESS_TRACKER_BUSINESS_H
#define BUSINESS_TRACKER_BUSINESS_H

#include <string>

using namespace std;

class Business {
private:
    string name; // The name of the business
    string owner; // The name/title of the owner of the business
public:
    // Default constructor
    Business();

    // Constructor
    Business(string name, string owner);

    // Getters
    /*
     * Returns: a string representing the name of the business
     */
    string get_name() const;
    /*
     * Returns: a string representing the owner's name
     */
    string get_owner() const;

    // Setters
    /*
     * Param: n, a string for the business name
     */
    void set_name(string n);
    /*
     * Param: o, a string for the owner's name
     */
    void set_owner(string o);


    // Replace the name field with an empty string
    void clear_name();
    // Replace the owner field with an empty string
    void clear_owner();
};
#endif //BUSINESS_TRACKER_BUSINESS_H
