#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include<memory>
#include <string>
//using namespace std;

class ElectronicDevice{
protected:
    std::string brand;
    std::string model;
public:
    ElectronicDevice(std::string brand,std::string model):brand(brand),model(model) {}
    void display(){
        std::cout<<brand<<" "<<model<<std::endl;
    }
};


class Store{
private:
std::vector<std::unique_ptr<ElectronicDevice>> devices;
public:
void addDevice(std::unique_ptr<ElectronicDevice> device){
    devices.emplace_back(std::move(device));
}
void displayDevices(){
    for(auto& device: devices){
        device->display();
    }
}
};


class Smartwatch: public ElectronicDevice{

protected:
    bool hasGPS;
public:
    Smartwatch(std::string brand,std::string model,bool hasGPS): ElectronicDevice(brand,model), hasGPS(hasGPS){}
    void dispy(){
        if(hasGPS){
            std::cout<<"Smart Watch has GPS";
        }
        else{
            std::cout<<"Smart Watch hasn't GPS";
        }
    }
};

class Smartphone:public ElectronicDevice{
protected:
    int storageCapacity;
public:
    Smartphone(std::string brand,std::string model,int storageCapacity): ElectronicDevice(brand,model), storageCapacity(storageCapacity){}

    void display(){
        std::cout<<storageCapacity<<std::endl;
    }
};

class Laptop :public ElectronicDevice{
protected:
int ramSize;

public:
Laptop(std::string brand,std::string model,int ramSize): ElectronicDevice(brand,model), ramSize(ramSize){}

void display(){
    std::cout<<ramSize<<std::endl;
}

};


class GamingLaptop : public Laptop{
protected:
    std::string gpuModel;
public:
    GamingLaptop(std::string brand,std::string model,int ramSize, std::string gpuModel):Laptop(brand,model,ramSize), gpuModel(gpuModel){}

    void display(){
        std::cout<<gpuModel<<std::endl;
    }
};







int main() {

    return 0;
}







































//class Time {
//public:
//    Time(int hours = 0, int minutes = 0, int seconds = 0) {
//        hours_=hours;
//        minutes_ = minutes;
//        seconds_ = seconds;
//    }

//  friend ostream &operator<<(ostream &str,Time &rhs){
//       if(rhs.hours_==0&&rhs.minutes_==0){
//           str<<rhs.seconds_<<"s"<<endl;
//       }else if(rhs.hours_==0){
//           str<<rhs.minutes_<<"m:"<<rhs.seconds_<<"s"<<endl;
//       }else{
//           str<<rhs.hours_<<"h:"<<rhs.minutes_<<"m:"<<rhs.seconds_<<"s"<<endl;
//       }
//        return str;
//    }
//  Time operator+(const Time &rhs)const{
//      return Time(((hours_+rhs.hours_)*3600)+((minutes_+rhs.minutes_)*60)+seconds_+rhs.seconds_);
//  }
//  Time operator-(const Time &rhs)const{
//      return Time(((hours_-rhs.hours_)*3600)+((minutes_-rhs.minutes_)*60)+(seconds_-rhs.seconds_));
//  }
//  bool operator==(const Time &rhs)const{
//      return (hours_==rhs.hours_&&minutes_==rhs.minutes_&&seconds_==rhs.minutes_);
//  }
//private:
//    int hours_, minutes_,seconds_;
//};

//int main() {
//    Time time1(3, 15, 45);
//    Time time2(1, 50, 30);

//    cout << "Time 1: " << time1 << endl;
//    cout << "Time 2: " << time2 << endl;

//   Time sum = time1 + time2;
//   cout << "Sum: " << sum << endl;

//   Time difference = time1 - time2;
//   cout << "Difference: " << difference << endl;

//   bool areEqual = time1 == time2;
//   cout << "Are equal? " << (areEqual ? "Yes" : "No") << endl;

//   return 0;

//}
