# M2OEP-srdougla
Name: Shannon Douglas

Summary: This program is an interactive way for the user to keep track of their business. It has general outlines of a generic business, so it is flexible for the user's needs. The Business class allows for the user to enter the name of their business, and the name of the owner. The Clients class allows the user to create clients, each of which contain the client's name, address, phone number, status (which the user defines themself to best fit their business), and general notes on the client. The user can add clients or view all of their clients. The Finances class allows the user to enter transactions, of which fall into 5 categories: Revenues, Expenses, Assets, Liabilities, and Miscellaneous/Other. Each transaction contains one of those categories, the dollar value of money involved, the date of the transaction, and a short description. The user can view all their transactions in a list, or they can view their financial statements: the income statement and balance sheet. It calculates their net income, and totals all categories (except miscellaneous) and displays the totals. It also prints a warning note if their assets do not equal liabilities. The Schedule class allows the user to create a list of events consisting of the name of the event, the date, and the start and end times. A schedule "has-an" event(s). Event is the parent class of Meeting and Project, which are types of events the user can add to their schedule. Main() loops through the main menu until the user decides to exit the program. In main, they choose what they want to do, and after completing each action they are brought back to the main menu to make another choice or quit.

List of concepts:

I/O OPERATIONS
I import two files in this program. One file, client_list.txt, holds information on over 10 clients. In main, the text file is looped through and clients are created and added to the vector.
The other file is finance_list.txt. It holds a bunch of transactions across all enum categories. In main, it's looped through and each finance object is correctly mapped to its enum, then added to the vector.

RELATIONSHIPS
Schedule HAS-A TimePoint
Each object in schedule (except for projects) has two TimePoints, one for the beginning time of the event and one for the end.
Schedule HAS-AN Event
The schedule class holds a vector of event objects that make up the schedule itself.
Meeting IS-AN Event
A meeting is a child of the event class. Aside from inheriting Event's variables, it adds a location and a number of attendees.
Project IS-AN Event
A project is another child of the event class. Its unique variables are a date for the project deadline and a number representing the number of days the project will take. It does not use any TimePoint variables, unlike Event and Meeting.

Any known bugs: I haven't found any bugs. However I don't have input validation for every single input the user enters.

Future work: I'm not sure how I would do this yet, but I want to add a functionality where when you go to add an item to your schedule, you can select a client from your list of clients and "map" that schedule item to that client. Then, when you view your clients, you can also see any corresponding meetings you have with them. I also want to link clients to expenses from the finance class, for example there can be a sub-category within Revenues and Expenses where the user can relate that to a client or not. If they do want to link it to a client, they get a list of their clients that they can choose from to map that expense or revenue to. I also want to do more math in the finance class. For example, if someone inputs their tax rate, the program will automatically add an expense for taxes and deduct that from net income. Also, on a simpler note, I want to allow the user to delete clients and schedule items if they want to. I also want to overload an operator to evaluate which date comes before another date, so I can print schedule items in chronological order.


Sources:
* TimePoint class: Created by Lisa Dion, part of the "Meeting" program used in class
* To convert a string to a double: https://cplusplus.com/reference/string/stod/
* Citations: https://gist.github.com/leimao/418395bf920eb70b2b11fe89d7c1f738 > How to clear the input buffer
