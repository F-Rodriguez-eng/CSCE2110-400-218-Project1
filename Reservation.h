#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

class Reservation {
private:
    int reservationID;
    std::string studentID; 
    std::string studentName;
    std::string resourceID;
    std::string reservationDate;
    std::string startTime;
    std::string endTime;
    bool active; // true = active, false = cancelled.
    static int timeToMinutes(const std::string& time);

public:
    Reservation();

    Reservation(
        int reservationID,
        const std::string& studentID,
        const std::string& studentName,
        const std::string& resourceID,
        const std::string& reservationDate,
        const std::string& date,
        const std::string& startTime,
        const std::string& endTime
    );
