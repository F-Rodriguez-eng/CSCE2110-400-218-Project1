#include "Reservation.h"

#include <iostream>
#include <cctype>

using namespace std;

Reservation::Reservation() {
    reservationID = 0;
    studentID = "";
    studentName = "";
    resourceID = "";
    reservationDate = "";
    startTime = "";
    endTime = "";
    active = false;
}


// new active reservation w/given info
Reservation::Reservation(
    int reservationID,
    const string& studentID,
    const string& studentName,
    const string& resourceID,
    const string& reservationDate,
    const string& startTime,
    const string& endTime
) {
    this->reservationID = reservationID;
    this->studentID = studentID;
    this->studentName = studentName;
    this->resourceID = resourceID;
    this->reservationDate = reservationDate;
    this->startTime = startTime;
    this->endTime = endTime;
    active = true;
}


// converting time to total mins, i.e xx:30 --> xxx minutes. 
int Reservation::timeToMinutes(const string& time) {

    // valid xx:xx should only be 5 characters 
    if (time.length() != 5 || time[2] != ':') {
        return -1;
    }

    
    if (!isdigit(time[0]) ||
        !isdigit(time[1]) ||
        !isdigit(time[3]) ||
        !isdigit(time[4])) {

        return -1;
    }

    
    int hour =
        (time[0] - '0') * 10 +
        (time[1] - '0');

   
    int minute =
        (time[3] - '0') * 10 +
        (time[4] - '0');

   
    if (hour < 0 || hour > 23) {
        return -1;
    }

   
    if (minute < 0 || minute > 59) {
        return -1;
    }

    return (hour * 60) + minute;
}

// returns reservation unique ID
int Reservation::getReservationID() const {
    return reservationID;
}

// returns student id
string Reservation::getStudentID() const {
    return studentID;
}

// studentname
string Reservation::getStudentName() const {
    return studentName;
}

// resourceid
string Reservation::getResourceID() const {
    return resourceID;
}

// date
string Reservation::getReservationDate() const {
    return reservationDate;
}

// starttime
string Reservation::getStartTime() const {
    return startTime;
}

// endtime
string Reservation::getEndTime() const {
    return endTime;
}

// true = active
bool Reservation::isActive() const {
    return active;
}

bool Reservation::isValid() const {

    if (reservationID <= 0) {
        return false;
    }

    if (studentID.empty() ||
        studentName.empty() ||
        resourceID.empty() ||
        reservationDate.empty() ||
        startTime.empty() ||
        endTime.empty()) {

        return false;
    }

    int start = timeToMinutes(startTime);
    int end = timeToMinutes(endTime);

    if (start == -1 || end == -1) {
        return false;
    }

    if (start >= end) {
        return false;
    }

    return true;
}

// conflict checks
bool Reservation::conflictsWith(const Reservation& other) const {

    if (!active || !other.active) {
        return false;
    }

    if (resourceID != other.resourceID) {
        return false;
    }

    if (reservationDate != other.reservationDate) {
        return false;
    }
    int thisStart = timeToMinutes(startTime);
    int thisEnd = timeToMinutes(endTime);

    int otherStart = timeToMinutes(other.startTime);
    int otherEnd = timeToMinutes(other.endTime);

    if (thisStart == -1 ||
        thisEnd == -1 ||
        otherStart == -1 ||
        otherEnd == -1) {

        return false;
    }

    return thisStart < otherEnd &&
           otherStart < thisEnd;
}


// for managing cancellations
void Reservation::cancel() {
    active = false;
}

void Reservation::restore() {
    active = true;
}

void Reservation::display() const {

    cout << "Reservation ID: " << reservationID << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "Student Name: " << studentName << endl;
    cout << "Resource ID: " << resourceID << endl;
    cout << "Reservation Date: " << reservationDate << endl;
    cout << "Start Time: " << startTime << endl;
    cout << "End Time: " << endTime << endl;

    if (active) {
        cout << "Status: Active" << endl;
    }
    else {
        cout << "Status: Cancelled" << endl;
      // Default constructor.
// Creates an empty reservation that is not active.
Reservation::Reservation() {
    reservationID = 0;
    studentID = "";
    studentName = "";
    resourceID = "";
    reservationDate = "";
    startTime = "";
    endTime = "";
    active = false;
}


// Parameterized constructor.
// Creates a new active reservation using the provided information.
Reservation::Reservation(
    int reservationID,
    const string& studentID,
    const string& studentName,
    const string& resourceID,
    const string& reservationDate,
    const string& startTime,
    const string& endTime
) {
    this->reservationID = reservationID;
    this->studentID = studentID;
    this->studentName = studentName;
    this->resourceID = resourceID;
    this->reservationDate = reservationDate;
    this->startTime = startTime;
    this->endTime = endTime;
    active = true;
}


// Converts a time in HH:MM format into total minutes.
//
// Example:
// "10:30" becomes 630 minutes.
//
// This makes comparing reservation times easier.
int Reservation::timeToMinutes(const string& time) {

    // Valid HH:MM format should contain exactly 5 characters.
    if (time.length() != 5 || time[2] != ':') {
        return -1;
    }

    // Make sure each hour/minute position contains a digit.
    if (!isdigit(time[0]) ||
        !isdigit(time[1]) ||
        !isdigit(time[3]) ||
        !isdigit(time[4])) {

        return -1;
    }

    // Convert hour characters into an integer.
    int hour =
        (time[0] - '0') * 10 +
        (time[1] - '0');

    // Convert minute characters into an integer.
    int minute =
        (time[3] - '0') * 10 +
        (time[4] - '0');

    // Valid hours are 00 through 23.
    if (hour < 0 || hour > 23) {
        return -1;
    }

    // Valid minutes are 00 through 59.
    if (minute < 0 || minute > 59) {
        return -1;
    }

    return (hour * 60) + minute;
}


// ------------------------------------------------------
// Getters
// ------------------------------------------------------

// Returns the reservation's unique ID.
int Reservation::getReservationID() const {
    return reservationID;
}


// Returns the ID of the student who made the reservation.
string Reservation::getStudentID() const {
    return studentID;
}


// Returns the name of the student who made the reservation.
string Reservation::getStudentName() const {
    return studentName;
}


// Returns the ID of the resource being reserved.
string Reservation::getResourceID() const {
    return resourceID;
}


// Returns the reservation date.
string Reservation::getReservationDate() const {
    return reservationDate;
}


// Returns the reservation's starting time.
string Reservation::getStartTime() const {
    return startTime;
}


// Returns the reservation's ending time.
string Reservation::getEndTime() const {
    return endTime;
}


// Returns true if the reservation is currently active.
bool Reservation::isActive() const {
    return active;
}


// ------------------------------------------------------
// Reservation Validation
// ------------------------------------------------------

// Checks whether the reservation contains valid information.
bool Reservation::isValid() const {

    // Reservation IDs should be positive.
    if (reservationID <= 0) {
        return false;
    }

    // Required information cannot be empty.
    if (studentID.empty() ||
        studentName.empty() ||
        resourceID.empty() ||
        reservationDate.empty() ||
        startTime.empty() ||
        endTime.empty()) {

        return false;
    }

    // Convert the reservation times into minutes.
    int start = timeToMinutes(startTime);
    int end = timeToMinutes(endTime);

    // -1 means one of the times was invalid.
    if (start == -1 || end == -1) {
        return false;
    }

    // End time must occur after start time.
    if (start >= end) {
        return false;
    }

    return true;
}


// ------------------------------------------------------
// Conflict Checking
// ------------------------------------------------------

// Checks whether this reservation conflicts with another.
//
// ReservationManager can use this while traversing the
// linked list before adding a new reservation.
bool Reservation::conflictsWith(const Reservation& other) const {

    // Cancelled reservations should not create conflicts.
    if (!active || !other.active) {
        return false;
    }

    // Different resources cannot conflict.
    if (resourceID != other.resourceID) {
        return false;
    }

    // Different reservation dates cannot conflict.
    if (reservationDate != other.reservationDate) {
        return false;
    }

    int thisStart = timeToMinutes(startTime);
    int thisEnd = timeToMinutes(endTime);

    int otherStart = timeToMinutes(other.startTime);
    int otherEnd = timeToMinutes(other.endTime);

    // Do not compare reservations containing invalid times.
    if (thisStart == -1 ||
        thisEnd == -1 ||
        otherStart == -1 ||
        otherEnd == -1) {

        return false;
    }

    /*
        Example:

        Reservation 1:
        10:00 - 11:00

        Reservation 2:
        10:30 - 11:30

        These reservations overlap because
        the second reservation begins before
        the first one ends.
    */
    return thisStart < otherEnd &&
           otherStart < thisEnd;
}


// ------------------------------------------------------
// Cancellation Management
// ------------------------------------------------------

// Marks the reservation as cancelled.
//
// ReservationManager can remove it from the active linked list,
// while CancelationHistory stores the cancelled reservation.
void Reservation::cancel() {
    active = false;
}


// Restores a previously cancelled reservation.
//
// This can be used when undoing the most recent cancellation.
void Reservation::restore() {
    active = true;
}


// ------------------------------------------------------
// Display
// ------------------------------------------------------

// Displays all reservation information.
//
// ReservationManager can call this when traversing
// and displaying active reservations.
void Reservation::display() const {

    cout << "Reservation ID: " << reservationID << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "Student Name: " << studentName << endl;
    cout << "Resource ID: " << resourceID << endl;
    cout << "Reservation Date: " << reservationDate << endl;
    cout << "Start Time: " << startTime << endl;
    cout << "End Time: " << endTime << endl;

    if (active) {
        cout << "Status: Active" << endl;
    }
    else {
        cout << "Status: Cancelled" << endl;
    }

    cout << "--------------------------------" << endl;
}
    }

    cout << "--------------------------------" << endl;
}
