// main.cpp
#include "BookingService.h"
#include "Show.h"
#include "Movie.h"
#include <iostream>
using namespace std;

int main() {
    Movie avengers("Avengers: Endgame", 180);
    Show show(avengers, 10); // 10 seats

    BookingService& bookingService = BookingService::getInstance();

    std::cout << "Available Seats:\n";
    for (auto& seat : show.getAvailableSeats()) {
        std::cout << "Seat Number: " << seat->getSeatNumber() << "\n";
    }

    int seatNumber;
    std::string paymentMethod;
    double amount = 250.0; // fixed ticket price

    std::cout << "Enter seat number to book: ";
    std::cin >> seatNumber;
    std::cout << "Enter payment method (credit/upi): ";
    std::cin >> paymentMethod;

    if (bookingService.bookTicket(show, seatNumber, paymentMethod, amount)) {
        std::cout << "Booking Successful!\n";
    } else {
        std::cout << "Booking Failed!\n";
    }

    return 0;
}
