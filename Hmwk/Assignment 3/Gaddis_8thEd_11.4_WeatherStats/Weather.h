/* 
 * Author: Kenzie Vasquez
 * Created on March 22, 2017, 11:47 AM
 * Purpose: Hold weather data.
 */

#ifndef WEATHER_H
#define WEATHER_H

struct Weather {
    unsigned short int SIZE;
    float totRain;
    short hiTemp;
    short lowTemp;
    float avgTemp;
};

#endif /* WEATHER_H */

