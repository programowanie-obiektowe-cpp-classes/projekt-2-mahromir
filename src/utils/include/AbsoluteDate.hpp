#pragma once

#include <stdio.h>

#include <chrono>
#include <vector>

#include "TimeSystem.hpp"

using Nanoseconds = std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds>;

class AbsoluteDate {
   private:
    TimeSystem time_system;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    double seconds;
    Nanoseconds time_point;

    long double juliadDate;

    void updateJuliaDate();

    struct LeapSecond {
        std::chrono::system_clock::time_point date;
        int total_leap_seconds;
    };

    static const std::vector<LeapSecond> leapSeconds;

    /**
     * @brief Returns amount of leap seconds from given time period
     * @param utc
     */
    int leap_seconds_before(Nanoseconds utc);

    double calculate_jd(int my_year, int my_month, int my_day, int my_hour, int my_minute,
                               double my_seconds);

   public:
    /**
     * @brief AbsoluteDate instance create based on UTC components
     * @param year
     * @param month
     * @param day
     * @param hour
     * @param seconds
     */
    AbsoluteDate(int my_year, int my_month, int my_day, int my_hour, int my_minute,
                 double my_seconds);
    /**
     * @brief AbsoluteDate instance create based on UTC components
     * @param year
     * @param month
     * @param day
     * @param hour
     * @param seconds
     * @param time_system
     */
    AbsoluteDate(int my_year, int my_month, int my_day, int my_hour, int my_minute,
                 double my_seconds, TimeSystem time_system);

    /**
     * @brief AbsoluteDate instance created based on Julian Date of automic international time
     */
    AbsoluteDate(long double jd_tai);

    /**
     * @brief AbsoluteDate instance created based on Julian Date in any given time system
     * @param jd
     * @param time_system
     */
    AbsoluteDate(long double jd, TimeSystem time_system);

    ~AbsoluteDate();

    Nanoseconds utc_to_tai(Nanoseconds utc);
    Nanoseconds tai_to_utc(Nanoseconds tai);
    Nanoseconds utc_to_gps(Nanoseconds utc);
    Nanoseconds gps_to_utc(Nanoseconds gps);
    double to_julian();

    // AbsoluteDate shiftedBy(double& seconds);
    int getYear();
    int getMonth();
    int getDay();
    int getDayOfTheYear();
    int getHour();
    int getMinute();
    double getSeconds();

    long double getJulianDate();

    void assign_datetime_components(Nanoseconds tp);

    std::vector<LeapSecond> getLeapSeconds();

    std::string toString();
};
