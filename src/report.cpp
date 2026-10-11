#include "report.h"
#include "analysis.h"
#include "grid.h"

#include <iostream>
#include <iomanip>

void print_report(const Station* stations, const double* temps, int rows, int cols) {
    std::cout << "=== Weather Station Report ===\n";

    for (int station = 0; station < rows; station++) {
        double average = 0.0;

        if (station_average(temps, rows, cols, station, average)) {
            std::cout << std::left << std::setw(15) << stations[station].name
                      << std::right << std::setw(5) << stations[station].elevation_ft
                      << " ft   avg  "
                      << std::fixed << std::setprecision(2)
                      << average << " F\n";
        }
    }

    int hot_row = 0;
    int hot_col = 0;

    if (find_hottest(temps, rows, cols, hot_row, hot_col)) {
        int index = grid_index(hot_row, hot_col, cols);

        std::cout << "Hottest reading: "
                  << std::fixed << std::setprecision(1)
                  << temps[index] << " F at "
                  << stations[hot_row].name
                  << " (day " << hot_col + 1 << ")\n";
    }
    }
