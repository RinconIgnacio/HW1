#include "station.h"
#include "analysis.h"
#include "report.h"

#include <iostream>
#include <iomanip>
#include <string>

int main() {
    constexpr int station_count = 4;
    constexpr int day_count = 7;

    const Station stations[station_count] = {
        {"Denton", 642.0},
        {"Fort Worth", 653.0},
        {"Waco", 470.0},
        {"Amarillo", 3605.0}
    };

    const double temps[station_count * day_count] = {
        91.2, 93.5, 95.0, 97.8, 96.1, 92.4, 90.3,
        92.0, 94.1, 96.4, 98.6, 97.2, 93.0, 91.5,
        93.4, 95.2, 97.9, 99.3, 98.1, 94.6, 92.8,
        84.5, 86.0, 88.2, 90.7, 89.9, 85.3, 83.6
    };

    print_report(stations, temps, station_count, day_count);

    int above = count_above(temps, station_count, day_count, 95.0);

    std::cout << "Readings above 95.0 F: " << above << "\n";

    std::cout << "Station to look up: ";

    std::string name;
    std::getline(std::cin, name);

    const Station* found = find_station(stations, station_count, name);

    if (found == nullptr) {
        std::cout << "No station named \"" << name << "\".\n";
    } else {
        int station_index = static_cast<int>(found - stations);
        double average = 0.0;

        if (station_average(temps, station_count, day_count,
                            station_index, average)) {
            std::cout << found->name << " averaged "
                      << std::fixed << std::setprecision(1)
                      << average << " F.\n";
        }
    }

    return 0;
}
