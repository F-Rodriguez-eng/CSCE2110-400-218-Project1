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
      if (previous->next = current->next){
        head = current->next;
      }

      //remove mid or last node
      else{
       previous->next = current->;
      }

      delete current;
      cout << "You have canceled the reservation" << endl;

      //reassign reservation to next on waiting list
      return true;
    }

    previous = current;
    current = current->next
  }

  //chosen reservation not found
  return false
}

//adding reservation request to wait list queue
void ReservationManager::addToWaitList(Reservation r) {
  waitList.push(r);

  cout << "Reservation added to wait list" << endl;
}

void ReservationManager::processWaitList(){

  //wait requests empty
  if (waitList.empty()){
    return;
  }

  //get first reservation request
  Reservation nextReservation = waitList.front();

  //remove from queue
  waitList.pop()

  //add to active reservations list
  createReservation(nextReservation);

  cout << "Next waiting reservation now in list." << endl;
}

//restore most recent cancelation
void ReservationManager::undoCancel(){
  //check if stack has items
  if (cancelHistory.em[ty()){
    cout << "Unable to Undo: No cancellations available" << endl;

    return;
  }

  //retrieve most recent  cancelled reservation
  Reservation restored = cancelHistory.top();

  //remove recently cancelled from stack
  cancelHistory.pop();

  //insert cancelled reservation into active reservation
  createReservation(restored);

  cout << "Cancelled reservation has been retrieved, reservation now active." << endl; 
  
}
