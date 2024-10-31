/*
 Shannon Douglas
 CS 2300 B - M2OEP
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "Business.h"
#include "Clients.h"
#include "Finances.h"
#include "Meeting.h"
#include "Project.h"
#include "Schedule.h"
#include "TimePoint.h"

using namespace std;

int menu();
void manage_business();
void manage_clients();
void manage_schedule();
void manage_finances();
Business business;
Finances finances;
Schedule schedule;
// vector<Schedule> schedule_list;
vector<Clients> client_list;
vector<Finances> finance_list;

// Overload the subscript operator
//Schedule& operator[](int index) {
//    return schedule[index];
//}

/*
 * Helper function to get the user to input a double.
 * Returns: a double representing the user input
 */
double get_double() {
    string value;
    bool invalid;

    do {
        cin >> value;
        cin.ignore();
        invalid = false;  // Assume the input is valid

        int dotCt = 0;

        // Check each character to see if it's a digit or a period
        for (char c : value) {
            if (c == '.') {
                ++dotCt;
            }
            if (!isdigit(c) && c != '.' || c == '-') {
                cout << "Invalid input. Enter a positive number: " << endl;
                invalid = true;  // Mark the input as invalid
                break;
            }
            if (dotCt > 1) {
                cout << "Invalid input. Enter a positive number: " << endl;
                invalid = true;
                break;
            }
        }
    } while (invalid);  // Repeat until input is valid
    // Convert string to int and return it
    double num;
    stringstream ss;
    ss << value;
    ss >> num;
    return num;
}

/*
 * Helper function to get the user to choose an int from a given range
 * Parameters: range, an int specifying the limit of the range of allowable inputs (0 to range)
 * Returns: an int representing the user's choice
 */
int get_choice(int range) {
    int choice;
    bool invalid = true;
    do {
        cout << "Enter a number from 1 to " << range << ": ";
        cin >> choice;
        if (cin.fail() || cin.peek() != '\n' || choice < 1 || choice > range) {
            // If invalid, clear buffer to reset it
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. ";
        } else {
            invalid = false;
        }
    } while (invalid);
    return choice;
}

/*
 * Helper function to get a string input from user
 * Returns: a string of whatever the user typed in
 */
string get_string() {
    string input;
    getline(cin, input);
    return input;
}

/*
 * Reads in 5 lines from the Client file, creates Client object, and adds to client vector
 */
void read_client_object() {
    string name, address, phone, status, desc;
    cout << "Enter file name to import clients from: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string filename = get_string();

    // File operations
    ifstream inFile("../" + filename);
    if(!inFile) {
        cout << "Error opening file '" << filename << "'...\n";
        return;
    }
    while (getline(inFile, name) &&
    getline(inFile, address) &&
    getline(inFile, phone) &&
    getline(inFile, status) &&
    getline(inFile, desc)) {

        Clients c(name, address, phone, status, desc);
        client_list.push_back(c);
    }
    cout << "Clients added!\n";
    inFile.close();
}

/*
 * Reads in 5 lines from the Client file, creates Client object, and adds to client vector
 */
void read_finance_object() {
    string finance_type_string, amount_string, date, desc;

    cout << "Enter file name to import finance data from: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string filename = get_string();

    // File operations
    ifstream inFile("../" + filename);
    if(!inFile) {
        cout << "Error opening file '" << filename << "'...\n";
        return;
    }
    while (getline(inFile, finance_type_string) &&
           getline(inFile, amount_string) &&
           getline(inFile, date) &&
           getline(inFile, desc)) {
        double amount = stod(amount_string);
        int finance_type = stoi(finance_type_string);
        Finances f(finance_type, amount, date, desc);
        finance_list.push_back(f);
    }
    cout << "Financial data added!\n";
    inFile.close();
}

int main() {
    cout << "Welcome to myBusinessTracker!" << endl;
    int choice; // Variable representing what number the user selects from the menu

    do {
        // Display menu and get selection from user
        choice = menu();

        if (choice == 1) {
            cout << endl << "********CREATE OR EDIT YOUR BUSINESS********" << endl;
            manage_business();
        } else if (choice == 2) {
            cout << endl << "****************YOUR CLIENTS****************" << endl;
            manage_clients();
        } else if (choice == 3) {
            cout << endl << "***************YOUR SCHEDULE****************" << endl;
            manage_schedule();
        } else if (choice == 4) {
            cout << endl << "******************FINANCES******************" << endl;
            manage_finances();
        } else if (choice == 5) {
            cout << "Exiting program...";
            return 0;
        }
    } while (choice != 5);
}

/*
 * Displays the main menu and gets the user to select a submenu
 * Returns: an int representing the user's selection
 */
int menu() {
    cout << endl << "******************MAIN MENU*****************" << endl;
    cout << "1. Create or edit my business" << endl;
    cout << "2. Add or view clients" << endl;
    cout << "3. View or edit my schedule" << endl;
    cout << "4. Track my finances" << endl;
    cout << "5. Exit" << endl;

    int choice = get_choice(5);
    return choice;
}

/*
 * Allow the user to edit their business name and owner name, or remove the names
 */
void manage_business() {
    int choice;

    cout << "Business name: " << business.get_name() << endl;
    cout << "Owner: " << business.get_owner() << endl;
    cout << "Would you like to make edits?" << endl <<
         "1. Edit business name" << endl <<
         "2. Edit owner name" << endl <<
         "3. Remove names" << endl <<
         "4. Exit to menu" << endl;

    choice = get_choice(4);

    if (choice == 1) {
        // Edit the business name
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Current business name: " << business.get_name() << endl;
        cout << "New name: ";
        string new_name = get_string();
        business.set_name(new_name);
        cout << "Your new business name is " << business.get_name() << endl;
    } else if (choice == 2) {
        // Edit the owner name
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Current owner name: " << business.get_owner() << endl;
        cout << "New name: ";
        string new_name = get_string();
        business.set_owner(new_name);
        cout << "Your new owner name is " << business.get_owner() << endl;
    } else if (choice == 3) {
        // Remove both business and owner names, replace with empty strings
        cout << "Clearing business and owner names..." << endl;
        business.clear_name();
        business.clear_owner();
    }
}

/*
 * Allow the user to add clients and view a list of their clients
 */
void manage_clients() {
    cout << "1. Add a client" << endl << "2. View clients" << endl << "3. Import clients" << endl << "4. Main Menu" << endl;
    int choice = get_choice(4);
    if (choice == 1) {
        // Create a client object and add it to the clients vector
        cout << "***************ADD YOUR CLIENT**************" << endl;
        Clients client;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Client name: ";
        string name = get_string();
        client.set_name(name);

        cout << "Address: ";
        string address = get_string();
        client.set_address(address);

        cout << "Phone Number: ";
        string phone = get_string();
        client.set_phone(phone);

        cout << "Client status: ";
        string status = get_string();
        client.set_status(status);

        cout << "Notes: ";
        string notes = get_string();
        client.set_notes(notes);

        // Display the user's input back to them and confirm adding the client, or let them cancel
        cout << "Adding new client:" << endl;
        cout << "--------------------------------" << endl;
        cout << client;
        cout << "--------------------------------" << endl;
        cout << "Confirm? 1. Yes 2. NO!" << endl;
        int confirm = get_choice(2);
        if (confirm == 1) {
            // Add client object to client vector
            client_list.push_back(client);
        }
    } else if (choice == 2) {
        // Display list of clients by looping through and printing each object in the client vector
        cout << "***************YOUR CLIENT LIST*************" << endl;
        for (int i = 0; i < client_list.size(); ++i) {
            cout << "#" << i+1 << endl;
            cout << client_list[i] << endl;
        }
    } else if (choice == 3) {
        read_client_object();
    }
}

/*
 * Allows the user to add items to their schedule and view everything on their schedule
 */
void manage_schedule() {
    cout << "1. Add item to schedule" << endl
         << "2. View schedule" << endl
         << "3. Main menu" << endl;
    int choice = get_choice(3);


    if (choice == 1) {
        // Create schedule object and add it to the schedule vector
        TimePoint start_time;
        TimePoint end_time;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "What type of event are you adding?" << endl
             << "1. Meeting\n2. Project/Deadline\n3. Other" << endl;
        int event_choice = get_choice(3);
        if (event_choice == 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            Meeting* meeting = new Meeting();
            cout << "Location: ";
            string location = get_string();
            meeting->set_location(location);

            cout << "Number of attendees: ";
            int num_att;
            cin >> num_att;
            meeting->set_num_att(num_att);

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Date of Event: ";
            string date = get_string();
            meeting->set_date(date);

            cout << "Start hour: ";
            int start_hour = get_choice(12);
            start_time.setHour(start_hour);

            cout << "Start minute (enter 60 for 00): ";
            int start_min = get_choice(60);
            if (start_min == 60) {
                start_min = 0;
            }
            start_time.setMinute(start_min);

            cout << "1. AM   2. PM  ";
            int ampm = get_choice(2);
            if (ampm == 1) {
                start_time.makeAM();
            } else {
                start_time.makePM();
            }

            cout << "End hour: ";
            int end_hour = get_choice(12);
            end_time.setHour(end_hour);

            cout << "End minute (enter 60 for 00): ";
            int end_min = get_choice(60);
            end_time.setMinute(end_min);

            cout << "1. AM   2. PM  ";
            ampm = get_choice(2);
            if (ampm == 1) {
                end_time.makeAM();
            } else {
                end_time.makePM();
            }
// Add start and end times to schedule object
            meeting->set_start_time(start_time);
            meeting->set_end_time(end_time);

            // Display their input back to them and confirm they want to add the item
            cout << "Adding new schedule item:" << endl;
            cout << "-------------------------------------------------------------------------" << endl;
            cout << *meeting;
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "Confirm? 1. Yes 2. NO!" << endl;
            int confirm = get_choice(2);
            if (confirm == 1) {
                schedule.add_event(meeting);
            }

        } else if (event_choice == 2) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            Project* project = new Project();
            cout << "Deadline (date): ";
            string deadline = get_string();
            project->set_deadline(deadline);

            cout << "Duration of project (in days): ";
            int dur;
            cin >> dur;
            project->set_duration(dur);

            // Display their input back to them and confirm they want to add the item
            cout << "Adding new schedule item:" << endl;
            cout << "-----------------------------------------------------------------------------------------------" << endl;
            cout << *project;
            cout << "-----------------------------------------------------------------------------------------------" << endl;
            cout << "Confirm? 1. Yes 2. NO!" << endl;
            int confirm = get_choice(2);
            if (confirm == 1) {
                schedule.add_event(project);
            }

        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            Event* event = new Event();
            cout << "Event Name: ";
            string name = get_string();
            event->set_name(name);

            cout << "Date of Event: ";
            string date = get_string();
            event->set_date(date);

            cout << "Start hour: ";
            int start_hour = get_choice(12);
            start_time.setHour(start_hour);

            cout << "Start minute (enter 60 for 00): ";
            int start_min = get_choice(60);
            if (start_min == 60) {
                start_min = 0;
            }
            start_time.setMinute(start_min);

            cout << "1. AM   2. PM  ";
            int ampm = get_choice(2);
            if (ampm == 1) {
                start_time.makeAM();
            } else {
                start_time.makePM();
            }

            cout << "End hour: ";
            int end_hour = get_choice(12);
            end_time.setHour(end_hour);

            cout << "End minute (enter 60 for 00): ";
            int end_min = get_choice(60);
            end_time.setMinute(end_min);

            cout << "1. AM   2. PM  ";
            ampm = get_choice(2);
            if (ampm == 1) {
                end_time.makeAM();
            } else {
                end_time.makePM();
            }

            // Add start and end times to schedule object
            event->set_start_time(start_time);
            event->set_end_time(end_time);

            // Display their input back to them and confirm they want to add the item
            cout << "Adding new schedule item:" << endl;
            cout << "---------------------------------------------------" << endl;
            cout << *event;
            cout << "---------------------------------------------------" << endl;
            cout << "Confirm? 1. Yes 2. NO!" << endl;
            int confirm = get_choice(2);
            if (confirm == 1) {
                schedule.add_event(event);
            }
        }

    } else if (choice == 2) {
        schedule.schedule_header();
        cout << schedule << endl;
    }
}
/*
 * Allows the user to add transactions, view all transactions, and view financial statements
 */
void manage_finances() {
    cout << "1. Add a transaction" << endl
         << "2. View all transactions" << endl
         << "3. View financial statements" << endl
         << "4. Import finances" << endl
         << "5. Main menu" << endl;
    int choice = get_choice(5);

    if (choice == 1) {
        // Create a transaction object: category, amount, date, and description
        FinanceType category = Finances::get_type_input();
        finances.set_category(category);

        cout << "Transaction amount: $";
        double amount = get_double();
        finances.set_amount(amount);

        cout << "Date of transaction: ";
        string date = get_string();
        finances.set_date(date);

        cout << "Short description: ";
        string desc = get_string();
        finances.set_description(desc);

        // Add object to finance_list vector
        cout << "Updating your records..." << endl << endl;
        finance_list.push_back(finances);

    } else if (choice == 2) {
        // Loop through vector and print each transaction object
        Finances::show_header();
        for (int i = 0; i < finance_list.size(); ++i) {
            cout << finance_list[i];
        }
    } else if (choice == 3) {
        // Display organized financial statements
        // Separate each type into its own vector to easily print them
        vector <Finances> revenues, expenses, assets, liabilities;
        for (int i = 0; i < finance_list.size(); ++i) {
            switch (finance_list[i].get_category()) {
                case FinanceType::Revenue:
                    revenues.push_back(finance_list[i]);
                    break;
                case FinanceType::Expense:
                    expenses.push_back(finance_list[i]);
                    break;
                case FinanceType::Asset:
                    assets.push_back(finance_list[i]);
                    break;
                case FinanceType::Liability:
                    liabilities.push_back(finance_list[i]);
                    break;
                case FinanceType::Miscellaneous:
                    break;
            }
        }
        // Output Income Statement
        cout << endl << "INCOME STATEMENT" << endl
             << "------------------------------------" << endl
             << "REVENUES" << endl;
        // Loop through revenue vector, print item, and sum transaction amounts
        double total_revenue = 0;
        double total_expenses = 0;
        double net_income;
        double total_assets = 0;
        double total_liabilities = 0;

        // Print all revenues
        for (int i = 0; i < revenues.size(); ++i) {
            total_revenue += revenues[i].get_amount();
            cout << "$" << revenues[i].get_amount() << "     ";
            cout << revenues[i].get_description() << endl;
        }
        cout << "TOTAL REVENUE:        $" << total_revenue << endl << endl;
        // Print all expenses
        cout << "EXPENSES" << endl;
        for (int i = 0; i < expenses.size(); ++i) {
            total_expenses += expenses[i].get_amount();
            cout << "$" << expenses[i].get_amount() << "     ";
            cout << expenses[i].get_description() << endl;
        }
        net_income = total_revenue - total_expenses;
        cout << "TOTAL EXPENSES:       $" << total_expenses << endl;
        cout << "------------------------------------" << endl;
        cout << "NET INCOME:           $" << net_income << endl;

        // Output Balance Sheet
        cout << endl << endl << "BALANCE SHEET" << endl
             << "------------------------------------" << endl
             << "ASSETS" << endl;

        // Print all assets
        for (int i = 0; i < assets.size(); ++i) {
            total_assets += assets[i].get_amount();
            cout << "$" << assets[i].get_amount() << "     ";
            cout << assets[i].get_description() << endl;
        }
        cout << "TOTAL ASSETS:         $" << total_assets << endl << endl;
        // Print all liabilities
        cout << "LIABILITIES" << endl;
        for (int i = 0; i < liabilities.size(); ++i) {
            total_liabilities += liabilities[i].get_amount();
            cout << "$" << liabilities[i].get_amount() << "     ";
            cout << liabilities[i].get_description() << endl;
        }
        cout << "TOTAL LIABILITIES:    $" << total_liabilities << endl;
        // Error note if assets do not equal liabilities + equity
        if (total_assets != total_liabilities + net_income) {
            cout << "* * * UH OH! YOUR ACCOUNTS ARE NOT BALANCED! * * *" << endl;
        }
    } else if (choice == 4) {
        read_finance_object();
    }
}





