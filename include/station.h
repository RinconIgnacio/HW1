#ifndef STATION_H
#define STATION_H

#include <string>

struct Station {
    std::string name;
    double elevation_ft;
};

/**
 * @brief finds a station by its exact name
 * @param stations array of stations
 * @param count number of station
 * @param name name to search for
 * @return pointer to the matching station, or nullptr if not found
 */
const Station* find_station(const Station* stations, int count, const std::string& name);

#endif
