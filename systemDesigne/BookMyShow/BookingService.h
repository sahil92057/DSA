
// BookingService.h
#pragma once
#include "Show.h"
#include "PaymentFactory.h"
#include <memory>
#include <iostream>
class BookingService {
    private:
       BookingService() {}
    public:
  static BookingService& getInstance() {
        static BookingService instance;
        return instance;
    }
        bool bookTicket(Show& show, int seatNumber, const std::string& paymentMethod, double amount) {
        if (show.bookSeat(seatNumber)) {
            auto payment = PaymentFactory::getPaymentStrategy(paymentMethod);
            return payment->pay(amount);
        }
        std::cout << "Seat already booked or invalid!\n";
        return false;
    }
    BookingService(const BookingService&) = delete;
    BookingService& operator=(const BookingService&) = delete;
};