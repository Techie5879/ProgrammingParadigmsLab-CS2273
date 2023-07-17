// Aritra Bandyopadhyay 2021CSB107
// Assignment 4_1
#include <iostream>
using namespace std;

class Vehicle {
private:
    double price;
    string manufacturer;
public:
    // Default constructor
    Vehicle() : price(0), manufacturer("") {}

    // Parametrized constructor
    Vehicle(double price, string manufacturer) : price(price), manufacturer(manufacturer) {}

    // Copy constructor
    Vehicle(const Vehicle& other) : price(other.price), manufacturer(other.manufacturer) {}

    // Assignment operator
    Vehicle& operator=(const Vehicle& other) {
        if (this != &other) {
            price = other.price;
            manufacturer = other.manufacturer;
        }
        return *this;
    }

    // Read data
    void readData() {
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter manufacturer: ";
        cin >> manufacturer;
    }

    // Display data
    void displayData() const {
        cout << "Price: " << price << endl;
        cout << "Manufacturer: " << manufacturer << endl;
    }
};

class Car : public Vehicle {
private:
    string color;
    int numberOfSeats;
    string model;
public:
    // Using initialization lists for constructors
    // Default constructor
    Car() : color(""), numberOfSeats(0), model("") {}

    // Parametrized constructor
    Car(double price, string manufacturer, string color, int numberOfSeats, string model)
        : Vehicle(price, manufacturer), color(color), numberOfSeats(numberOfSeats), model(model) {}

    // Copy constructor
    Car(const Car& other) : Vehicle(other), color(other.color), numberOfSeats(other.numberOfSeats), model(other.model) {}

    // Assignment operator
    Car& operator=(const Car& other) {
        if (this != &other) {
            Vehicle::operator=(other);
            color = other.color;
            numberOfSeats = other.numberOfSeats;
            model = other.model;
        }
        return *this;
    }

    // Read data
    void readData() {
        Vehicle::readData();
        cout << "Enter color: ";
        cin >> color;
        cout << "Enter number of seats: ";
        cin >> numberOfSeats;
        cout << "Enter model: ";
        cin >> model;
    }

    // Display data
    void displayData() const {
        Vehicle::displayData();
        cout << "Color: " << color << endl;
        cout << "Number of seats: " << numberOfSeats << endl;
        cout << "Model: " << model << endl;
    }
};

int main() {
    // Car myCar;
    // myCar.readData();
    // cout << endl;
    // myCar.displayData();

    Car car0;
    Car car1(20000, "Honda", "Red", 5, "Civic");
    Car car2(30000, "Toyota", "Blue", 7, "Highlander");
    cout << endl;
    cout << "Car 0 data:" << endl;
    car0.displayData();
    cout << endl;

    // display the data of both cars
    cout << "Car 1 data:" << endl;
    car1.displayData();
    cout << endl;

    cout << "Car 2 data:" << endl;
    car2.displayData();
    cout << endl;

    // use the assignment operator to copy the data of car1 into car2
    car2 = car1;

    // display the data of both cars again to confirm that car2 now has the same data as car1
    cout << "After assignment operator usage:" << endl;

    cout << "Car 1 data:" << endl;
    car1.displayData();
    cout << endl;

    cout << "Car 2 data:" << endl;
    car2.displayData();
    cout << endl;

    return 0;
}
