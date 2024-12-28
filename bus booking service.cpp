#include <iostream>
#include <vector>
using namespace std;

class BusReservationSystem {
private:
    vector<bool> seats;  // vector to store seat booking status (true = booked, false = available)
    int totalSeats;

public:
    BusReservationSystem(int numSeats) {
        totalSeats = numSeats;
        seats.resize(totalSeats, false); // Initially, all seats are available (false)
    }

    // Function to book a seat
    void bookSeat(int seatNumber) {
        if (seatNumber < 1 || seatNumber > totalSeats) {
            cout << "Invalid seat number! Please try again." << endl;
        } else if (seats[seatNumber - 1]) {
            cout << "Seat " << seatNumber << " is already booked!" << endl;
        } else {
            seats[seatNumber - 1] = true;
            cout << "Seat " << seatNumber << " has been successfully booked!" << endl;
        }
    }