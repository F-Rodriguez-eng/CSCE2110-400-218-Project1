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
void ReservationManager::createReserv(Reservation r){
  //create new node containing reservation
  ReservationNode newNode = new ReservationNode(r);

  //insert node infront of list
  newNode->next = head;
  head = newNode;

  cout << "Your reservation was created successfully." << endl;

}

//displays all active reservations
void ReservationManager::viewReservations(){
  //check if list is empty
  if (head == nullptr){
    cout << "No reservations in line." << endl;
    return;
  }

  ReservationNode* current = head;

  //traverse linked list
  while (current != nullptr){

    //display reservation info
    current -> data.display();

    cout << "********************" << endl;

    current = current->next;
  }

}

Reservation* ReservationManager::searchReserv(int reservationID){
  ReservationNode* current = head;

  //traverse linked list
  while (current != nullptr){
    //checking if IDs match
    if (current->data.getReservationID() == reservationID){

      return &(current->data);
    }

    current = current->next;
  }

  //no matching reservation was found
  return nullptr;
}

//cancels reservation
bool ReservationManager::cancelReserv(int reservationID){
  ReservationNode* current = head;
  ReservationNode* previous = nullptr;

  //search via traversal
  while (current != nullptr){
    
    if (current->data.getReservationID() == reservationID){

      //save reservation to stack
      cancelHistory.push(current->data);

      //remove first node
      

      //remove mid or last node
    }

  }

}