#include "AbsoluteDate.hpp"

#include <chrono>
#include <iostream>
#include <vector>

#include "TimeSystem.hpp"

using Nanoseconds = std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds>;

AbsoluteDate::AbsoluteDate(int my_year, int my_month, int my_day, int my_hour, int my_minute,
                           double my_seconds)
    : AbsoluteDate::AbsoluteDate(AbsoluteDate::calculate_jd(
          my_year, my_month, my_day, my_hour, my_minute, my_seconds)) {}

AbsoluteDate::AbsoluteDate(int my_year, int my_month, int my_day, int my_hour, int my_minute,
                           double my_seconds, TimeSystem system)
    : AbsoluteDate::AbsoluteDate(AbsoluteDate::calculate_jd(my_year, my_month, my_day,
                                                                   my_hour, my_minute, my_seconds),
                                 system) {}

AbsoluteDate::AbsoluteDate(long double jd, TimeSystem system)
    : juliadDate(jd), time_system(system) {};

AbsoluteDate::AbsoluteDate(long double jd_tai) : juliadDate(jd_tai), time_system(TimeSystem::UTC) {}

AbsoluteDate::~AbsoluteDate() {};

// TODO: implement automatic reading of the orekit-data/tai-utc.dat file for tai<->utc time
// conversions
const std::vector<AbsoluteDate::LeapSecond> AbsoluteDate::leapSeconds = {
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1972} / std::chrono::July / std::chrono::day{1}},
        11},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1973} / std::chrono::January / std::chrono::day{1}},
        12},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1974} / std::chrono::January / std::chrono::day{1}},
        13},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1975} / std::chrono::January / std::chrono::day{1}},
        14},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1976} / std::chrono::January / std::chrono::day{1}},
        15},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1977} / std::chrono::January / std::chrono::day{1}},
        16},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1978} / std::chrono::January / std::chrono::day{1}},
        17},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1979} / std::chrono::January / std::chrono::day{1}},
        18},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1980} / std::chrono::January / std::chrono::day{1}},
        19},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1981} / std::chrono::July / std::chrono::day{1}},
        20},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1982} / std::chrono::July / std::chrono::day{1}},
        21},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1983} / std::chrono::July / std::chrono::day{1}},
        22},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1985} / std::chrono::July / std::chrono::day{1}},
        23},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1988} / std::chrono::January / std::chrono::day{1}},
        24},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1990} / std::chrono::January / std::chrono::day{1}},
        25},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1991} / std::chrono::January / std::chrono::day{1}},
        26},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1992} / std::chrono::July / std::chrono::day{1}},
        27},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1993} / std::chrono::July / std::chrono::day{1}},
        28},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1994} / std::chrono::July / std::chrono::day{1}},
        29},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1996} / std::chrono::January / std::chrono::day{1}},
        30},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1997} / std::chrono::July / std::chrono::day{1}},
        31},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{1999} / std::chrono::January / std::chrono::day{1}},
        32},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{2006} / std::chrono::January / std::chrono::day{1}},
        33},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{2009} / std::chrono::January / std::chrono::day{1}},
        34},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{2012} / std::chrono::July / std::chrono::day{1}},
        35},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{2015} / std::chrono::July / std::chrono::day{1}},
        36},
    AbsoluteDate::LeapSecond{
        std::chrono::sys_days{std::chrono::year{2017} / std::chrono::January / std::chrono::day{1}},
        37}};

int AbsoluteDate::leap_seconds_before(Nanoseconds utc) {
    int leap = 0;
    for (const auto& ls : AbsoluteDate::leapSeconds)
        if (utc >= ls.date)
            leap = ls.total_leap_seconds;
        else
            break;
    return leap;
};

// AbsoluteDate AbsoluteDate::shiftedBy(double& seconds) {
//     return AbsoluteDate();
// }

int AbsoluteDate::getYear() {
    return year;
};
int AbsoluteDate::getMonth() {
    return month;
};
int AbsoluteDate::getDay() {
    return day;
};
int AbsoluteDate::getDayOfTheYear() {
    return 0;
};
int AbsoluteDate::getHour() {
    return hour;
};
int AbsoluteDate::getMinute() {
    return minute;
};
double AbsoluteDate::getSeconds() {
    return seconds;
};
long double AbsoluteDate::getJulianDate() {
    return juliadDate;
};

Nanoseconds AbsoluteDate::utc_to_tai(Nanoseconds utc) {
    int leap = leap_seconds_before(utc);   
    time_system = TimeSystem::TAI;
    return utc - std::chrono::seconds(leap);
};

Nanoseconds AbsoluteDate::tai_to_utc(Nanoseconds tai) {
    // Approximate inverse (fine for most orbit work)
    for (auto it = AbsoluteDate::leapSeconds.rbegin(); it != AbsoluteDate::leapSeconds.rend();
         ++it) {
        if (tai >= it->date + std::chrono::seconds(it->total_leap_seconds))
            return tai + std::chrono::seconds(it->total_leap_seconds);
    }
    return tai;
};

double AbsoluteDate::to_julian() {
    // Based on Algorithm 14 p185 Fundamentals of Astrodynamics and Application. Vallado vol 4

    double jd, jdFrac;

    jd = 367.0 * year - floor((7 * (year + floor((month + 9) / 12.0))) * 0.25) +
         floor(275 * month / 9.0) + day + 1721013.5;  // use - 678987.0 to go to mjd directly
    jdFrac = (seconds + minute * 60.0 + hour * 3600.0) / 86400.0;

    // check that the day and fractional day are correct
    if (fabs(jdFrac) > 1.0) {
        double dtt = floor(jdFrac);
        jd = jd + dtt;
        jdFrac = jdFrac - dtt;
    }
    return jd + jdFrac;
}

std::vector<AbsoluteDate::LeapSecond> AbsoluteDate::getLeapSeconds() {
    return leapSeconds;
};

Nanoseconds AbsoluteDate::utc_to_gps(Nanoseconds utc) {
    using namespace std::chrono;
    auto gps_epoch = std::chrono::sys_days{1980y / January / 6};
    int leap = leap_seconds_before(utc);
    return utc + std::chrono::seconds(leap - 19);  // GPS ahead of UTC by (leap - 19)
};

Nanoseconds AbsoluteDate::gps_to_utc(Nanoseconds gps) {
    using namespace std::chrono;
    auto gps_epoch = std::chrono::sys_days{1980y / January / 6};
    // iterative correction (since leap seconds change over time)
    for (auto it = AbsoluteDate::leapSeconds.rbegin(); it != AbsoluteDate::leapSeconds.rend();
         ++it) {
        auto utc_guess = gps - std::chrono::seconds(it->total_leap_seconds - 19);
        if (utc_guess >= it->date) return utc_guess;
    }
    return gps;
}

double AbsoluteDate::calculate_jd(int my_year, int my_month, int my_day, int my_hour,
                                         int my_minute, double my_seconds) {
    int second = (int)my_seconds;
    double val = (my_seconds - (double)second);
    double temp = (my_seconds - (double)second) * 1e9;
    int second_fraction_ns = (int)temp;

    // Define components
    std::chrono::year year{my_year};
    std::chrono::month month{static_cast<unsigned int>(my_month)};
    std::chrono::day day{static_cast<unsigned int>(my_day)};
    std::chrono::hours hour{my_hour};
    std::chrono::minutes minute{my_minute};
    std::chrono::seconds second_int{second};
    std::chrono::nanoseconds seconds_frac{second_fraction_ns};

    // Definig sys day
    std::chrono::sys_days date_at_midnight = year / month / day;

    // duration from sumed up hour minutes, seconds and nanoseconds
    auto time_duration = hour + minute + second_int + seconds_frac;

    // timepoint representing utc time passed to contructor
    auto tp = std::chrono::time_point<std::chrono::system_clock>{date_at_midnight} + time_duration;

    assign_datetime_components(tp);

    return AbsoluteDate::to_julian();
}

void AbsoluteDate::assign_datetime_components(Nanoseconds tp) {
    using namespace std::chrono;

    // 1. Split the time_point into a date (days since epoch)
    auto days_since_epoch = floor<days>(tp);
    auto time_of_day_duration = tp - days_since_epoch;

    // 2. Convert the days to a calendar date (year/month/day)
    std::chrono::year_month_day ymd{days_since_epoch};

    // 3. Extract the date components
    AbsoluteDate::year = static_cast<int>(ymd.year());
    AbsoluteDate::month = static_cast<unsigned int>(ymd.month());
    AbsoluteDate::day = static_cast<unsigned int>(ymd.day());

    // 4.   hh_mm_ss handles the breakup into H/M/S and fractional seconds
    hh_mm_ss<Nanoseconds::duration> tod{time_of_day_duration};

    // 5. Extract the time components
    AbsoluteDate::hour = static_cast<int>(tod.hours().count());
    AbsoluteDate::minute = static_cast<int>(tod.minutes().count());

    // 6. Calculate the total seconds as a double, including the fraction
    //    a. Get the integral seconds
    long long integral_seconds = tod.seconds().count();

    //    b. Get the nanosecond fraction (the remainder after removing H, M, and S)
    auto fractional_part = tod.subseconds();

    //    c. Calculate the total double seconds
    AbsoluteDate::seconds =
        (double)integral_seconds + (double)fractional_part.count() / 1000000000.0;
}

std::string AbsoluteDate::toString() {
    return std::format(
        "'AbsoluteDate(time system={} year={} month={} day={} hour={} minute={} seconds={})'",
        TimeSystemToString(time_system), year, month, day, hour, minute, seconds);
}