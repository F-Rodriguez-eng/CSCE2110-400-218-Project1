#include "Resource.h"
//#include Resource.cpp
//#include Reservation.cpp //headers only
#include "Reservation.h"
//#include ReservationManagement.cpp
#include "ReservationMnagement.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>  
#include <stack>
#include <map>
#include <cctpye>
#include <stdlib>

using namespace std;

const string RESOURCE_FILE = "resources.txt";
const string RESERVATION_FILE = "reservations.txt";
const int MAX_RESERVID = 1000;

//WAITING LIST
class WaitingList{
  private:
//
string studentID;
string studentName;
string resourceID;
string requestDate;
int entryposition;

public:
    // Contructor
    // Initializes a new waiting list entry
  WaitingList(const string& studID = "",
                     const string& studName = "",
                     const string& resID = "",
                     const string& date = ""); // Getters
// Get student ID
string getStudentID() const;
// Returns student name
string getStudentName() const;
// Returns resource ID
string getResourceID() const;
// Returns request date
string getRequestDate() const;
 // Returns position in queue
 int getEntryPosition() const;
    
    
  // Setters
  //This sets the position in the queue
  void setEntryPosition(int pos);

  // This displays the entry
  void display() const;

  // Operator overload that compares the entries
   bool operator==(const WaitingList& other) const;  // Compare entries
};

WaitingList::WaitingList(const string& stuID, const string& studName, const string& resID, const string& date){
    studentID = stuID;
    studentName = studName;
    resourceID = resID;
    requestDate = date;
    entryposition = 0;
}

string Waitinglist::getStudentID() const{
    return studentID;
}

string Waitinglist::getStudentName() const{
    return studentName;
}

string Waitinglist::getResourceID() const{
    return resourceID;
}

string Waitinglist::getRequestDate() const{
    return requestDate;
}

int WaitingList::getEntryPosition() const{
    return entryposition;
}

void WaitingList::setEntryPosition(int pos){
    entryposition = pos;
}

void WaitingList::display() const{
    cout << "Position " << entryposition << endl << 
    "Student ID: " << studentID << endl <<
    "Name: " << studentName << endl <<
    "Resource: " << resourceID << endl <<
    "Date: " << requestDate << endl;
}

bool WaitingList::operator==(const WaitingList& rhs) const{
    return studentID == rhs.studentID && resourceID == rhs.studentID && requestDate == rhs.requestDate;
}

//CANCELATION
// CANCELLATION HISTORY
class CancelationHistory {
private:
    stack<Reservation> cancelHistory;

public:
    void push(const Reservation& reservation) {
        cancelHistory.push(reservation);
    }
    bool empty() const {
        return cancelHistory.empty();
    }

    Reservation top() const {
        if (cancelHistory.empty()) {
            cout << "No cancelled reservations available." << endl;
            return Reservation();
        }
        return cancelHistory.top();
    }

    void pop() {
        if (!cancelHistory.empty()) {
            cancelHistory.pop();
        } // removes most recently canceled 
    }

    void displayHistory() const {
        if (cancelHistory.empty()) {
            cout << "No cancellation history." << endl;
            return;
        }
        stack<Reservation> temp = cancelHistory;
        cout << "Cancellation History:" << endl;//LIFO
        cout << "********************" << endl;
        while (!temp.empty()) {
            temp.top().display();
            cout << "********************" << endl;
            temp.pop();
        }
    }
};

//REPORT GEN
class ReportGenerator{
  private:
    ReservationManager* reservationManager;
    vector<Resource>* resources;
    queue<WaitingList>* WaitingList;

    public:
    //Initializing object
    ReportGenerator(ReservationManager* rm, vector<Resource>* resources, queue<WaitingList>* waitingList);

    //Generates Availability Report
    void availabilityReport();
    //Generates Reservations Currently Active
    void activeReservationReport();
    //Generates Waiting list Report
    void waitListReport();
    //Generates most frequently requested resources report
    void mostFrequentRsrcReport();
};

//report generator
ReportGenerator::ReportGenerator(ReservationManager* rm, vector<Resource>* resources, queue<WaitingList>* waitingList){
    reservationManager = rm;
    this->resources = resources;
    this->WaitingList = waitingList;
}

//Availability resport
void ReportGenerator::availabilityReport(){
    cout << "\n==== Current Availability ====\n";

    int availableCount = 0;

    for(const Resource& resource : *resources){
        cout << resource << endl;

        if (resource.getIsAvailable()){
        availableCount++;
        }
    }

    cout << "Available resources: " << availableCount << " of " << resources->size() << endl;
}
//Active reservation report
void ReportGenerator::activeReservationReport(){
    cout << "\n==== Active Reservations Report ====\n";

    cout << "Total Active Reservations: " << reservationManager->getActiveReservationCount() << endl;
}


//wait list report
void ReportGenerator::waitListReport(){
    cout << "\n==== Waiting List Availability ====\n";

    cout << "Students waiting: " << waitingList->size() << endl;

    queue<WaitingList> temp = *waitingList;

    while (!temp.empty()){
        temp.front().display();
        temp.pop();
    }
}

//most freq resource report
void ReportGenerator::mostFrequentRsrcReport(){
  cout << "\n==== Most Frequently Request Resources Report ====\n";

  map<string, int> resourceCount;

  ReservationNode* current = reservationManager->getHead();

  while (current!=nullptr){
    string resourceID = current->data.getResourceID();

    resourceCount[resourceID]++;

    current = current->next;
    }

    if (resourceCount.empty()){
    cout << "No reservations found." <<endl;
    return;
    }

    string mostFrequentRsrc;
    int highestCount = 0;

    for (const auto& pair : resourceCount){
        if (pair.second > highestCount){
            highestCount = pair.second;
            mostFrequentRsrc = pair.first;
    }
  }

  cout << "Most Requested Resource ID: " << mostFrequentRsrc << endl;
  cout << "Number of Reservations: " << highestCount << endl;
}

//input reading helpers

//white space cleaning
string trim(const string& text){
    size_t start = text.find_first_not_of(" \t\r\n");

    if (start == string::npos){
        return "";
    }

    size_t end = text.find_last_not_of(" \t\r\n");
    return text.substr(start, end - start + 1);
}

string toUpper(string text){
    for (size_t i = 0; i < text.length(); i++){
        text[i] = toupper(static_cast<unsigned char>(text[i]));
    }
    return text;
}

//if text is whole num with nothing after then true
bool parseInt(const string& text, int& value){
    stringstream strstrm(text);
    char extra;

    if(!(strstrm >> value)){
        return false;
    }

    if(strstrm >> extra){
        return false;
    }

    return true;
}

string readLin(const string& prompt){
    cout << prompt;

    string line;

    //end of file, nothing left to read
    if (!getLine(cin, line)){
        cout << "\nInput closed. Goodbye." << endl;
        exit(0);
    }

    return trim(line);
}

//continues prompting until something is typed
string readNotEmpty(const string& prompt){
    while (true){
        string line = readLin(prompt);

        if (!line.empty()){
            return line;
        }

        cout << "Input can't be empty. Try again." << endl;
    }
}

//continues prompting for whole num from min to max is typed
int readInt(const string& prompt, int min, int max){
    while(true){
       int value;

       if (parseInt(readLin(prompt), value) && value >= min && value <= max){
        return value;
       }

       cout << "Invalid input. Enter a whole number from " <<min << " to " << max << "." << endl;
    }
}

bool readYN(const string& prompt){
    while(true){
        string ans = toUpper(readLin(prompt));
    }
}

//validation help



//menu display
void displayMenu(){
  cout << "\n===== Campus Resource Reservation System =====" << endl;
  cout << "1. View Resources" << endl;
  cout << "2. Create Reservation" << endl;
  cout << "3. Cancel Reservation" << endl;
  cout << "4. View Waiting Lists" << endl;
  cout << "5. Undo Cancellation" << endl;
  cout << "6. Search Reservations" << endl;
  cout << "7. Sort Resources" << endl;
  cout << "8. Generate Report" << endl;
  cout << "9. Exit" << endl;
  cout << "Enter Choice: ";

    //we will use the switch statement to check the user's statement and call the right function
    //we will call all the functions on the display menu as cases
    switch (choice){
    //for the first case, we will call all the campus resources
        case 1:
        displayResources();
        break;
        
    //create a reservation for a student and add to the waiting list if not available
        case 2:
        createReservation();
        break;
    //Case 3 cancels an existing reservation and placing it on the cancellationhistory
        case 3:
        cancelReservation();
        break;
    //disaplay waiting list
        case 4:
        displayWaitingLists();
    //Show the recent cancelled reservation
        case 5:
        undoCancellation();
        break;
    //search for reservation 
        case 6:
        searchReservation();
        break;
    //Sorts all resources    
        case 7:
        sortResources();
        break;
        
    //gives reports on most elements above  
        case 8:
        generateReport();
        break;
    }
       
  
}


