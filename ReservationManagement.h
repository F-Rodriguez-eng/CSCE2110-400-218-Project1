#ifndef "RESERVATIONMANAGEMENT_H"
#define "RESERVATIONMANAGEMENT_H"

#include "Reservation.h"
#include <queue>
#include <stack>
using namespace std;

//node structure for linked list to store all active reservations
struct ReservationNode{
  Reservation data; //reservation stored in node
  Reservation* next;//ptr to the next node (current -> next)

  //contructor to initialize node with Reservation obj, sets next to nullptr
  ReservationNode(Reservation r) : data(r), next(nullptr) {}
};

//RESERVATION MANAGEMENT
/*
* Stores active reservations using a linked list
* Maintain a waiting list using queue, FIFO
* Maintain cancellation history using stack, also FIFO
* Create, search, view, cancel reservations
* Restore recently cancelled reservation
*/
class ReservationManager{
  private:
    //points to first node in the linked list
    ReservationNode* head;

    //wait list queue, reserve requests placed here, processed FIFO
    queue<Reservation> waitList;
    //stores cancelled reservation, most recent is placed on top of stack and can be restored with undoCancel
    stack<Reservation> cancelHistory;

  public:
    //default constructor
    ReservationManager();
    //destructor
    ~ReservationManager();

    //adds new reservation to active linked list, r is Reservation object to be added
    void createReserv(Reservation r);

    //cancels an existing reservation, cancelled reservation is removed from linkedlist
    bool cancelReserv(int placeholdReservID)//replace with actual rID

    //searches reservation with ID
    Reservation* searchReserv(int placeholdReservID);//same thing

    //displays all active reservations in linked list
    void viewReservations();

    //adds reservation request to wait list queue
    void addToWaitList();

    //processes next reservation in wait list queue
    void processWaitList();

    //restores most recent cancelled reservation from stack
    void undoCancel();

};

#endif



