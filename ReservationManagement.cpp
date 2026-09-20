#include "ReservationManager.h"

//default constructor, inits linked list by setting head ptr to nullptr, meaning no active reservations
ReservationManager::ReservationManager(){
  head = nullptr;
}

//destructor, traverses linked list to delete every node to free dyn malloc and stop mem leaks
ReservationManager::~ReservationManager(){
  ReservationNode* current = head;

  while (current != nullptr) {
    ReservationNode* temp = current;
    current = current->next;
    delete temp;
  }
}

//creates Reservation
