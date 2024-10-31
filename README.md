# Business-Tracker
Created by Shannon Douglas

This program, written in C++, is an interactive way for the user to keep track of their business. It has general outlines of a generic business, so it is flexible for the user's needs. The Business class allows for the user to enter the name of their business, and the name of the owner. The Clients class allows the user to create clients, each of which contain the client's name, address, phone number, status (which the user defines themself to best fit their business), and general notes on the client. The user can add clients or view all of their clients. The Finances class allows the user to enter transactions, of which fall into 5 categories: Revenues, Expenses, Assets, Liabilities, and Miscellaneous/Other. Each transaction contains one of those categories, the dollar value of money involved, the date of the transaction, and a short description. The user can view all their transactions in a list, or they can view their financial statements: the income statement and balance sheet. It calculates their net income, and totals all categories (except miscellaneous) and displays the totals. It also prints a warning note if their assets do not equal liabilities. The Schedule class allows the user to create a list of events consisting of the name of the event, the date, and the start and end times. A schedule "has-an" event(s). Event is the parent class of Meeting and Project, which are types of events the user can add to their schedule. Main() loops through the main menu until the user decides to exit the program. In main, they choose what they want to do, and after completing each action they are brought back to the main menu to make another choice or quit.

## **CONCEPTS**

### **I/O OPERATIONS**

I import two files in this program. One file, client_list.txt, holds information on over 10 clients. In main, the text file is looped through and clients are created and added to the vector.
The other file is finance_list.txt. It holds a bunch of transactions across all enum categories. In main, it's looped through and each finance object is correctly mapped to its enum, then added to the vector.

### **RELATIONSHIPS**
* Schedule HAS-A TimePoint
  * Each object in schedule (except for projects) has two TimePoints, one for the beginning time of the event and one for the end.
* Schedule HAS-AN Event
  * The schedule class holds a vector of event objects that make up the schedule itself.
* Meeting IS-AN Event
  * A meeting is a child of the event class. Aside from inheriting Event's variables, it adds a location and a number of attendees.
* Project IS-AN Event
  * A project is another child of the event class. Its unique variables are a date for the project deadline and a number representing the number of days the project will take. It does not use any TimePoint variables, unlike Event and Meeting.


#### Sources:
* TimePoint class - Created by Lisa Dion, computer science professor at the University of Vermont
* https://cplusplus.com/reference/string/stod/
* https://gist.github.com/leimao/418395bf920eb70b2b11fe89d7c1f738
