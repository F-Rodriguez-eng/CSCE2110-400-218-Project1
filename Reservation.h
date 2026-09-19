#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

class Reservation {
private:
    int reservationID;
    std::string studentID; 
    std::string resourceID;
    std::string date;
    std::string startTime;
    std::string endTime;
    bool active; // true = active, false = cancelled.

public:
    Reservation();

    Reservation(
        int reservationID,
        const std::string& studentID,
        const std::string& resourceID,
        const std::string& date,
        const std::string& startTime,
        const std::string& endTime
    );
