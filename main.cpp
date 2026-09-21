#include Resource.h
#include Resource.cpp
#include Reservation.cpp
#include Reservation.h
#include ReservationManagement.cpp
#include ReservationMnagement.h
#include <iostream>
#include <string>  

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
class CancelationHistory{
  private:

  public:

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

void ReportGenerator::availabilityReport(){
  cout << "\n==== Current Availability ====\n";
}
