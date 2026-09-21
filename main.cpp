#include Resource.h
#include Resource.cpp
#include Reservation.cpp
#include Reservation.h
#include ReservationManagement.cpp
#include ReservationMnagement.h
#include <iostream>
#include <string>  
#include <stack>

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

  public:

};
