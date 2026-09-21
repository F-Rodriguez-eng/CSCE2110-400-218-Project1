#include Resource.h
#include Resource.cpp
#include Reservation.cpp
#include Reservation.h
#include ReservationManagement.cpp
#include ReservationMnagement.h
#include <iostream>
#include <string>  
#include <stack>
#include <map>

using namespace std;

//WAITING LIST
class WaitingList{
  private:
//
string studentID;
string studentName;
string resource ID;
string requestDate;
int entryposition;
  
public:
    // Contructor
    // Initializes a new waiting list entry
  WaitingListEntry(const string& studID = "", 
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
   bool operator==(const WaitingListEntry& other) const;  // Compare entries
};

};

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
        cout << "Cancellation History:" << endl;
        cout << "********************" << endl;
        while (!temp.empty()) 
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

  public:
    //Initializing object
    ReportGenerator(ReservationManger* rm, vector<Resource>* resources);

    //Generates Availability Report
    void availabilityReport();
    //Generates Reservations Currently Active
    void activeReservationReport();
    //Generates Waiting list Report
    void waitListReport();
    //Generates most frequent;y requested resources report
    void mostFrequentRsrcReport();
};

//Availability
void ReportGenerator::availabilityReport(){
  cout << "\n==== Current Availability ====\n";

  for(const Resource& resource : *resources){
    cout << resource << endl;
  }//Work In Progress

}

//Active
void ReportGenerator::activeReservationReport(){
  cout << "\n==== Avtice Reservations Report ====\n";

  cout << "Total Active Reservations: " << reservationManager->getActiveReservationCount() << endl;
} //Work In Progress

void ReportGenerator::waitListReport(){
  cout << "\n==== Waiting List Availability ====\n";

  reservationManager->waitListReport();
}

void ReportGenerator::mostFrequentRsrcReport(){
  cout << "\n==== Most Frequently Request Resources Report ====\n";
  
  map<string, int> resourceCount;

  ReservationNode* current = reservationManager->getHead();

  while (current!=nullptr){
    string resourceID = current->data.getResourceID();//make get function

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
    if (pair.second > highsetCount){
      highestCount = pair.second;
      mostFrequentRsrc = pair.first;
    }
  }

  cout << "Most Requested Resource ID: " << mostFrequentRsrc << endl;
  cout << "Number of Reservations: " << highestCount << endl;
}

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
}


