#pragma once

enum TimeSystem{
    UTC,
    GPS,
    UT,
    UT1,
    UT2,
    TAI
};

inline std::string TimeSystemToString (TimeSystem ts)
{ 
   const std::string nameTT[] = { "UTC", "GPS", "UT", "UT1", "UT2", "TAI" };
   return nameTT[ts];
}