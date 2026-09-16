#IFNDEF "RESERVATIONMANAGEMENT_H"
#DEFINE "RESERVATIONMANAGEMENT_H"
#include <string>
#include <iostream>

/*
Reservation Management
Users shall be able to:

Create a reservation.
Cancel a reservation.
View current reservations.
Search for reservations.
Each reservation must contain:

Reservation ID
Student ID
Student Name
Resource ID
Reservation Date
Waiting List Management
When a resource is unavailable:

Student requests must be placed in a waiting queue.
Requests must be processed in FIFO order.
Available resources must automatically be assigned to the next waiting user.
Reservation History
The system shall maintain a cancellation history.

When a reservation is cancelled:

It is stored on a stack.
Users may undo the most recent cancellation.
Only the most recently cancelled reservation may be restored.

Reporting
The system shall generate reports including:

Most frequently reserved resources
Current availability
Number of active reservations
Waiting list reports
*/

//RESERVATION MANAGEMENT
class ReservationManager{
  private:



  public:

};

//WAITING LIST
class WaitingList{
  private:

  public:

};

//CANCELATION
class CancelationHistory{
  private:

  public:

};

//REPORT GEN
class ReportGenerator{
  private:

  public:

};

#ENDIF
