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
// function to view all the seats
     void viewAllSeats() {
        cout << "Bus seats status: " << endl;
        for (int i = 0; i < totalSeats; i++) {
            cout << "Seat " << i + 1 << ": " << (seats[i] ? "Booked" : "Available") << endl;
        }
    }
      void viewRemainingSeats() {
        int remainingSeats = 0;
        for (int i = 0; i < totalSeats; i++) {
            if (!seats[i]) {
                remainingSeats++;
            }
        }
        cout << "Remaining available seats: " << remainingSeats << endl;
    }
     void deleteBooking(int seatNumber) {
        if (seatNumber < 1 || seatNumber > totalSeats) {
            cout << "Invalid seat number! Please try again." << endl;
        } else if (!seats[seatNumber - 1]) {
            cout << "Seat " << seatNumber << " is not booked!" << endl;
        } else {
            seats[seatNumber - 1] = false;
            cout << "Booking for seat " << seatNumber << " has been canceled!" << endl;
        }
    }
};

int main() {
    int totalSeats;
    cout << "Enter total number of seats in the bus: ";
    cin >> totalSeats;

    BusReservationSystem bus(totalSeats);

    int choice, seatNumber;

    while (true) {
        cout << "\n*** Bus Reservation System ***" << endl;
        cout << "1. Book a seat" << endl;
        cout << "2. View all bus seats" << endl;
        cout << "3. View remaining available seats" << endl;
        cout << "4. Delete a seat booking" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter seat number to book: ";
                cin >> seatNumber;
                bus.bookSeat(seatNumber);
                break;
                           case 2:
                bus.viewAllSeats();  // call the function to view all the seat
                break;
            case 3:
                bus.viewRemainingSeats();
                break;
                 case 4:
                cout << "Enter seat number to cancel booking: ";
                cin >> seatNumber;
                bus.deleteBooking(seatNumber);
                break;
                 case 5:
                cout << "Exiting the system." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }