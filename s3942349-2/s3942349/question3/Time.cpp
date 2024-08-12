#include "Time.h"
#include <exception>
#include <iomanip>

Time::Time():
    hour(0), minute(0), second(0)
{}

Time::Time(unsigned int hour, unsigned int minute, unsigned int second):
                            hour(hour), minute(minute), second(second)
{}

Time::Time(unsigned int nSeconds){
    this->setTime(nSeconds);
}

Time::Time(const Time& other):
                hour(other.hour), minute(other.minute), second(other.second)
{}

Time::Time(Time&& other):
                hour(other.hour), minute(other.minute), second(other.second)
{}

Time::~Time()
{}


unsigned int Time::getHour(){
    return hour;
}
unsigned int Time::getMinute(){
    return minute;
}
unsigned int Time::getSecond(){
    return second;
}
unsigned int Time::getnSeconds() const{
    return hour*MINS_PER_HOUR*SECS_PER_MIN + minute*SECS_PER_MIN + second;
}
void Time::setTime(unsigned int nSeconds){

    second  = nSeconds%(SECS_PER_MIN);
    nSeconds = nSeconds/SECS_PER_MIN;
    minute = nSeconds%(MINS_PER_HOUR);
    hour = nSeconds/MINS_PER_HOUR;
}


void Time::setTime(unsigned int hour, unsigned int minute, unsigned int second){
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

std::ostream& operator<<(std::ostream& os, const Time& t) {
    int nSeconds = t.getnSeconds();
    int second = nSeconds%(SECS_PER_MIN);
    nSeconds = nSeconds/SECS_PER_MIN;
    int minute = nSeconds%(MINS_PER_HOUR);
    int hour = nSeconds/MINS_PER_HOUR;
    os << std::setfill('0') << std::setw(2) << hour << ':' << std::setfill('0') << std::setw(2) << minute << ':' << std::setfill('0') << std::setw(2) << second;
    return os;
}

Time operator-(const Time& t, const Time& t2) {
    int nSeconds = t.getnSeconds();
    int nSeconds2 = t2.getnSeconds();
    nSeconds = nSeconds - nSeconds2;
    Time time = (nSeconds);
    return time;
}

int operator += (const  Time& t, const Time& t2) {
    int nSeconds = t.getnSeconds();
    int nSeconds2 = t2.getnSeconds();
    nSeconds += nSeconds2;
    return nSeconds;
}

bool operator != (const Time& t, const Time& t2) {
    int nSeconds = t.getnSeconds();
    int nSeconds2 = t2.getnSeconds();
    if (nSeconds == nSeconds2)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool operator > (const Time& t, const Time& t2) {
    int nSeconds = t.getnSeconds();
    int nSeconds2 = t2.getnSeconds();
    if (nSeconds > nSeconds2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int operator += (const Time& t, const int& t2) {
    int nSeconds = t.getnSeconds();
    int nSeconds2 = t2;
    return nSeconds + nSeconds2;
}

// Time.operator[](const char& t2) {

// }

// += operators could not get them to work
// [] operator could not get to work too