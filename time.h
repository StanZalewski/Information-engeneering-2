
#ifndef TIME_H
#define TIME_H




class Time
{
public:
    Time(int hrs = 0,int min = 0,int sec = 1);
    Time operator+(const Time &rhs) const;//Adds time
    Time operator-(const Time &rhs) const;//Subtracts time
    Time operator*(const Time &rhs) const;//Multiplies time
    double time_in_seconds(int hours,int minutes,int seconds) const;//Converts time to seconds
    Time seconds_in_time(double seconds) const;//Converts seconds to time.
    friend std::ostream &operator<<(std::ostream &str, Time &rhs);//prints time.
    friend std::istream &operator>>(std::istream &str, Time &rhs);//inputs time to program by user.


private:
    int hrs_, min_, sec_;
};

#endif // TIME_H
