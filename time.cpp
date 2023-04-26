#include <iostream>
#include "time.h"

Time::Time(int hrs, int min,int sec ) : hrs_(hrs),min_(min),sec_(sec){
    sec_=1;
}

std::ostream &operator<<(std::ostream &str, Time &rhs){
    if (rhs.hrs_==0 && rhs.min_==0 && rhs.sec_>=0){
        str<<rhs.sec_<<"s"<<std::endl;
    }
    if (rhs.hrs_==0 && rhs.min_>0){
        str<<rhs.min_<<"m:"<<rhs.sec_<<"s"<<std::endl;
    }
    else{
        str<<rhs.hrs_<<"h:"<<rhs.min_<<"m:"<<rhs.sec_<<"s"<<std::endl;
    }
}

std::istream &operator>>(std::istream &str, Time &rhs){
    std::string time_line;
    str >> time_line;
    std::size_t index_h=time_line.find("h");
    std::size_t index_m=time_line.find("m");
    std::size_t index_s=time_line.find("s");

    if (index_h==-1){
        rhs.hrs_=0;
    }
    else{
        rhs.hrs_=std::stoi(time_line.substr(0,index_h));
    }
    if (index_m==-1){
        rhs.min_=0;
    }
    else{
        if (index_h==-1){
            rhs.min_=std::stoi(time_line.substr(0,index_m-1));
        }
        else{
            rhs.min_=std::stoi(time_line.substr(index_h+2,index_m-1));
        }
    }
    if (index_s==-1){
        rhs.sec_=0;
    }
    else{
        if (index_m==-1){
            if (index_h==-1){
                rhs.sec_=std::stoi(time_line.substr(0,index_s-1));
            }
            else{
                rhs.sec_=std::stoi(time_line.substr(index_h+2,index_s-1));
            }
        }
        else{
            rhs.sec_=std::stoi(time_line.substr(index_m+2,index_s-1));
        }
    }
}

double Time::time_in_seconds(int hours,int minutes,int seconds) const{
    double time_sec=hours*3600+minutes*60+seconds;
    return time_sec;
}

Time Time::seconds_in_time(double seconds) const{
    int added_hrs=static_cast<int>(seconds/3600);
    int added_min=static_cast<int>((seconds-added_hrs*3600)/60);
    int added_sec=static_cast<int>((seconds-added_hrs*3600-added_min*60));
    return Time(added_hrs,added_min,added_sec);
}

Time Time::operator+(const Time &rhs) const{
    double time_combined=time_in_seconds(hrs_,min_,sec_)+time_in_seconds(rhs.hrs_,rhs.min_,rhs.sec_);
    return seconds_in_time(time_combined);
}
Time Time::operator-(const Time &rhs) const{
    double time_combined=time_in_seconds(hrs_,min_,sec_)-time_in_seconds(rhs.hrs_,rhs.min_,rhs.sec_);
    return seconds_in_time(time_combined);
}
Time Time::operator*(const Time &rhs) const{
    double time_combined=time_in_seconds(hrs_,min_,sec_)*time_in_seconds(rhs.hrs_,rhs.min_,rhs.sec_);
    return seconds_in_time(time_combined);
}
