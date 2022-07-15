#include <bits/stdc++.h>

using namespace std;

class Car {
protected:
    bool isSedan;
    string seats;
    
public:
    Car(bool isSedan, string seats) {
        this->isSedan = isSedan;
        this->seats = seats;
    }

    bool getIsSedan() {
        return this->isSedan;
    }

    string getSeats() {
        return this->seats;
    }

    virtual string getMileage() = 0;

    void printCar(string name) {
        cout << "A " << name << " is " << (this->getIsSedan() ? "" : "not ")
            <<"Sedan, is " << this->getSeats() << "-seater, and has a mileage of around "
            << getMileage() << ".\n";
    }
};
// Write your code here.

/**
*   WagonR class
**/

/**
*   HondaCity class
**/

/**
*   InnovaCrysta class
**/

class WagonR: public Car{
    int milage{};
public:
    WagonR(int m):Car(false, "4"), milage(m){
    }
    string getMileage(){
        return to_string(milage)+ " kmpl";
    }
};

class HondaCity: public Car{
    int milage{};
public:
    HondaCity(int m):Car(true, "4"), milage(m){
    }
    string getMileage(){
        return to_string(milage)+" kmpl";
    }
};

class InnovaCrysta: public Car{
    int milage{};
public:
    InnovaCrysta(int m):Car(false, "6"), milage(m){
    }
    string getMileage(){
        return to_string(milage)+" kmpl";
    }
};
int main()
{
    int carType, carMileage;
    cin >> carType >> carMileage;
    Car *pointer;
    if(carType == 0){
        WagonR wagonR(carMileage);
        pointer = &wagonR;
        wagonR.printCar("WagonR");
    }
    
    if(carType == 1){
        HondaCity hondaCity(carMileage);
        pointer = &hondaCity;
        hondaCity.printCar("HondaCity");
    }
    
    if(carType == 2){
        InnovaCrysta innovaCrysta(carMileage);
        pointer = &innovaCrysta;
        innovaCrysta.printCar("InnovaCrysta");
    }
}
