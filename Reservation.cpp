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


// converts time from xx:xx to minutes for easier comparison
int Reservation::timeToMinutes(const string& time) {

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

int Reservation::getReservationID() const {
    return reservationID;
}

string Reservation::getStudentID() const {
    return studentID;
}

string Reservation::getStudentName() const {
    return studentName;
}

string Reservation::getResourceID() const {
    return resourceID;
}

string Reservation::getReservationDate() const {
    return reservationDate;
}

string Reservation::getStartTime() const {
    return startTime;
}

string Reservation::getEndTime() const {
    return endTime;
}

bool Reservation::isActive() const {
    return active;
}

// checks if reservation is valid
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
// managing cancellations
void Reservation::cancel() {
    active = false;
}

void Reservation::restore() {
    active = true;
}

// display
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
