#include <iostream>
#include <vector> // header file for dynamic storage of arrays
#include <algorithm>

using namespace std;

class BusReservationSystem {
private:
    vector<int> seats;
    const int totalSeats;

public:
    BusReservationSystem(int totalSeats) : totalSeats(totalSeats) {
        // Initialize all seats as available
        for (int i = 1; i <= totalSeats; ++i) {
            seats.push_back(i);
        }
    }

    void createSeat(int seatNumber) {
        if (find(seats.begin(), seats.end(), seatNumber) != seats.end()) {
            cout << "Seat " << seatNumber << " is already available.\n";
        } else {
            if (seatNumber > 0 && seatNumber <= totalSeats) {
                seats.push_back(seatNumber);
                sort(seats.begin(), seats.end());
                cout << "Seat " << seatNumber << " created successfully.\n";
            } else {
                cout << "Invalid seat number. It must be between 1 and " << totalSeats << ".\n";
            }
        }
    }

    void deleteSeat(int seatNumber) {
        auto it = find(seats.begin(), seats.end(), seatNumber);
        if (it != seats.end()) {
            seats.erase(it);
            cout << "Seat " << seatNumber << " deleted successfully.\n";
        } else {
            cout << "Seat " << seatNumber << " is not available.\n";
        }
    }

    void viewAvailableSeats() const {
        if (seats.empty()) {
            cout << "No seats are available.\n";
        } else {
            cout << "Available seats: ";
            for (int seat : seats) {
                cout << seat << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int totalSeats;
    cout << "Enter the total number of seats in the bus: ";
    cin >> totalSeats;

    BusReservationSystem bus(totalSeats);
    int choice, seatNumber;

    do {
        cout << "\n--- Bus Reservation System ---\n";
        cout << "1. Create a seat\n";
        cout << "2. Delete a seat\n";
        cout << "3. View available seats\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter seat number to create: ";
            cin >> seatNumber;
            bus.createSeat(seatNumber);
            break;
        case 2:
            cout << "Enter seat number to delete: ";
            cin >> seatNumber;
            bus.deleteSeat(seatNumber);
            break;
        case 3:
            bus.viewAvailableSeats();
            break;
        case 4:
            cout << "Exiting the system.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
