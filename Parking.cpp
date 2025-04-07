
#include <iostream>
#include <string>
#include <iomanip>

class ParkedCar {
private:
    std::string make;
    std::string model;
    std::string color;
    std::string licenseNumber;
    int minutesParked;

public:
    ParkedCar(std::string mk, std::string mdl, std::string clr, std::string lic, int mins)
        : make(mk), model(mdl), color(clr), licenseNumber(lic), minutesParked(mins) {}

    std::string getMake() const { return make; }
    std::string getModel() const { return model; }
    std::string getColor() const { return color; }
    std::string getLicenseNumber() const { return licenseNumber; }
    int getMinutesParked() const { return minutesParked; }
};

class ParkingMeter {
private:
    int minutesPurchased;

public:
    ParkingMeter(int mins) : minutesPurchased(mins) {}
    int getMinutesPurchased() const { return minutesPurchased; }
};

class ParkingTicket {
private:
    ParkedCar car;
    std::string officerName;
    std::string officerBadge;
    double fine;

    void calculateFine(int illegalMinutes) {
        int illegalHours = (illegalMinutes + 59) / 60; // Round up to nearest hour
        fine = 25.0; // First hour
        if (illegalHours > 1) {
            fine += (illegalHours - 1) * 10.0; // Additional hours
        }
    }

public:
    ParkingTicket(const ParkedCar& c, std::string name, std::string badge, int illegalMins)
        : car(c), officerName(name), officerBadge(badge) {
        calculateFine(illegalMins);
    }

    void printTicket() const {
        std::cout << "\n=== PARKING TICKET ===\n"
                  << "Vehicle Information:\n"
                  << "Make: " << car.getMake() << "\n"
                  << "Model: " << car.getModel() << "\n"
                  << "Color: " << car.getColor() << "\n"
                  << "License: " << car.getLicenseNumber() << "\n\n"
                  << "Fine Amount: $" << std::fixed << std::setprecision(2) << fine << "\n\n"
                  << "Issuing Officer: " << officerName << "\n"
                  << "Badge Number: " << officerBadge << "\n"
                  << "==================\n";
    }
};

class PoliceOfficer {
private:
    std::string name;
    std::string badgeNumber;

public:
    PoliceOfficer(std::string n, std::string badge)
        : name(n), badgeNumber(badge) {}

    ParkingTicket* patrol(const ParkedCar& car, const ParkingMeter& meter) {
        int illegalMinutes = car.getMinutesParked() - meter.getMinutesPurchased();
        if (illegalMinutes > 0) {
            return new ParkingTicket(car, name, badgeNumber, illegalMinutes);
        }
        return nullptr;
    }
};

// Main function to demonstrate the classes
int main() {
    // Create a parked car that has been parked for 125 minutes
    ParkedCar car("Toyota", "Camry", "Blue", "ABC123", 125);
    
    // Create a parking meter with 60 minutes purchased
    ParkingMeter meter(60);
    
    // Create a police officer
    PoliceOfficer officer("John Smith", "B12345");
    
    // Have the officer patrol and check the car
    ParkingTicket* ticket = officer.patrol(car, meter);
    
    // If a ticket was issued, print it
    if (ticket != nullptr) {
        ticket->printTicket();
        delete ticket;
    } else {
        std::cout << "No parking violation.\n";
    }
    
    return 0;
}
