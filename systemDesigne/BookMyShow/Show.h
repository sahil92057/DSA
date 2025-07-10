#pragma once
#include "Movie.h"
#include "Seat.h"
#include <vector>
#include <memory>
using namespace std;

class Show{
    private:
    Movie movie;
    std::vector<std::shared_ptr<Seat>> seats;
public:
    Show(const Movie& movie, int seatCount) : movie(movie) {
        for (int i = 1; i <= seatCount; ++i) {
            seats.push_back(std::make_shared<Seat>(i));
        }
    }

    std::vector<std::shared_ptr<Seat>> getAvailableSeats() {
        std::vector<std::shared_ptr<Seat>> available;
        for (auto& seat : seats) {
            if (!seat->isBooked()) available.push_back(seat);
        }
        return available;
    }

    bool bookSeat(int seatNumber) {
        if (seatNumber < 1 || seatNumber > seats.size()) return false;
        auto seat = seats[seatNumber - 1];
        if (!seat->isBooked()) {
            seat->book();
            return true;
        }
        return false;
    }

    Movie getMovie() const { return movie; }
};