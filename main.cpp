
#include <iostream>

using namespace std;

class Vehicle {

public:
    std::string name() { return name_; }
    int number_of_wheels() { return number_of_wheels_; }
    std::string propulsion_type() { return propulsion_type_; }
    double max_speed() { return max_speed_; }

protected:
    Vehicle(const std::string &name, int number_of_wheels,
            const std::string &propulsion_type, double max_speed)
        : name_(name), number_of_wheels_(number_of_wheels),
        propulsion_type_(propulsion_type), max_speed_(max_speed) {}

    std::string name_;
    int number_of_wheels_;
    std::string propulsion_type_;
    double max_speed_;
};

class Bike : public Vehicle {

public:
    Bike() : Vehicle("Bike", 2, "Muscles", 30) {}
};

class Car : public Vehicle {

public:
    Car(const std::string &name, const std::string &propulsion_type,
        double max_speed, bool has_abs)
        : Vehicle(name, 4, propulsion_type, max_speed),
        has_abs_(has_abs) {}

    bool has_abs() { return has_abs_; }

private:
    bool has_abs_;
};

class Tractor : public Vehicle{

public:
    Tractor(const std::string &name,int number_of_wheels,  const std::string &propulsion_type,  int max_speed,  int max_horsepower, bool has_front_loader )
    : Vehicle(name, 4, "diesel engine",max_speed), max_horsepower_(max_horsepower), has_front_loader_(has_front_loader){}

    int max_horsepower () {
        return max_horsepower_; }
    int has_front_loader (){
        return has_front_loader_;}

    private:
    int max_horsepower_;
    bool has_front_loader_;
};

int main()
{
    Car passat("Volkswagen Passat", "Diesel", 200, true);
    std::cout << "Name: " << passat.name() << std::endl;
    std::cout << "Has ABS: " << passat.has_abs() << std::endl;

    Tractor john_deere("John Deere 2403F",4,"Diesel", 100, 450,false);
    std::cout<< "Name: "<< john_deere.name()<<" Nr of wheels: "<<john_deere.number_of_wheels()<<" what propulsion "<<john_deere.propulsion_type()<<std::endl;
    return 0;
}
