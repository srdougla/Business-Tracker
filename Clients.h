#ifndef BUSINESS_TRACKER_CLIENTS_H
#define BUSINESS_TRACKER_CLIENTS_H
#include <string>

using namespace std;

class Clients {
private:
    string name; // The name of the client
    string address; // The street address of the client
    string phone; // The phone number of the client
    string status; // The status of the client, which can be defined however the user wants depending on their business
    string notes; // Notes on/regarding the client

public:
    // Default constructor
    Clients();
    // Constructor
    Clients (string name, string address, string phone, string status, string notes);

    // Overloaded operator to easily print client objects
    friend ostream& operator << (ostream& os, Clients& client);

    // Getters
    /*
     * Returns: a string representing the client's name
     */
    string get_name() const;
    /*
     * Returns: a string representing the client's address
     */
    string get_address() const;
    /*
     * Returns: a string representing the client's phone number
     */
    string get_phone() const;
    /*
     * Returns: a string representing the client's status
     */
    string get_status() const;
    /*
     * Returns: a string representing notes on the client
     */
    string get_notes() const;

    // Setters
    /*
     * Param: n, a string for the name of the client
     */
    void set_name(string n);
    /*
     * Param: a, a string for the client's address
     */
    void set_address(string a);
    /*
     * Param: p, a string for the client's phone number
     */
    void set_phone(string p);
    /*
     * Param: s, a string for the client's status
     */
    void set_status(string s);
    /*
     * Param: n, a string for notes about the client
     */
    void set_notes(string n);

};

#endif //BUSINESS_TRACKER_CLIENTS_H
