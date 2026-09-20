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

//creates new reservation node, inserts at beginning of linked list, r is reservation obj
void ReservationManager::createReserv(Reservation r){
  //create node
  ReservationNode* newNode = new ReservationNode(r);

  //insert node at front of list
  newNode->next = head;
  head = newNode;

  cout << "Your reservation was created successfully." << endl;
}

//dispalys all active reservations (excluding recently cancelled)
void ReservationManager::viewR





Reservation* ReservationManager::searchReserv



bool ReservationManager::cancelReservation(int placeholdReservID){



}


void ReservationManager::addToWaitList(Reservation r){


}


void ReservationManager::processWaitList(){


}


void ReservationManger::undoCancel(){

}
